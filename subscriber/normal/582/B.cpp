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

int n, T;
int a[N], b[N];
int dp[N];
int h[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> T;
	int ma = 0;
	for (int i = 0; i < n; i++) {
		 cin >> a[i];
		 h[a[i]]++;
		 if (h[a[i]] > ma) ma = h[a[i]];
	}		 

	int len = n * min(T, n + 3);
	for (int i = 0; i < len; i++) b[i] = a[i % n];

	for (int i = 0; i < len; i++) dp[i] = 1;
	for (int i = 0; i < len; i++) for (int j = 1; j <= n; j++) {
		if (i + j >= len) break;

		if (b[i] <= b[i + j]) dp[i + j] = max(dp[i + j], dp[i] + 1);
	}
	int ans = 0;
	for (int i = 0; i < len; i++) ans = max(ans, dp[i]);

	ans += ma * (T - min(T, n + 3));

	cout << ans << endl;


	return 0;
}