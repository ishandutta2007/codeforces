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

int n, a, b, k;
int dp[5005], dp2[5005];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> a >> b >> k;
	a--;
	b--;
	dp[a] = 1;
	for (int ii = 0; ii < k; ii++) {
		for (int j = 0; j <= n; j++) dp2[j] = 0;

		for (int i = 0; i < n; i++) {
			int t = abs(i - b) - 1;

			int l = max(i - t, 0);
			int r = min(i + t, n - 1);

			dp2[l] += dp[i];
			if (dp2[l] >= M) dp2[l] -= M;

			dp2[r + 1] -= dp[i];
			if (dp2[r + 1] < 0) dp2[r + 1] += M;
		}

		int s = 0;
		for (int i = 0; i < n; i++) {
			s += dp2[i];
			if (s >= M) s-= M;
			dp[i] = s - dp[i];
			if (dp[i] < 0) dp[i] += M;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans = (ans + dp[i]) % M;
	cout << ans << endl;
	return 0;
}