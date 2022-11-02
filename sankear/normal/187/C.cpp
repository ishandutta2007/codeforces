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

bool good[100100], used[100100];
int queue[100100], lst[100100], use[100100], nlst[100100], d[100100];
vector <int> v[100100];

void dfs(int a){
	used[a] = true;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(!used[v[a][i]]){
			dfs(v[a][i]);
		}
	}
}

int main(){
	//freopen("covertexts.in", "r", stdin);
	//freopen("covertexts.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < k; i++){
		int a;
		scanf("%d", &a);
		a--;
		good[a] = true;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	int s, t;
	scanf("%d %d", &s, &t);
	s--;
	t--;
	dfs(s);
	if(!used[t]){
		printf("-1\n");
		return 0;
	}
	int ans = n, l = 1, r = n - 1, step = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		for(int i = 0; i < n; i++){
			used[i] = false;
		}
		int sz = 1;
		lst[0] = s;
		used[s] = true;
		while(true){
			step++;
			int l = 0, r = 0;
			for(int i = 0; i < sz; i++){
				queue[r++] = lst[i];
				use[lst[i]] = step;
				d[lst[i]] = 0;
			}
			int nsz = 0;
			while(l < r && use[t] != step){
				int cur = queue[l++];
				if(d[cur] == mid){
					continue;
				}
				for(int i = 0; i < (int)v[cur].size() && use[t] != step; i++){
					if(use[v[cur][i]] != step){
						use[v[cur][i]] = step;
						d[v[cur][i]] = d[cur] + 1;
						queue[r++] = v[cur][i];
						if(good[v[cur][i]] && !used[v[cur][i]]){
							used[v[cur][i]] = true;
							nlst[nsz++] = v[cur][i];
						}
					}
				}
			}
			if(use[t] == step || nsz == 0){
				break;
			}
			sz = nsz;
			for(int i = 0; i < sz; i++){
				lst[i] = nlst[i];
			}
		}
		if(use[t] == step){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}