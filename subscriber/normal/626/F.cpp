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

int n, k;
int a[555];

int dp[202][202][1011];


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	a[n] = 500;
	
	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++) for (int b = 0; b <= i; b++) for (int s = 0; s <= k; s++) if (dp[i][b][s]) {
		for (int g = -1; g <= 1; g++) {
			if (b + g < 0) continue;

			int cc = 1;
			if (g != 1) cc = b;
			if (g == 0) cc++;

			int v = s + (b + g) * (a[i + 1] - a[i]);

			if (v > k) continue;
			dp[i + 1][b + g][v] = (dp[i + 1][b + g][v] + dp[i][b][s] * 1ll * cc) % M;
		}

	}

	int ans = 0;
	for (int l = 0; l <= k; l++) ans = (ans + dp[n][0][l]) % M;
	cout << ans << endl;

	return 0;
}