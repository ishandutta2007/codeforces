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

int n, m;
long long b;
long long dp[3000333], dp2[3000333];
long long s[111], k[111];
int mask[111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		int t;
		mask[i] = 0;
		cin >> s[i] >> k[i] >> t;
		for (int j = 0; j < t; j++) {
			int x;
			cin >> x;
			mask[i] |= pw(x - 1);
		}
	}
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (k[j] < k[i]) {
		swap(k[i], k[j]);
		swap(s[i], s[j]);
		swap(mask[i], mask[j]);
	}
	long long ans = 4e18;
	for (int j = 0; j < pw(m); j++) dp[j] = 4e18;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < pw(m); j++) dp2[j] = 4e18;
		for (int j = 0; j < pw(m); j++) {
			dp2[j] = min(dp2[j], dp[j]);
			dp2[j | mask[i]] = min(dp2[j | mask[i]], dp[j] + s[i]);
		}
		for (int j = 0; j < pw(m); j++) dp[j] = dp2[j];
		ans = min(ans, k[i] * 1ll * b + dp[pw(m) - 1]);
	}
	if (ans == 4e18) ans = -1;                                  
	cout << ans << endl;
	return 0;
}