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
#define N 322000

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k;
int a[N];
int dp[5055][5055];

long long su[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);

	int sz = n / k;

	int B = n % k;
	int A = k - B;

	for (int i = 0; i <= A; i++) for (int j = 0; j <= B; j++) dp[i][j] = 2e9 + 1;
	dp[0][0] = 0;

	su[0] = 0;
	for (int i = 1; i < n; i++) su[i] = su[i - 1] + a[i] - a[i - 1];

	for (int i = 0; i <= A; i++) for (int j = 0; j <= B; j++) {
		int x = (i + j) * sz + j;

		if (i < A) {
			long long t = dp[i][j] + su[x + sz - 1] - su[x];
			dp[i + 1][j] = min(dp[i + 1][j] * 1ll, t);
		} 
		if (j < B) {
			long long t = dp[i][j] + su[x + sz] - su[x];
			dp[i][j + 1] = min(dp[i][j + 1] * 1ll, t);
		}
	}
	cout << dp[A][B] << endl;
	return 0;
}