#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<cstring>
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
#define N 2111111
using namespace std;
typedef pair<int,int> pt;

int n;
char a[N];
long long dp[N][3];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	gets(a);
	n = strlen(a);
	for (int i = 0; i < n; i++) {
		if (a[i] == '_' || a[i] >= 'a' && a[i] <= 'z' || a[i] >= '0' && a[i] <= '9') dp[i + 1][0] += dp[i][0];
		if (a[i] == '@' && i + 1 < n) {
			if (a[i + 1] >= 'a' && a[i + 1] <= 'z' || a[i + 1] >= '0' && a[i + 1] <= '9') dp[i + 2][1] += dp[i][0];
		}
		if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= '0' && a[i] <= '9') dp[i + 1][1] += dp[i][1];
		if (a[i] == '.' && i + 1 < n) {
			if (a[i + 1] >= 'a' && a[i + 1] <= 'z') dp[i + 2][2] += dp[i][1];
		}
		if (a[i] >= 'a' && a[i] <= 'z') dp[i + 1][2] += dp[i][2];
		if (a[i] >= 'a' && a[i] <= 'z') dp[i + 1][0] ++;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) ans += dp[i + 1][2];
	cout << ans << endl;
	return 0;
}