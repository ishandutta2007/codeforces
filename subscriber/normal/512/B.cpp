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

map<int, int> was;
vector<int> z;
int dp[1000111];

int x[333], c[333];

void add(int x) {
	if (was[x]) return;
	was[x] = 1;
	z.pb(x);
}


int n;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);

	for (int s = 0; s < n; s++) {
		for (int j = 1; j * j <= x[s]; j++) if (x[s] % j == 0) {
			add(j);
			add(x[s] / j);
		}
	}
	sort(z.begin(), z.end());

//	for (int i = 0; i < z.size(); i++) cout << z[i] << " ";
//	cout <<endl;

	for (int i = 0; i < z.size(); i++) dp[i] = 1e9 + 1;

	for (int i = 0; i < n; i++) {
		int k = lower_bound(z.begin(), z.end(), x[i]) - z.begin();
		dp[k] = min(dp[k], c[i]);	
	}

	for (int i = z.size() - 1; i > 0; i--) {
		for (int j = 0; j < n; j++) if (x[j] % z[i] > 0) {
			int t = __gcd(x[j], z[i]);
			int k = lower_bound(z.begin(), z.end(), t) - z.begin();
			dp[k] = min(dp[k], dp[i] + c[j]);
				
		}
	}
	if (dp[0] > 1e9) dp[0] = -1;
	cout << dp[0] << endl;



	return 0;
}