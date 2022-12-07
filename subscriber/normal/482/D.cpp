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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
vector<int> v[N];

int was[N][2];
int mem[N][2];

void add(int & a, int b) {
	a += b;
	if (a >= M) a-= M;	
} 

int rec(int x, int o) {
	if (was[x][o]) return mem[x][o];

	if (v[x].size() == 0) {
		return (o == 1);
	}		
	o ^= 1;

	int dp[v[x].size() + 1][2];

	for (int i = 0; i <= v[x].size(); i++) for (int j = 0; j < 2; j++) dp[i][j] = 0;

	dp[0][0] = 1;

	for (int i = 0; i < v[x].size(); i++) for (int j = 0; j < 2; j++) {
		add(dp[i + 1][j], dp[i][j]);
		for (int k = 0; k < 2; k++) add(dp[i + 1][j ^ k], dp[i][j] * 1ll * rec(v[x][i], k) % M);
	}

	int ret = dp[v[x].size()][o];

	for (int i = 0; i <= v[x].size(); i++) for (int j = 0; j < 2; j++) dp[i][j] = 0;

	dp[0][0] = 1;

	for (int i = 0; i < v[x].size(); i++) for (int j = 0; j < 2; j++) {
		add(dp[i + 1][j], dp[i][j]);
		for (int k = 0; k < 2; k++) add(dp[i + 1][j ^ k], dp[i][j] * 1ll * rec(v[x][v[x].size() - 1 - i], k) % M);
	}

	ret = (ret + dp[v[x].size()][o]) % M;

	int dp2[v[x].size()][2][2];

	for (int i = 0; i <= v[x].size(); i++) for (int j1 = 0; j1 < 2; j1++) for (int j2 = 0; j2 < 2; j2++) dp2[i][j1][j2] = 0;

	dp2[0][0][o] = 1;

	for (int i = 0; i < v[x].size(); i++) for (int j1 = 0; j1 < 2; j1++) for (int j2 = 0; j2 < 2; j2++) if (dp2[i][j1][j2] > 0) {
		add(dp2[i + 1][j1][j2], dp2[i][j1][j2]);

		for (int k = 0; k < 2; k++) {
			int p1 = j1;
			int p2 = j2 ^ k;
			if (p1 != p2) continue;

			add(dp2[i + 1][j1 ^ k][j2 ^ k], dp2[i][j1][j2] * 1ll * rec(v[x][i], k) % M);
		}
	}
	
	ret -= dp2[v[x].size()][o][0];
	if (ret < 0) ret += M;   

	o ^= 1;

	was[x][o] = 1;
	mem[x][o] = ret;

	return ret;			
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		v[x - 1].pb(i);
	}

	int ans = (rec(0, 0) + rec(0, 1)) % M;
	cout << ans << endl;
	return 0;
}