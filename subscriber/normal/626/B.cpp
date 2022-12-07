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


int dp[202][202][202];

int n;
string s;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;

	int A = 0, B = 0, C = 0;
	for (int i = 0; i < n; i++) if (s[i] == 'R') A++; else if (s[i] == 'B') B++; else C++;

	dp[A + B + C][A][B] = 1;

	for (int sum = n; sum > 1; sum--) for (int i = 0; i <= sum; i++) for (int j = 0; j <= sum; j++)
		if (dp[sum][i][j]) {
			int k = sum - i - j;

			if (i > 0 && j > 0) dp[sum - 1][i - 1][j - 1] = 1;
			if (i > 0 && k > 0) dp[sum - 1][i - 1][j + 1] = 1;
			if (k > 0 && j > 0) dp[sum - 1][i + 1][j - 1] = 1;

			if (i > 1) dp[sum - 1][i - 1][j] = 1;
			if (j > 1) dp[sum - 1][i][j - 1] = 1;
			if (k > 1) dp[sum - 1][i][j] = 1;
	
		}
	string ans = "";		
	if (dp[1][0][1]) ans += 'B';
	if (dp[1][0][0]) ans += 'G';
	if (dp[1][1][0]) ans += 'R';
	cout << ans <<endl;
			

	return 0;
}