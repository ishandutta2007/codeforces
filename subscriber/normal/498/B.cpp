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

int n, T;
int p[5555], o[5555];

double dp[5055];
double add[5055][5055];

double mem[111][5055];

/*void addnew(int t, int i, double v) {
	dp[t][i] += v;
	if (i == n) return;
	if (t + o[i] <= T) {
		dp[t + o[i]][i] -= v * mem[p[i]][o[i]];
		dp[t + o[i]][i + 1] += v * mem[p[i]][o[i]];
	}
}*/

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> T;
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i], &o[i]);

	for (int s = 0; s <= 100; s++) {
		mem[s][1] = (100 - s) / 100.;
		for (int i = 2; i <= T + 5; i++) {
			mem[s][i] = mem[s][i - 1] * (100 - s) / 100.;
		}
	}
	
	double ans = 0;
	add[0][0] += 1;
	for (int i = 0; i <= n; i++) {
		for (int t = 0; t <= T; t++) dp[t] = 0;
	
		for (int t = 0; t <= T; t++) {
			dp[t] += add[t][i];
			if (t == T) continue;

			if (i == n) {
				dp[t + 1] += dp[t];
				continue;
			}

			if (t + o[i] <= T) {
				dp[t + o[i]] -= add[t][i] * mem[p[i]][o[i]];
		
				add[t + o[i]][i + 1] += add[t][i] * mem[p[i]][o[i]];
			}
		
			add[t + 1][i + 1] += dp[t] * p[i] / 100.;
		
			dp[t + 1] += dp[t] * (100 - p[i]) / 100.;
		}
		ans += dp[T] * i;			
	
	}
	printf("%.10lf\n", ans);
	return 0;
}