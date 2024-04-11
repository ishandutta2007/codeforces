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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int c, h1, h2, w1, w2;
long long dp[2000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if (w1 < w2) {
		swap(w1, w2);
		swap(h1, h2);
	}
	if (w1 >= 900) {
		long long ans = 0;
		for (int i = 0; i * 1ll * w1 <= c; i++) {
			long long h = i * 1ll * h1 + (c - i * 1ll * w1) / w2 * h2;
			ans = max(ans, h);
		}
		cout << ans << endl;
		return 0;
	}
	int g = w1 * w2;
	dp[0] = 0;
	for (int i = 0; i < g * 2; i++) {
		if (i + w1 <= g * 2) dp[i + w1] = max(dp[i + w1], dp[i] + h1);
		if (i + w2 <= g * 2) dp[i + w2] = max(dp[i + w2], dp[i] + h2);
	}
	long long ans;
	if (c <= 2 * g) {
		ans = dp[c];
	} else {
		ans = (c / g - 1) * 1ll * dp[g] + dp[c % g + g];
	}

	cout << ans << endl;

	return 0;
}