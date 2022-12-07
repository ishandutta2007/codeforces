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
#define M 1000000007
#define N 2000222

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, q;
int a[N];
long long s[N];
pair<int, long long> dp[N];
long long b;
int u[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

	while (q--) {
		cin >> b;
		int g = n;
		for (int i = n - 1; i >= 0; i--) {
			while (s[g] - s[i] > b) g--;
			u[i] = g;
		}		

		for (int i = 0; i <= n; i++) dp[i] = mp((int)1e9, 0);

		for (int i = 0; i < n; i++) if (s[i + 1] <= b) dp[i + 1] = mp(1, s[i + 1]);
		dp[0] = mp(1, 0);

		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			if (s[n] - s[i] + dp[i].S <= b) ans = min(ans, dp[i].F);

			int g = u[i];
			if (g == n) ans = min(ans, dp[i].F + 1);

			dp[g] = min(dp[g], mp(dp[i].F + 1, dp[i].S));	
		}
		ans = min(ans, dp[n].F);
		cout << ans << endl;
	}
	return 0;
}