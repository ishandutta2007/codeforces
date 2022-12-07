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
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int al, n;
int dp[2222][2222];
vector<int> v[2222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> al >> n;
	for (int i = 1; i <= al; i++) for (int j = 1; j <= al; j++) if (i % j == 0) v[i].pb(j);
	for (int i = 1; i <= al; i++) dp[1][i] = 1;
	for (int i = 1; i < n; i++) for (int j = 1; j <= al; j++) if (dp[i][j])
	for (int k = 0; k < v[j].size(); k++) {
		dp[i + 1][v[j][k]] += dp[i][j];
		if (dp[i + 1][v[j][k]] >= M) dp[i + 1][v[j][k]] -= M;
	}
	int ans = 0;
	for (int i = 1; i <= al; i++) ans = (ans + dp[n][i]) % M;
	cout << ans <<endl;
	return 0;
}