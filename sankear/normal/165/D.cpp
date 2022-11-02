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
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define pb push_back

int cur;
bool used[100100];
int num[100100], pos[100100], h[100100], maxv[100100], look[100100], a[100100], b[100100];
vector <int> v[100100], nums[100100], lst[100100], rmq[100100];

void dfs(int a, int b, bool fl){
	if(!fl){
		pos[a] = lst[num[a]].size();
		lst[num[a]].pb(a);
	}
	used[a] = true;
	h[a] = b;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(!used[v[a][i]]){
			if(fl){
				num[v[a][i]] = cur++;
			}
			else{
				num[v[a][i]] = num[a];
			}
			look[nums[a][i]] = v[a][i];
			dfs(v[a][i], b + 1, false);
		}
	}
}

inline void update(int a, int b, int c){
	b += maxv[a];
	rmq[a][b] = c;
	while(b > 1){
		b /= 2;
		rmq[a][b] = rmq[a][b * 2] + rmq[a][b * 2 + 1];
	}
}

inline int get(int a, int l, int r){
	int res = 0;
	l += maxv[a];
	r += maxv[a];
	while(l <= r){
		if(l % 2 != 0){
			res += rmq[a][l];
		}
		l = (l + 1) / 2;
		if(r % 2 == 0){
			res += rmq[a][r];
		}
		r = (r - 1) / 2;
	}
	return res;
}

int main(){
	//freopen("caravans.in", "r", stdin);
	//freopen("caravans.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		v[a[i]].pb(b[i]);
		nums[a[i]].pb(i);
		v[b[i]].pb(a[i]);
		nums[b[i]].pb(i);
	}
	int root = 0;
	for(int i = 1; i < n; i++){
		if(v[i].size() > v[root].size()){
			root = i;
		}
	}
	cur = 0;
	dfs(root, 0, true);
	for(int i = 0; i < cur; i++){
		maxv[i] = 1;
		while(maxv[i] < (int)lst[i].size()){
			maxv[i] *= 2;
		}
		rmq[i].resize(2 * maxv[i]);
		for(int j = 0; j < (int)lst[i].size(); j++){
			rmq[i][j + maxv[i]] = 1;
		}
		for(int j = maxv[i] - 1; j > 0; j--){
			rmq[i][j] = rmq[i][j * 2] + rmq[i][j * 2 + 1];
		}
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int tt;
		scanf("%d", &tt);
		if(tt == 1){
			int id;
			scanf("%d", &id);
			id--;
			update(num[look[id]], pos[look[id]], 1);
			continue;
		}
		if(tt == 2){
			int id;
			scanf("%d", &id);
			id--;
			update(num[look[id]], pos[look[id]], 0);
			continue;
		}
		int f, t;
		scanf("%d %d", &f, &t);
		f--;
		t--;
		if(f == t){
			printf("0\n");
			continue;
		}
		if(f == root){
			if(get(num[t], 0, pos[t]) != h[t] - h[f]){
				printf("-1\n");
			}
			else{
				printf("%d\n", h[t] - h[f]);
			}
			continue;
		}
		if(t == root){
			if(get(num[f], 0, pos[f]) != h[f] - h[t]){
				printf("-1\n");
			}
			else{
				printf("%d\n", h[f] - h[t]);
			}
			continue;
		}
		if(num[f] == num[t]){
			if(h[f] > h[t]){
				swap(f, t);
			}
			if(get(num[f], pos[f] + 1, pos[t]) != h[t] - h[f]){
				printf("-1\n");
			}
			else{
				printf("%d\n", h[t] - h[f]);
			}
			continue;
		}
		if(get(num[f], 0, pos[f]) != h[f] - h[root]){
			printf("-1\n");
			continue;
		}
		if(get(num[t], 0, pos[t]) != h[t] - h[root]){
			printf("-1\n");
			continue;
		}
		printf("%d\n", h[f] + h[t] - 2 * h[root]);
	}
	return 0;
}