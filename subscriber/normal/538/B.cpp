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
int dp[1000111], pr[1000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	vector<int> e;

	for (int o = 0; o < pw(6); o++) {
		int s = 0;
		for (int i = 0; i < 6; i++) {
			s *= 10;
			if (o & pw(i)) s++;
		}
		e.pb(s);
	}
	e.pb((int)1e6);
	sort(e.begin(), e.end());
	
	cin >> n;
	for (int i = 0; i <= n; i++) dp[i] = 1e9;
	dp[0] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < e.size(); j++) if (i + e[j] > n) break; else {
		if (dp[i] + 1 < dp[i + e[j]]) {
			dp[i + e[j]] = dp[i] + 1;
			pr[i + e[j]] = e[j];
		}
	}
	vector<int> ans;
	int x = n;
	while (x > 0) {
		ans.pb(pr[x]);
		x -= pr[x];
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 == ans.size()) puts(""); else putchar(' ');
	}
	return 0;
}