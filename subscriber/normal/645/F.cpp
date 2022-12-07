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

int n, k, q;

int cnt[2000222];
int dp[2000222];

int fu[200222], inv[200222];

int was[2000222];
int T;

vector<int> pd[1000111];

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int C(int n, int k) {
	if (k > n) return 0;
	return fu[n] * 1ll * inv[k] % M * inv[n - k] % M;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	fu[0] = 1;
	for (int i = 1; i <= 200110; i++) fu[i] = fu[i - 1] * 1ll * i % M;
	for (int i = 0; i <= 200110; i++) inv[i] = pv(fu[i], M - 2);

	for (int i = 1; i <= 1000000; i++) for (int j = i + i; j <= 1000000; j+= i) pd[j].pb(i);
/*	
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 1; j * j <= i; j++) if (i % j == 0) {
			pd[i].pb(j);
			if (j > 1 && j * j != i) pd[i].pb(i / j);
		}
	}*/

	cin >> n >> k >> q;

	int ans = 0;
	
	for (int i = 0; i < n + q; i++) {
	        int x;
	        scanf("%d", &x);

	        vector<int> d = pd[x];
	        d.pb(x);

	        for (int j = 0; j < d.size(); j++) dp[d[j]] = 0;


	        for (int j = d.size() - 1; j >= 0; j--) {
	        	int cn = cnt[d[j]];

	        	int y = d[j];

	        	dp[y] = (dp[y] + C(cn, k - 1)) % M;


	        	for (int k = 0; k < pd[y].size(); k++) {
				dp[pd[y][k]] -= dp[y];
				if (dp[pd[y][k]] < 0) dp[pd[y][k]] += M;	        		
	        	}
	        }

	        for (int j = 0; j < d.size(); j++) ans = (ans + dp[d[j]] * 1ll * d[j]) % M;

	        for (int j = 0; j < d.size(); j++) cnt[d[j]]++;

	        if (i >= n) printf("%d\n", ans);
		
	}

	return 0;
}