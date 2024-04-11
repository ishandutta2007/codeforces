#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define pb push_back

typedef long long ll;

const int inf = (int)1e9;

struct tr{
	int l, r, val;
};

int sz, h, m, res;
bool used[200200];
int col[200200], pos[200200], maxv[200200];
vector <int> lst[200200];
vector <tr> rmq[200200];

void dfs(int a){
	used[a] = true;
	col[a] = sz;
	pos[a] = lst[sz].size();
	lst[sz].pb(a);
	a = (a + m) % h;
	if(!used[a]){
		dfs(a);
	}
}

inline void update(vector <tr> &rmq, int maxv, int a, int b){
	a += maxv;
	rmq[a].val = b;
	while(a > 1){
		a /= 2;
		rmq[a].val = min(rmq[a * 2].val, rmq[a * 2 + 1].val);
	}
}

void dfs(vector <tr> &rmq, int maxv, int v, int l, int r){
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return;
	}
	if(rmq[v].val > 0){
		return;
	}
	if(v >= maxv){
		res = min(res, v - maxv);
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		if(rmq[v * 2].val == 0){
			dfs(rmq, maxv, v * 2, l, r);
		}
		else{
			dfs(rmq, maxv, v * 2 + 1, l, r);
		}
		return;
	}
	dfs(rmq, maxv, v * 2, l, r);
	dfs(rmq, maxv, v * 2 + 1, l, r);
}

int main(){
	//freopen("flooringtiles.in", "r", stdin);
	//freopen("flooringtiles.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d %d %d", &h, &m, &n);
	sz = 0;
	for(int i = 0; i < h; i++){
		if(!used[i]){
			dfs(i);
			sz++;
		}
	}
	for(int i = 0; i < sz; i++){
		maxv[i] = 1;
		while(maxv[i] < (int)lst[i].size()){
			maxv[i] *= 2;
		}
		rmq[i].resize(2 * maxv[i]);
		for(int j = 0; j < maxv[i]; j++){
			rmq[i][j + maxv[i]].l = rmq[i][j + maxv[i]].r = j;
			rmq[i][j + maxv[i]].val = 0;
		}
		for(int j = maxv[i] - 1; j > 0; j--){
			rmq[i][j].l = rmq[i][j * 2].l;
			rmq[i][j].r = rmq[i][j * 2 + 1].r;
			rmq[i][j].val = 0;
		}
	}
	map <int, int> mem;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		char ch;
		int id;
		scanf(" %c %d", &ch, &id);
		if(ch == '+'){
			int hash;
			scanf("%d", &hash);
			res = inf;
			dfs(rmq[col[hash]], maxv[col[hash]], 1, pos[hash], (int)lst[col[hash]].size() - 1);
			if(res == inf){
				ans += (int)lst[col[hash]].size() - pos[hash];
				dfs(rmq[col[hash]], maxv[col[hash]], 1, 0, pos[hash] - 1);
				ans += res;
			}
			else{
				ans += res - pos[hash];
			}
			mem[id] = lst[col[hash]][res];
			update(rmq[col[hash]], maxv[col[hash]], res, 1);
			continue;
		}
		int elem = mem[id];
		update(rmq[col[elem]], maxv[col[elem]], pos[elem], 0);
	}
	printf("%I64d\n", ans);
	return 0;
}