#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

vector<int> g[1000100];
vector<int> rg[1000100];
vector<bool> used;
int last = -1;

void dfs1(int v) {
	used[v] = true;
	for (auto& to: g[v]) {
		if (!used[to]) {
			dfs1(to);
		}
	}
	last = v;
}

void dfs2(int v) {
	used[v] = true;
	for (auto& to: rg[v]) {
		if (!used[to]) {
			dfs2(to);
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int Q;
    cin >> Q;
    forn (q, Q) {
    	int n, m;
    	cin >> n >> m;
    	forn (i, n) {
    		g[i].clear();
    		rg[i].clear();
    	}
    	forn (i, m) {
    		int a, b;
    		cin >> a >> b;
    		if (a == b) {
    			continue;
    		}
    		--a;
    		--b;
    		g[a].pb(b);
    		rg[b].pb(a);
    	}
    	used.assign(n, false);
    	last = 0;
    	forn (i, n) {
    		if (!used[i]) {
    			dfs1(i);
    		}
    	}
    	used.assign(n, false);
    	dfs2(last);
    	int cnt = 0;
    	forn (i, n) {
    		if (!used[i]) {
    			cnt++;
    		}
    	}
    	if (cnt == 0) {
    		printf("No\n");
    		continue;
    	}
  		printf("Yes\n%d %d\n", cnt, n - cnt);
    	forn (i, n) {
    		if (!used[i]) {
		  		printf("%d ", i + 1);
    		}
    	}
    	printf("\n");
    	forn (i, n) {
    		if (used[i]) {
		  		printf("%d ", i + 1);
    		}
    	}
    	printf("\n");
    }
}