#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

using namespace std;
using nagai = long long;

template <typename T>
vector<int> kmp_table(int n, const T &s) {
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}
template <typename T>
vector<int> kmp_table(const T &s) {
  return kmp_table((int) s.size(), s);
}
template <typename T>
vector<int> kmp_search(int n, const T &s, int m, const T &w, const vector<int> &p) {
  assert(n >= 1 && (int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || !(w[i] == s[k]))) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      k++;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  return res;
  // returns 0-indexed positions of occurrences of w in s
}
template <typename T>
vector<int> kmp_search(const T &s, const T &w, const vector<int> &p) {
  return kmp_search((int) s.size(), s, (int) w.size(), w, p);
}

template <typename T>
vector<int> z_function(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
template <typename T>
vector<int> z_function(const T &s) {
  return z_function((int) s.size(), s);
}

const int mod=1e9+7;

const int N=100100;
int pref[N][26];

nagai md(nagai& x){
	return x %= mod;
}
nagai md(const nagai& x){
	return x % mod;
}

int mu(int a, int b) {
	 return (nagai) a * b % mod;
}

int pw(int a, int b, int c=1) {
	for(;b;a=mu(a,a),b >>=1)if(b&1)c=mu(a,c);
	return c;
}

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int n, q;
	 cin >> n >> q;
	 string s ,t;
	 cin >> s >> t;
	 const int tt=22;
	 while(t.size() < 25) 
		 t.push_back('#');
	 for(int i=0;i<=n;++i) {
		 for(int j=0;j<26;++j) {
			 pref[i + 1][j] = md(pref[i][j] * 2);
			 if(t[i] == 'a' + j)
				 pref[i+1][j]++;
			 md(pref[i+1][j]);
		 }
	 }
	 int pws[N];
	 pws[0]=1;
	 for(int i=0;i+1<N;++i)
		 pws[i+1]=md(pws[i]*2);
	 while(q--) {
		 int c;
		 cin >> c;
		 string w;
		 cin >> w;
		 string ss=s;
		 int i;
		 for(i=0;i < c && ss.size() < w.size();++i) { 
			 ss.push_back(t[i]);
			 ss += ss;
			 ss.pop_back();
		 }
		 vector<nagai>ans(25);
		 vector<int>kek(26);
		 auto ssw = z_function(ss + w);
		 auto wss = z_function(w + ss);
		 ssw.push_back(0);
		 wss.push_back(0);
		 for(int ii=w.size();ii<wss.size();++ii)
			 if(wss[ii]>=w.size())
				 ++ans[i];
		 for(int j=0;j<w.size();++j) 
			 if (wss[(int)w.size() + (int)ss.size() - j] >= j
					 && ssw[(int)ss.size() + (int)w.size() - (w.size() - j - 1)] >= w.size() - j - 1) {
				 ++kek[w[j]-'a'];
			 }
		 int tt=i;
		 /*
		 for(int j=i+1;j<=tt;++j) {
			 ans[j] = md(2 * ans[j - 1] + kek[t[j-1] - 'a']);
		 }
		 */
		 if (c <= tt) 
			 cout << ans[c] << '\n';
		 else {
			 nagai a = mu(ans[tt], pws[c-tt]);
			 for(int i=0;i<26;++i) {
				 a += mu(kek[i], pref[c][i]);
				 a -= mu(kek[i], mu(pref[tt][i], pws[c-tt]));
				 md(a);
				 if (a < 0) 
					 a += mod;
			 }
			 cout << a << '\n';
		 }
	 }
	 return 0;
}