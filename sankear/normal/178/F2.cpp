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

#define next _next
#define pb push_back

typedef long long ll;

const ll inf = (ll)1e18;

struct edge{
	int num, l, r, v;
};

int v, e, k;
edge go[6000000];
int term[6000000], first[6000000], next[6000000];
char s[2000][501];
int sz[6000];
ll d[6000][2001];
ll f[30][2001];

inline void add(char num){
	int n = strlen(s[num]), cur = 0, i = 0;
	while(i < n){
		bool fl = false;
		for(int j = first[cur], prev = -1; j > 0; prev = j, j = next[j]){
			if(s[go[j].num][go[j].l] == s[num][i]){
				int z = go[j].l;
				while(i + 1 < n && z + 1 <= go[j].r){
					if(s[go[j].num][z + 1] != s[num][i + 1]){
						if(prev == -1){
							first[cur] = next[j];
						}
						else{
							next[prev] = next[j];
						}
						go[++e].num = go[j].num;
						go[e].l = go[j].l;
						go[e].r = z;
						go[e].v = ++v;
						next[e] = first[cur];
						first[cur] = e;
						go[++e].num = go[j].num;
						go[e].l = z + 1;
						go[e].r = go[j].r;
						go[e].v = go[j].v;
						next[e] = first[v];
						first[v] = e;
						go[++e].num = num;
						go[e].l = i + 1;
						go[e].r = n - 1;
						go[e].v = v + 1;
						next[e] = first[v];
						first[v] = e;
						term[++v]++;
						return;
					}
					i++;
					z++;
				}
				if(i == n - 1){
					if(z == go[j].r){
						term[go[j].v]++;
					}
					else{
						if(prev == -1){
							first[cur] = next[j];
						}
						else{
							next[prev] = next[j];
						}
						go[++e].num = go[j].num;
						go[e].l = go[j].l;
						go[e].r = z;
						go[e].v = ++v;
						term[v]++;
						next[e] = first[cur];
						first[cur] = e;
						go[++e].num = go[j].num;
						go[e].l = z + 1;
						go[e].r = go[j].r;
						go[e].v = go[j].v;
						next[e] = first[v];
						first[v] = e;
					}
					return;
				}
				cur = go[j].v;
				fl = true;
				i++;
				break;
			}
		}
		if(fl){
			continue;
		}
		term[++v]++;
		go[++e].num = num;
		go[e].l = i;
		go[e].r = n - 1;
		go[e].v = v;
		next[e] = first[cur];
		first[cur] = e;
		return;
	}
}

void dfs(int v, int len){
	sz[v] = term[v];
	vector <int> sons;
	for(int i = first[v]; i > 0; i = next[i]){
		dfs(go[i].v, len + go[i].r - go[i].l + 1);
		sz[v] += sz[go[i].v];
		sons.pb(go[i].v);
	}
	for(int i = 0; i <= (int)sons.size(); i++){
		for(int j = 0; j <= k; j++){
			f[i][j] = -inf;
		}
	}
	f[0][0] = 0;
	for(int i = 1; i <= (int)sons.size(); i++){
		for(int j = 0; j <= min(sz[v], k); j++){
			for(int z = 0; z <= j; z++){
				f[i][j] = max(f[i][j], f[i - 1][j - z] + (ll)z * (j - z) * len + d[sons[i - 1]][z]);
			}
		}
	}
	for(int i = 0; i <= min(sz[v], k); i++){
		d[v][i] = f[(int)sons.size()][i];
	}
	for(int i = min(sz[v], k); i > 0; i--){
		for(int j = 1; j <= min(term[v], i); j++){
			d[v][i] = max(d[v][i], d[v][i - j] + (((ll)j * (j - 1)) / 2) * len + (ll)j * (i - j) * len);
		}
	}
}

int main(){
	//freopen("folding.in", "r", stdin);
	//freopen("folding.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cout << (sizeof(go) + sizeof(term) + sizeof(first) + sizeof(next) + sizeof(s) + sizeof(d) + sizeof(f)) / 1024 / 1024 << endl;
	int n;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
	}
	int v = 0, e = 0;
	for(int i = 0; i < n; i++){
		add(i);
	}
	dfs(0, 0);
	cout << d[0][k] << endl;
	return 0;
}