#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n;
int a[1505][1505];

int uf[1505];
int edges[1505]; int siz[1505];
int x[3000000], y[3000000];

struct Tree {
    Tree* fchild;
    Tree* sibling;
    int weight;
    int f[1505];
};


vector<Tree*> trees[1505];

int fin(int A)
{
    if (uf[A] == A) return A;
    return uf[A] = fin(uf[A]);
}

int comps;

void un(int A, int b)
{
    A = fin(A); b = fin(b);
    if (A == b) return;
    if (trees[A].size() > trees[b].size()) swap(A, b);
    uf[A] = b; edges[b] += edges[A]; siz[b] += siz[A];
    for (int i = 0; i < trees[A].size(); i++) trees[b].push_back(trees[A][i]);
}

bool isbad(int node)
{
    return (siz[fin(node)] * (siz[fin(node)] - 1)) / 2 != edges[fin(node)];
}

void dfs(Tree* tr)
{
    for (Tree* child = tr->fchild; child != NULL; child = child->sibling) {
        dfs(child);
    }
    tr->f[0] = 1;
    for (Tree* child = tr->fchild; child != NULL; child = child->sibling) {
        tr->weight += child->weight;
        for (int tot = tr->weight; tot >= 0; tot--) {
            tr->f[tot] = 0;
            for (int j = min(child->weight, tot); j >= 0 && tot - j <= tr->weight - child->weight; j--) {
                tr->f[tot] += mul(child->f[j], tr->f[tot - j]);
                if (tr->f[tot] >= MOD) tr->f[tot] -= MOD;
                //if (tot == 2) printf("! %d %d\n", j, tr->f[tot]);
            }
        }
        /*printf("weight %d\n", tr->weight);
        for (int i = 0; i <= tr->weight; i++) {
            printf("%d ", tr->f[i]);
        }
        printf("\n");*/
    }
    tr->f[0] = 0; tr->f[1] = 1;
    //printf("node finished\n");
}

int main()
{
    scanf("%d", &n); comps = n;
    for (int i = 1; i <= n; i++) {
        uf[i] = i, siz[i] = 1;
        Tree* leaf = new Tree;
        leaf->fchild = leaf->sibling = NULL;
        leaf->weight = 1;
        trees[i].push_back(leaf);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &(a[i][j]));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            x[a[i][j]] = i; y[a[i][j]] = j;
        }
    }
    for (int i = 1; i <= (n * (n - 1)) / 2; i++) {
        //printf("%d %d\n", x[i], y[i]);
        un(x[i], y[i]);
        edges[fin(x[i])]++;
        if (!isbad(x[i])) {
            Tree* tr = new Tree;
            tr->fchild = trees[fin(x[i])][0];
            tr->sibling = NULL; tr->weight = 0;
            for (int X = 0; X + 1 < trees[fin(x[i])].size(); X++) {
                trees[fin(x[i])][X]->sibling = trees[fin(x[i])][X + 1];
            }
            trees[fin(x[i])].clear();
            trees[fin(x[i])].push_back(tr);
        }
    }
    dfs(trees[fin(1)][0]);
    for (int i = 1; i <= n; i++) {
        printf("%d ", trees[fin(1)][0]->f[i]);
    }
    return 0;
}