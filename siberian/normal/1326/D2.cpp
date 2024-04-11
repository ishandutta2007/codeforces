#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string s;
int n;

void read() {
	cin >> s;
	n = s.size();
}

int ans_pref;
int ansL, ansR;

string fans;

void make_ans() {
	fans = "";
	for (int i = 0; i < ans_pref; i++)
		fans += s[i];
	for (int i = 0; i < ansL; i++)
		fans += s[i + ans_pref];
	int n = s.size();
	for (int i = 0; i < ansR; i++)
		fans += s[n - ans_pref - ansR + i];
	for (int i = 0; i < ans_pref; i++)
		fans += s[n - ans_pref + i];
}

vector<int> mxL, mxR;

vector<int> make_d1() {
	int n = s.size();
	vector<int> d1 (n);
	int l=0, r=-1;
	for (int i=0; i<n; ++i) {
		int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
	  	while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
	  	d1[i] = k;
	  	if (i+k-1 > r)
	    	l = i-k+1,  r = i+k-1;
	}
	return d1;
}

vector<int> make_d2() {
	int n = s.size();
	vector<int> d2 (n);
	int l = 0, r = -1;
	for (int i=0; i<n; ++i) {
  		int k = i > r ? 0 : min (d2[l+r-i+1], r-i+1);
  		while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
  		d2[i] = k;
  		if (i+k-1 > r)
    	l = i-k,  r = i+k-1;
	}
	return d2;
}

vector<int> d1, d2;

void build() {
	d1 = make_d1();
	d2 = make_d2();

	/*mxL.assign(n, 0);
	for (int i = 0; i < n; i++) {
		chkmax(mxL[i - d1[i] + 1], d1[i] * 2 - 1);
		chkmax(mxL[i - d2[i]], d2[i] * 2);
	}
	for (int i = 1; i < n; i++) {
		chkmax(mxL[i], mxL[i - 1] - 2);
	}

	mxR.assign(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		chkmax(mxR[i + d[i] - 1], d1[i] * 2 - 1);
		chkmax(mxR[i + d2[i] - 1], d2[i] * 2);
	}
	for (int i = n - 2; i >= 0; i--) {
		chkmax(mxR[i], mxR[i + 1] - 2);
	}*/
}

void relax(int fans_pref, int fansL, int fansR) {
	if (fans_pref * 2 + fansL + fansR <= 2*ans_pref + ansL + ansR) return;
	ans_pref = fans_pref;
	ansL = fansL;
	ansR = fansR;
}

void run() {
	ans_pref = 0;
	ansL = 0;
	ansR = 0;
	build();
	int mx_pref = 0;

	for (int i = 0; i < n && n - 1 - i > i; i++) {
		if (s[i] != s[n - 1 - i]) break;
		mx_pref++;
	}

	for (int i = 0; i < n; i++) {
		int posL = i - d1[i] + 1;
		int posR = i + d1[i] - 1;
		int len1 = posL;
		int len2 = n - posR - 1;
		if (len1 <= len2) {
			if (mx_pref < len1) continue;
			relax(len1, d1[i] * 2 - 1, 0);
		} else {
			if (mx_pref < len2) continue;
			relax(len2, 0, d1[i] * 2 - 1);
		}
	}

	for (int i = 0; i < n; i++) {
		int posL = i - d2[i];
		int posR = i + d2[i] - 1;
		int len1 = posL;
		int len2 = n - posR - 1;
		if (len1 <= len2) {
			if (mx_pref < len1) continue;
			relax(len1, d2[i] * 2, 0);
		} else {
			if (mx_pref < len2) continue;
			relax(len2, 0, d2[i] * 2);
		}
	}

	make_ans();
}

void write() {
	cout << fans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {	
		read();
		run();
		write();
	}
	return 0;
}