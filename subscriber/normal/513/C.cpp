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

int n;
int l[55], r[55];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

	long double ans = 0;
	for (int x = 1; x <= 10000; x++) {
		long double v = 0;

		for (int i = 0; i < n; i++) if (r[i] > x) {
			long double t = (r[i] - max(x, l[i] - 1)) / 1. / (r[i] - l[i] + 1);

			long double dp[n + 1][2];
			for (int ii = 0; ii <= n; ii++) for (int j = 0; j < 2; j++) dp[ii][j] = 0;
			dp[0][0] = 1;

			for (int ii = 0; ii < n; ii++) for (int j = 0; j < 2; j++) {
				if (ii == i) {
					dp[ii + 1][j] += dp[ii][j];
					continue;
				}
				long double g = 0;
				if (l[ii] <= x && x <= r[ii]) g = 1. / (r[ii] - l[ii] + 1);

				dp[ii + 1][j | 1] += dp[ii][j] * g;
				if (x > l[ii])
					dp[ii + 1][j] += dp[ii][j] * (min(x - 1, r[ii]) - l[ii] + 1) / 1. / (r[ii] - l[ii] + 1);
			}
			v += dp[n][1] * t;
		}
		{
			long double dp[n + 1][3];
			for (int ii = 0; ii <= n; ii++) for (int j = 0; j < 3; j++) dp[ii][j] = 0;
			dp[0][0] = 1;
			for (int ii = 0; ii < n; ii++) for (int j = 0; j < 3; j++) {
				long double g = 0;

				if (l[ii] <= x && x <= r[ii]) g = 1. / (r[ii] - l[ii] + 1);

				dp[ii + 1][min(j + 1, 2)] += dp[ii][j] * g;

				if (x > l[ii])
					dp[ii + 1][j] += dp[ii][j] * (min(x - 1, r[ii]) - l[ii] + 1) / 1. / (r[ii] - l[ii] + 1);
			}
			v += dp[n][2];
		}
//		cout << v << endl;		
		ans += v * x;
	}
	printf("%.15lf\n", (double) ans);
	return 0;
}