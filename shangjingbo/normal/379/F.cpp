#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define FOR(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++ i)

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-8;
const double PI = acos(-1.0);

const int maxn = 1000000 + 20;

int jump[maxn][20], depth[maxn];

int lca(int a, int b)
{
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int target = depth[b];
    for (int i = 19;depth[a] > target; -- i) {
        if (depth[jump[a][i]] >= target) {
            a = jump[a][i];
        }
    }
    
    if (a == b) {
        return a;
    }
    for (int i = 19; i >= 0; -- i) {
        int ta = jump[a][i];
        int tb = jump[b][i];
        if (ta != tb) {
            a = ta;
            b = tb;
        }
    }
    return jump[a][0];
}

void prepare(int u)
{
    for (int i = 0; i < 20 && jump[u][i] ; ++ i) {
        jump[u][i + 1] = jump[ jump[u][i] ][i];
    }
}

int dist(int a, int b)
{
    int c = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
}

int main()
{
    int q;
    memset(jump, 0, sizeof(jump));
    memset(depth, 0, sizeof(depth));
    depth[0] = -1;
    jump[2][0] = jump[3][0] = jump[4][0] = 1;
    depth[2] = depth[3] = depth[4] = 1;
    
    int n = 4;
    int len = 2, start = 2, end = 3;
    for (scanf("%d" ,&q); q --; ) {
        int v;
        scanf("%d", &v);
        
        jump[n + 1][0] = jump[n + 2][0] = v;
        depth[n + 1] = depth[n + 2] = depth[v] + 1;
        prepare(n + 1);
        prepare(n + 2);
        
        int d = dist(n + 1, start);
        if (d > len) {
            len = d;
            end = n + 1;
        } else {
            d = dist(n + 1, end);
            if (d > len) {
                len = d;
                start = n + 1;
            }
        }
        
        n += 2;
        
        printf("%d\n", len);
        
//        printf("%d %d\n", start, end);
    }
    
    return 0;
}