#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
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
typedef pair<int,int> pt;

int dp[2222][2];
int X, Y, n;
int x[2222], y[2222];

int inv[N], fu[N];

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int C(int n, int k) {
	return fu[n] * 1ll * inv[k] % M * inv[n - k] % M;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> X >> Y >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	fu[0] = 1;
	for (int i = 1; i <= X + Y; i++) fu[i] = fu[i - 1] * 1ll * i % M;
	for (int i = 0; i <= X + Y; i++) inv[i] = pv(fu[i], M - 2);

	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (x[i] + y[i] > x[j] + y[j]) {
		swap(x[i], x[j]);
		swap(y[i], y[j]);
	}
	for (int i = 0; i < n; i++) dp[i][1] = C(x[i] - 1 + y[i] - 1,x[i] - 1);
	for (int i = 0; i < n; i++) for (int o = 0; o < 2; o++) for (int j = i + 1; j < n; j++) {
		if (x[j] < x[i] || y[j] < y[i]) continue;
		dp[j][o ^ 1] = (dp[j][o ^ 1] + dp[i][o] * 1ll * C(x[j] - x[i] + y[j] - y[i],x[j] - x[i])) % M;
	}
	int ans = C(X - 1 + Y - 1, X - 1);
	for (int i = 0; i < n; i++) for (int o = 0; o < 2; o++) {
		int t = dp[i][o] * 1ll * C(X - x[i] + Y - y[i], X - x[i]) % M;
		if (o) ans = (ans - t + M) % M; else ans = (ans + t) % M;
	}
	cout << ans << endl;
	return 0;
}