#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

const int NN = 200011;
char s[NN], t[NN];
VI pos[2];
vector<pii> ans;

#define sz(a) ((int)a.size())

int n;
int solve() {
	for(int i=0; i<n; i++) {
		if(s[i] != t[i]) pos[s[i]-'a'].pb(i);
	}
	if(sz(pos[0]) + sz(pos[1]) & 1) return puts("-1");
	for(int i=0; i<sz(pos[0])-1; i+=2) {
		ans.pb({pos[0][i], pos[0][i+1]});
	}
	for(int i=0; i<sz(pos[1])-1; i+=2) {
		ans.pb({pos[1][i], pos[1][i+1]});
	}
	if(sz(pos[0]) & 1) {
		ans.pb({pos[0].back(), pos[0].back()});
		ans.pb({pos[0].back(), pos[1].back()});
	}
	cout << sz(ans) << endl;
	for(auto p : ans) {
		printf("%d %d\n", p.x+1, p.y+1);
	}
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin >> n;
	scanf("%s %s", s, t);
	solve();
	return 0;
}