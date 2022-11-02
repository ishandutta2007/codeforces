///Corded by rns_csy  codeforces problem 86D

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 200100
#define M 1000010

int a[N], L[N], R[N], gas[M], gas1[M], n, m;
vector <int> g[N], clr;
LL ans[N];

bool cmp(int x, int y){
	return R[x] < R[y];
}

int main(){
	///freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++){
		scanf("%d", a + i);
	}

	int d = sqrt(2 * n);

	for(int i = 1; i <= m; i ++){
		scanf("%d %d", L + i, R + i);
		g[ L[i] / d ].push_back( i );
	}

	for(int i = 0; i <= n / d; i ++){
	///	for(int i = 1; i <= n; i ++) gas[a[i]] = 0;
		memset(gas, 0, sizeof gas);
		LL tmp = 0;
		sort(g[i].begin(), g[i].end(), cmp);
		int cur = d * (i + 1);
		for(auto id : g[i]){
			for( ; cur <= R[id]; cur ++){
				gas[a[cur]] ++;
				tmp += (LL)a[cur] * (gas[a[cur]] * 2 - 1);
			}
			int pos = min(d * (i + 1) - 1, R[id]);
			ans[id] = tmp;
			for( ; pos >= L[id]; pos --){
				if(gas1[a[pos]] == 0){
					clr.push_back(a[pos]);
					gas1[a[pos]] = gas[a[pos]] + 1;
					ans[id] += (LL)a[pos] * (gas1[a[pos]] * 2 - 1);
				}
				else{
					gas1[a[pos]] ++;
					ans[id] += (LL)a[pos] * (gas1[a[pos]] * 2 - 1);
				}
			}
			for( auto y : clr) gas1[y] = 0;
			clr.clear();
		}
	}

	for(int i = 1; i <= m; i ++) printf("%I64d\n", ans[i]);
}