#pragma comment(linker, "/STACK:60000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define Ef(...) ((void)0)
#endif

int par[2<<20];
int Head(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = Head(par[x]);
}
void Join(int x, int y) {
    x = Head(x);
    y = Head(y);
    if (rand() & 1)
        par[x] = y;
    else
        par[y] = x;
}

typedef pair<int, int> pii;


int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {

        int n, m;
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
            par[i] = i;

        vector<pii> edges;
        vector<int> tree, rest;
        set<int> verts;
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--; b--;
            edges.emplace_back(a, b);

            if (Head(a) != Head(b)) {
                tree.push_back(i);
                adj[a].push_back(b);
                adj[b].push_back(a);
                Join(a, b);
            }
            else {
                rest.push_back(i);
                verts.insert(a);
                verts.insert(b);
            }
        }
        assert(rest.size() <= 3);

        if (verts.size() == 3 && rest.size() == 3) {
            Ef("triangle!\n");

            int v = *verts.begin();
            int intree = -1, inrest = -1;
            for (int i = 0; i < rest.size(); i++)
                if (edges[rest[i]].first == v || edges[rest[i]].second == v)
                    inrest = i;
            auto critEdge = edges[rest[inrest]];
            int u = critEdge.first == v ? critEdge.second : critEdge.first;

            vector<char> vis(n, false);
            vector<int> qarr;
            qarr.push_back(u);
            vis[u] = true;
            for (int i = 0; intree < 0 && i < qarr.size(); i++) {
                int x = qarr[i];
                for (int y : adj[x]) {
                    if (vis[y]) continue;
                    vis[y] = true;
                    qarr.push_back(y);

                    if (y == v) {
                        for (int i = 0; i < tree.size(); i++)
                            if (edges[tree[i]].first == x && edges[tree[i]].second == y || edges[tree[i]].first == y && edges[tree[i]].second == x)
                                intree = i;
                        break;
                    }
                }
            }

            Ef("swapped (%d %d) and (%d %d)\n", edges[tree[intree]].first, edges[tree[intree]].second, edges[rest[inrest]].first, edges[rest[inrest]].second);
            swap(rest[inrest], tree[intree]);
        }
        
        vector<int> mask(m, 0);
        for (int e : rest)
            mask[e] = 1;
        for (int b : mask)
            printf("%d", b);
        printf("\n");
    }

	return 0;
}