#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

int u;
int e[N], A, B, a, b, n;

int can(int A, int B, int a, int b, int x) {
	if (A <= a && B <= b) return 1;
	if (x == u) return 0;

	int cnt = 0;
	for (int i = x; i < u; i++) if (e[i] == e[x]) cnt++; else break;

	for (int i = 0; i <= cnt; i++) {
		if (a >= A && i > 0) continue;
		if (b >= B && i < cnt) continue;

		int aa = a;
		int bb = b;
		for (int j = 0; j < i; j++) if (aa * 1ll * e[x] >= A) aa = A; else aa *= e[x];
		for (int j = 0; j < cnt - i; j++) if (bb * 1ll * e[x] >= B) bb = B; else bb *= e[x];

		if (can(A, B, aa, bb, x + cnt)) return 1;
	}                                                
	return 0;
}

int solve(int A, int B, int a, int b) {
	for (u = 0; u <= n; u++) {
		if (can(A, B, a, b, 0)) return u;
	}
	return 1e9  + 1;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> A >> B >> a >> b >> n;
	for (int i = 0; i < n; i++) cin >> e[i];
	sort(e, e + n);
	reverse(e, e + n);
	n = min(n, 40);

	int ans = min(solve(A, B, a, b), solve(A, B, b, a));
	if (ans > 1e9) ans = -1;
	cout << ans << endl;
	return 0;
}