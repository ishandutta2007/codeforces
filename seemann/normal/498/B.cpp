#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 5e-15;
const int MAXN = 5010;
double dp[MAXN][MAXN];
double p[MAXN];
int t[MAXN];

int main() {
//	freopen("a.in", "r", stdin);
	//freopen("aout", "w", stdout);
	//freopen("", "w", stderr);
	    int n, T;
	    scanf("%d%d", &n, &T);
		for (int i = 0; i < n; i++) {
		    int wp;
	        scanf("%d%d", &wp, &t[i]);
			p[i] = 0.01 * wp;
		}
		
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < T; j++) {
				double prob = dp[i][j];
				if (prob < EPS)
				    continue;
			    bool flag = false;	
				if (p[i] > EPS) {
					for (int k = j + 1; k < j + t[i]; ++k) {
						if (k > T) {
							dp[i][T] += prob;
							flag = true;
							break;
						}
							
						dp[i + 1][k] += prob * p[i];
						prob *= (1 - p[i]);
						if (prob < EPS)
							break;
					}
				}
				if (!flag)
    				if (j + t[i] <= T)
	    				dp[i + 1][j + t[i]] += prob;
		    		else
			    		dp[i][T] += prob;
			}
		}
		double ex = 0;
		//for (int j = T; j < 2 * T + 2; j++) {
			for (int i = 0; i < n; i++) {
			//	if (j == T)
					ex += i * dp[i][T];
				//else
					//ex += (i - 1) * dp[i][j];
				//System.err.format(i + " " + dp[i][T]);
			}
		//}
		for (int j = 0; j < T + 1; j++) {
			ex += n * dp[n][j];
		}
		cout << fixed << setprecision(10) << ex << '\n';
	return 0;
}