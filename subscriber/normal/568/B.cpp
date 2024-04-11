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

const int maxn = 4040;
int C[maxn][maxn];
int p[maxn];

int n;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;

	for (int i = 0; i < maxn; i++) for (int j = 0; j <= i; j++) if (j == 0 || i == j) C[i][j] = 1; else 
	C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;

	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		//p[i] = 1;
		for (int j = 0; j <= i - 1; j++) {
			p[i] = (p[i] + p[i - 1 - j] * 1ll * C[i - 1][j]) % M;
		}
	}		

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int k = n - i;
		int t = C[n][i] * 1ll * p[k] % M;
//		cout << t << endl;
//		if (i % 2) ans = (ans + t) % M; else ans = (ans - t + M) % M;
		if (true) ans = (ans + t) % M; else ans = (ans - t + M) % M;
	}
	cout << ans << endl;
	return 0;
}