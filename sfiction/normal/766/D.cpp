#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAXN = 1E5 + 10;

int n, m, q;
int fa[MAXN << 1], neg[MAXN << 1];

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void merge(int &u, int v){
	if (u == 0)
		u = v;
	else if (v)
		fa[v] = u;
}

int main(){
	scanf("%d%d%d", &n, &m, &q);

	map<string, int> lst;
	string s, t;
	for (int i = 1; i <= n; ++i){
		cin >> s;
		lst[s] = i;
		fa[i] = i, neg[i] = n + i;
		fa[n + i] = n + i, neg[n + i] = i;
	}

	for (int type, i = 0; i < m; ++i){
		cin >> type >> s >> t;
		int u = find(lst[s]), v = find(lst[t]);

		if (type == 1){
			if (neg[u] == v)
				puts("NO");
			else{
				puts("YES");
				if (u != v)
					fa[v] = u, fa[neg[v]] = neg[u];
			}
		}
		else{
			if (u == v)
				puts("NO");
			else{
				puts("YES");
				if (neg[u] != v){
					fa[neg[v]] = u, fa[neg[u]] = v;
					neg[u] = v, neg[v] = u;
				}
			}
		}
	}

	for (int i = 0; i < q; ++i){
		cin >> s >> t;
		int u = find(lst[s]), v = find(lst[t]);
		puts(u == v ? "1" : u == neg[v] ? "2" : "3");
	}

	return 0;
}