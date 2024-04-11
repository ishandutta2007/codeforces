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

long long l;
int n, k;

pair<int, int> q[1000111];
int dp[1000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i].F);
		q[i].S = i;
	}
	sort(q, q + n);
	for (int i = 0; i < n; i++) dp[i] = 1;
	
	int ans = 0;
	for (int s = 1; s <= k; s++) {
		for (int i = 0; i < n; i++) {
			long long bl = l / n;
			if (q[i].S < l % n) bl++;
			long long var = bl - s + 1;
			if (var <= 0) continue;

			var %= M;

			ans = (ans + dp[i] * 1ll * var) % M;
		}
		int sum = 0;
		for (int i = 0; i < n; ) {
			int j = i;
			while (j < n && q[j].F == q[i].F) {
				sum = (sum + dp[j]) % M;
				j++;
			}			
			for (int u = i; u < j; u++) dp[u] = sum;
			i = j;
		}
	}
	cout << ans << endl;
	return 0;
}