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
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int dp[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	int n, k;
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1];
		if (i - k >= 0)
		dp[i] = (dp[i] + dp[i - k]) % M;
	}
	for (int i = 1; i < N; i++) dp[i] = (dp[i] + dp[i - 1]) % M;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = dp[y] - dp[x - 1];
		if (ans < 0) ans += M;
		printf("%d\n", ans);
	}
	return 0;
}