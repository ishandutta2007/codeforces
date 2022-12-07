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
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, tra;
string a[4];
int dp[222][4];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> tra;
		for (int i = 0; i < 3; i++) cin >> a[i];
		int y = -1;
		for (int i = 0; i < 3; i++) if (a[i][0] == 's') y = i;

		for (int i = 0; i < 3; i++) for (int j = 0; j <= n + 5; j++) dp[j][i] = 0;

		dp[0][y] = 1;

		int ok = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) if (dp[i][j]) {
			if (i + 1 == n) {
				ok = 1;
				continue;
			}
			if (a[j][i + 1] != '.') continue;
			for (int k = 0; k < 3; k++) if (abs(k - j) <= 1) {
				if (a[k][i + 1] != '.') continue;

				if (i + 2 == n) {
					ok = 1;
					continue;
				}
				if (a[k][i + 2] != '.') continue;
				if (i + 3 == n) {
					ok = 1;
					continue;
				}
				if (a[k][i + 3] != '.') continue;
				dp[i + 3][k] = 1;
			}
		}
		if (ok) puts("YES"); else puts("NO");
	}
	return 0;
}