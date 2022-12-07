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

int n, q;
string a[55];
char b[55];

long long dp[55][55];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> q;

	for (int i = 0; i < q; i++) cin >> a[i] >> b[i];

	dp[1][0] = 1;

	for (int i = 1; i < n; i++) for (int j = 0;j < 26; j++) for (int k = 0; k < q; k++) if (b[k] - 'a' == j)
		dp[i + 1][a[k][0] - 'a'] += dp[i][j];

	long long ans = 0;
	for (int i = 0; i < 26; i++) ans += dp[n][i];

	cout <<ans <<endl;	

	return 0;
}