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

long long s, x;
long long dp[57][2];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> s >> x;

	dp[0][0] = 1;

	for (int i = 0; i < 55; i++) for (int j = 0; j < 2; j++) if (dp[i][j]) {
		for (int a = 0; a < 2; a++) {
			int b = a;
			if (x & pw(i)) b ^= 1;
			int sum = a + b + j;

			int ins = 0;
			if (s & pw(i)) ins = 1;

			if (sum % 2 != ins) continue;

			dp[i + 1][sum / 2] += dp[i][j];
		}
	}
	long long ans = dp[55][0];
	if (s == x) ans -= 2;
	cout << ans << endl;
	return 0;
}