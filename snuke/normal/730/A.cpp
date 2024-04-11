#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = n-1; i >= 0; --i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
#define dame {puts("No"); return 0;}
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1001001001;



int main() {
	df(n);
	vp a(n);
	rep(i,n) cin >> a[i].fi, a[i].fi *= -1, a[i].se = i;
	vs s;
	while (1) {
		sort(rng(a));
		if (a[0].fi == a.back().fi) break;
		if (n >= 3 && a[0].fi == a[1].fi && a[0].fi == a[2].fi) {
			if (a[3].fi == a[0].fi+1 && a.back().fi == a[0].fi+1) {
				string t(n,'0');
				t[a[0].se] = t[a[1].se] = t[a[2].se] = '1';
				a[0].fi++; a[1].fi++; a[2].fi++;
				s.pb(t);
				continue;
			}
		}
		string t(n,'0');
		t[a[0].se] = t[a[1].se] = '1';
		s.pb(t);
		a[0].fi++;
		if (a[1].fi) a[1].fi++;
	}
	cout << -a[0].fi << endl;
	cout << sz(s) << endl;
	rep(i,sz(s)) cout << s[i] << endl;
	return 0;
}