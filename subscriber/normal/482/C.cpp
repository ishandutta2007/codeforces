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
long long C[22][22];
int eq[55][55];

long long D[2000222];

string s[55];

int S[22];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	for (int i = 0; i <= 20; i++) for (int j = 0; j <= i; j++) if (j == 0 || j == i) C[i][j] = 1; else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> s[i];

	int m = s[0].size();

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) if (s[i][k] == s[j][k]) eq[i][j] += pw(k);
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) D[eq[i][j]] |= pw(i);

	for (int o = pw(m) - 1; o >= 0; o--)
		for (int i = 0; i < m; i++) if (o & pw(i)) D[o - pw(i)] |= D[o];

	long double ans = 0;		

	for (int o = 0; o < pw(m); o++) {
		int t = 0;	
		long long q = pw(m) - 1 - o;
		t = __builtin_popcountll(D[q]);
//		for (int i = 0; i < n; i++) if (D[q] & pw(i)) t++;

		int sz = __builtin_popcount(o);
//		for (int i = 0; i < m; i++) if (o & pw(i)) sz++;

		S[sz] += t;
	}	

	for (int i = 0; i <= m; i++) ans += S[i] / (long double)1. / C[m][i];
	ans /= n;

	printf("%.15lf\n", (double)ans);



	return 0;
}