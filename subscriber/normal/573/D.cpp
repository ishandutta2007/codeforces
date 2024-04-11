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
//#define max(a, b) (a > b ? a : b)

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

long long dp[N];

pair<int, int> A[N], B[N];

int ta[N], tb[N], a[N], b[N];

int n, q;
int g[N];

long long G1[N], G2[N], G3[N];

void calc(int i) {
		G1[i] = -1e18;
		G2[i] = -1e18;
		G3[i] = -1e18;
		
		if (g[i] != i) G1[i] = a[i] * 1ll * b[i];

		if (i + 1 < n && g[i] != i + 1 && g[i + 1] != i) G2[i] = a[i] * 1ll * b[i + 1] + a[i + 1] * 1ll * b[i];

		if (i + 2 < n) {
			if (g[i] != i + 1 && g[i + 1] != i + 2 && g[i + 2] != i) G3[i] = max(G3[i], a[i] * 1ll * b[i + 1] + a[i + 1] * 1ll * b[i + 2] + a[i + 2] * 1ll * b[i]);
			if (g[i] != i + 2 && g[i + 1] != i && g[i + 2] != i + 1) G3[i] = max(G3[i], a[i] * 1ll * b[i + 2] + a[i + 1] * 1ll * b[i] + a[i + 2] * 1ll * b[i + 1]);
		}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i].F);
		A[i].S = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i].F);
		B[i].S = i;
	}
	sort(A, A + n);
	sort(B, B + n);

	for (int i = 0; i < n; i++) {
		a[i] = A[i].F;
		b[i] = B[i].F;
		ta[A[i].S] = i;
		tb[B[i].S] = i;
	}
	for (int i = 0; i < n; i++) g[ta[i]] = tb[i];

	for (int i = 0; i < n; i++) {
		calc(i);
	}
	//cyka


	

	for (int it = 0; it < q; it++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		int s1 = ta[x];
		int s2 = ta[y];
		swap(g[s1], g[s2]);
		for (int i = max(0, s1 - 5); i < min(n, s1 + 5); i++) calc(i);
		for (int i = max(0, s2 - 5); i < min(n, s2 + 5); i++) calc(i);

//		for (int i = 0; i <= n; i++) dp[i] = -1e18;

		if (n < 5) {
			dp[0] = 0;
			dp[1] = G1[0];
			dp[2] = max(G2[0], dp[1] + G1[1]);
			dp[3] = max(G3[0], dp[2] + G1[2]);
			dp[3] = max(dp[3], dp[1] + G2[1]);
		
			n++;
			for (int i = 4; i < n; i++) {
				dp[i] = max(dp[i - 1] + G1[i - 1], max(dp[i - 2] + G2[i - 2], dp[i - 3] + G3[i - 3]));
			}
			printf("%I64d\n", dp[n - 1]);
		} else {
			long long aa = 0;
			long long bb = G1[0];
			long long cc = max(G2[0], bb + G1[1]);
			long long tt;
			n++;
			for (int i = 3; i < n; i++) {
				tt = max(cc + G1[i - 1], max(bb + G2[i - 2], aa + G3[i - 3]));
				aa = bb;
				bb = cc;
				cc = tt;
			}
			printf("%I64d\n", cc);
		}			

	}		

	return 0;
}