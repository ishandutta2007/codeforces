#include<bits/stdc++.h>
using namespace std;

#define N 2020
#define M 2000020

typedef long long LL;

struct edge{
	int x, y, dist;
	edge(){}
	edge(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist){};
}d[M];

bool cmp(edge A, edge B){ return A.dist < B.dist; }

const LL INF = 1ll << 62;

int n, dist, u, v;
LL dp[N], diff;

template<class T> void CHK_MIN(T &a, T b){ if(a > b) a = b; }

int main(){
///	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i < n; i ++){
		for(int j = i + 1; j <= n; j ++){
			scanf("%d", &dist);
			d[cnt ++] = edge(i, j, dist);
		}
	}
	sort(d, d + cnt, cmp);
   int mn = d[0].dist;
   for(int i = 0; i < cnt; i ++) d[i].dist -= mn;
   LL tmp = (LL)mn * (n - 1);
   for(int i = 1; i <= n; i ++) dp[i] = INF;
   for(int i = 0; i < cnt; i ++){
		u = d[i].x;
		v = d[i].y;
		diff = d[i].dist;
		CHK_MIN(dp[u], min(dp[v], diff) + diff);
		CHK_MIN(dp[v], min(dp[u], diff) + diff);
   }
   for(int i = 1; i <= n; i ++){
		printf("%I64d\n", dp[i] + tmp);
   }
}