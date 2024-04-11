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

int n, m;
char s[N];

long long dp[N][17];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d %d\n", &n, &m);
	gets(s);

	dp[0][pw(0)] = 1;

	for (int i = 0; i < n; i++) for (int j = 0; j < pw(4); j++) if (dp[i][j]) {
		for (int c = 0; c < m; c++) {
			int can = 0;
			if (c == s[i] - 'a' && (j & pw(0))) can |= pw(0);

			if (i + 1 < n && c == s[i + 1] - 'a' && ((j & pw(1)) || (j & pw(0)))) can |= pw(1);

			if (i > 0 && c == s[i - 1] - 'a' && (j & pw(2))) can |= pw(2);
			if (j & pw(0)) can |= pw(2);

			if (c == s[i] - 'a' && (j & pw(3))) can |= pw(3);
			if (j & pw(0)) can |= pw(3);
			if (j & pw(1)) can |= pw(3);
			if (i > 0 && c == s[i - 1] - 'a' && (j & pw(2))) can |= pw(3);

			dp[i + 1][can] += dp[i][j];
		}
	}
	long long ans = 0;
	for (int i = 1; i < pw(4); i++) if ((i & pw(0)) == 0 && (i & pw(3))) ans += dp[n][i];
	cout << ans << endl;
	return 0;
}