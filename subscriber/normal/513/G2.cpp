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

int n, k;
int p[1111];

long double c[2][2], r[2][2], a[2][2];

long double dp[333][33][33];

void oo1() {
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) c[i][j] = 0;

	for (int i = 0; i < 2; i++) for (int j = 0; j  < 2; j++) for (int k = 0; k < 2; k++) c[i][j] += r[i][k] * a[k][j];

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) r[i][j] = c[i][j];
}

void oo2() {
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) c[i][j] = 0;

	for (int i = 0; i < 2; i++) for (int j = 0; j  < 2; j++) for (int k = 0; k < 2; k++) c[i][j] += a[i][k] * a[k][j];

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) a[i][j] = c[i][j];
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> p[i];

	long double ans = 0;
		for (int g = 0; g <= k; g++)for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) dp[g][x][y] = 0;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
	
		if (p[i] < p[j])
			dp[0][i][j]  = 1;
		else dp[0][j][i] = 1;			
	}
	for (int g = 0; g <= k; g++)for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) 
	{
		for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
			int xx = x;
			int yy = y;
			if (i <= xx && xx <= j) xx = j - (xx - i);
			if (i <= yy && yy <= j) yy = j - (yy - i);

			dp[g + 1][xx][yy] += dp[g][x][y] / (n * (n + 1) / 2);
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) ans += dp[k][i][j];


	printf("%.15lf\n", (double)ans);
	return 0;
}