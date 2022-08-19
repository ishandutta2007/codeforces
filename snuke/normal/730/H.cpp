#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
#define dame {puts("No"); return 0;}
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;

int main() {
	df(n); df(m);
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	string t;
	rep(i,m) {
		df(a);
		--a;
		if (!i) t = s[a];
		else {
			if (sz(t) != sz(s[a])) dame;
			rep(j,sz(t)) {
				if (t[j] == '?') continue;
				if (t[j] != s[a][j]) t[j] = '?';
			}
		}
		s[a] = "";
	}
	rep(i,n) {
		if (sz(t) != sz(s[i])) continue;
		bool ok = false;
		rep(j,sz(t)) {
			if (t[j] == '?') continue;
			if (t[j] != s[i][j]) ok = true;
		}
		if (!ok) dame;
	}
	puts("Yes");
	cout << t << endl;
	return 0;
}