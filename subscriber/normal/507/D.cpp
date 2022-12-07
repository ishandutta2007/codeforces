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
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k, m;

int dp[1111][111][2];

int st[1111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k >> m;

	dp[0][0][0] = 1;

	st[0] = 1;
	for (int i = 1; i <= n; i++) st[i] = (st[i - 1] * 10) % k;

	int ans = 0;

	for (int i = 0; i< n; i++) for (int j = 0; j < k; j++) for (int o = 0; o < 2; o++) {
		for (int d = 0; d < 10; d++) {
			int oo = o;
			int z = (j + d * st[i]) % k;
			if (z == 0 && d != 0) oo = 1;

			dp[i + 1][z][oo] = (dp[i + 1][z][oo] + dp[i][j][o]) % m;	

			if (i == n - 1 && d != 0 && oo == 1) {
				ans = (ans + dp[i][j][o]) % m;
			}
		}
	}
	cout << ans << endl;
	return 0;
}