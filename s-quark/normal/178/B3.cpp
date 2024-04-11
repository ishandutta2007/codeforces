#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 100004;

int s[MAXN];
int b[MAXN*2], next[MAXN*2];
int f[MAXN];
int num[MAXN], low[MAXN];
int d[MAXN];
int u[MAXN], v[MAXN], ans[MAXN];
vector<int> block[MAXN];
vector<int> quest[MAXN];
int f1[MAXN];
int cnt;

int getF1(int i){
	if(f1[i] != i)
		return f1[i] = getF1(f1[i]);
	return i;
}

int getF(int i){
	if(f[i] != i)
		return f[i] = getF(f[i]);
	return i;
}
	

void dfs1(int i){
	low[i] = num[i] = cnt++;
	int j;
	for(j = s[i]; j != -1; j = next[j]){
		if(num[b[j]] == -1){
			f[b[j]] = i;
			dfs1(b[j]);
		}
		if(b[j] != f[i])
			low[i] = min(low[i], low[b[j]]);
	}
	if(low[i] == num[i]){
		f[i] = i;
	}
}

void dfs2(int i){
	int j, k, t;
	num[i] = 1;
	f1[i] = i;
	for(j = 0; j < quest[i].size(); j++){
		t = quest[i][j];
		t = i^u[t]^v[t];
		if(num[t])
			ans[quest[i][j]] = getF1(t);
	}
	for(j = 0; j < block[i].size(); j++)
		for(k = s[block[i][j]]; k != -1; k = next[k])
			if(!num[f[b[k]]]){
				d[f[b[k]]] = d[i]+1;
				dfs2(f[b[k]]);
				f1[f[b[k]]] = i;
			}
}

int main()
{
	#ifdef __FIO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n, m, k;
	int i, j;
	scanf("%d%d", &n, &m);
	memset(num, -1, sizeof num);
	memset(s, -1, sizeof s);
	for(i = 0; i < m; i++){
		scanf("%d%d", &b[i], &b[i+m]);
		next[i] = s[b[i+m]];
		s[b[i+m]] = i;
		next[i+m] = s[b[i]];
		s[b[i]] = i+m;
	}
	f[1] = -1;
	dfs1(1);
	for(i = 1; i <= n; i++)
		block[getF(i)].pb(i);
	scanf("%d", &k);
	for(i = 0; i < k; i++){
		scanf("%d%d", &u[i], &v[i]);
		u[i] = f[u[i]];
		v[i] = f[v[i]];
		quest[u[i]].pb(i);
		quest[v[i]].pb(i);
	}
	memset(num, 0, sizeof num);
	d[1] = 0;
	dfs2(1);
	for(i = 0; i < k; i++)
		printf("%d\n", d[u[i]] + d[v[i]] - d[ans[i]]*2);
	return 0;
}