#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

namespace suffix_array {
	template<class T>
	void induce(int n, const T s[], bool isL[], int sa[], int l_head[], int B)
	{
		int buf[B+2];
		copy_n(l_head, B+2, buf);

		for (int i = 0; i < n; ++i) {
			if (sa[i] > 0 && isL[sa[i]-1]) {
				int pos = (int)s[sa[i]-1];
				sa[buf[pos]++] = sa[i]-1;
			} 
		}

		copy_n(l_head, B+2, buf);

		for (int i = n - 1; i >= 0; --i) {
			if (sa[i] > 0 && !isL[sa[i]-1]) {
				int pos = (int)s[sa[i]-1];
				sa[--buf[pos+1]] = sa[i]-1;
			}
		}	
	}

	//sentinel must be added to the end of s in advance

	template<class T>
	void SA_IS(int n, const T s[], int sa[], int B = 200)
	{
		bool isL[n];

		isL[n - 1] = false;

		for (int i = n - 2; i >= 0; --i) { 
			isL[i] = (s[i] > s[i+1] || (s[i] == s[i+1] && isL[i+1]));
		}

		int l_head[B+2] = {0};

		for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];

		int sum = 0;

		for (int i = 0; i <= B+1; ++i) {
			l_head[i] += sum;
			swap(sum, l_head[i]);
		}

		vector<int> lms;
		int lms_id[n];

		fill_n(lms_id, n, -1);

		int buf[B+2];
		copy_n(l_head, B+2, buf);	

		int now = 0;

		fill_n(sa, n, -1);

		for (int i = 1; i < n; ++i) {
			if (isL[i-1] && !isL[i]) {
				lms_id[i] = now++;
				lms.push_back(i);
				sa[--buf[(int)s[i]+1]] = i;
			}
		}

		vector<int> lms2 = lms;
		induce(n, s, isL, sa, l_head, B);

		now = 0;
		
		for (int i = 0; i < n; ++i) {
			if (lms_id[sa[i]] != -1) {
				lms[now++] = sa[i];
			}
		}

		int s_lms[now], sa_lms[now+1];

		now = 0;
		s_lms[lms_id[lms[0]]] = 0;
		
		for (int i = 1; i < lms.size(); ++i) {
			int u = lms[i-1], v = lms[i];

			bool diff = false;

			for (int j = 0; j < n; ++j) {
				if (s[u+j] != s[v+j] || isL[u+j] != isL[v+j]) {
					diff = true;
					break;
				}

				if (j > 0 && (lms_id[u+j] != -1 || lms_id[v+j] != -1)) break;
			}
			
			if (diff) now++;
			s_lms[lms_id[lms[i]]] = now;
		}

		if (now+1 != lms.size()) {
			SA_IS(lms.size(), s_lms, sa_lms, now);
		} else {
			for (int i = 0; i < lms.size(); ++i) {
				sa_lms[s_lms[i]] = i;
			}
		}

		for (int i = 0; i < lms.size(); ++i) {
			lms[i] = lms2[sa_lms[i]];
		}

		copy_n(l_head, B+2, buf);

		fill_n(sa, n, -1);

		for (int i = (int)lms.size()-1; i >= 0; --i) {
			int p = s[lms[i]];
			sa[--buf[p+1]] = lms[i];
		}

		induce(n, s, isL, sa, l_head, B);
	}

	template <class T>
	void LCP(int n, const T s[], const int sa[], int lcp[]) {
		int rsa[n+1];
		for (int i = 0; i <= n; i++) {
			rsa[sa[i]] = i;
		}

		int h = 0;
		for (int i = 0; i < n; i++) {
			int j = sa[rsa[i]-1];

			if (h > 0) h--;
			for (; j+h < n && i+h < n; h++) {
				if (s[j+h] != s[i+h]) break;
			}
			lcp[rsa[i]-1] = h;
		}
	}
};

int n;
char c[500010];
int h[1000010];
int sa[500010];
int lcp[500010];
vector<int> vp[1000010];

int main() {
	scanf("%d%s", &n, c);

	int u = 500000;
	h[0] = u;

	rep(i, n) {
		if (c[i] == '(') ++u;
		else --u;
		h[i+1] = u;
	}

	for (int i = 0; i <= n; ++i) {
		vp[h[i]].pb(i);
	}

	suffix_array::SA_IS(n + 1, c, sa);
	suffix_array::LCP(n, c, sa, lcp);

	ll ret = 0;

	for (int i = 1; i <= n; ++i) {
		int cm = lcp[i-1];
		int lb = sa[i] + cm;
		int hi = h[sa[i]];

		auto it = lower_bound(ALL(vp[hi-1]), sa[i]);
		
		int ub = it == vp[hi-1].end() ? n+1 : *it;
		//cout << "pos= " << sa[i] << " " << lb << " " << ub << endl;

		if (lb < ub) {
			int t = lower_bound(ALL(vp[hi]), ub) - upper_bound(ALL(vp[hi]), lb);
			ret += t; 
			//cout << t << endl;
		}
	}

	printf("%I64d\n", ret);

	//cout << ret << endl;
	return 0;
}