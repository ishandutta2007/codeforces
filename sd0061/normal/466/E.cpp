#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N];
int deg[N];
int O , P , Q , f[N];
bool ans[N];
pair<int , int> op[N];
vector< pair<int , int> > V[N];
int L[N] , R[N] , ncnt;
int getf(int x) {return f[x] == x ? x : f[x] = getf(f[x]);}

void dfs(int x) {
    L[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        dfs(y);
    }
    R[x] = ncnt;
}

void work() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= n ; ++ i) {
        f[i] = i;
    }
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d",&j);
        if (j < 3) {
            if (j == 1) {
                scanf("%d%d",&x,&y);
                e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
                ++ deg[x];
                ++ O;
                op[O + P] = make_pair(x , y);
            } else {
                scanf("%d",&x);
                ++ P;
                op[O + P] = make_pair(x , -P);
            }
        } else {
            ++ Q , ans[Q] = 1;
            scanf("%d%d",&x,&y);
            V[y].push_back(make_pair(x , Q));
        }
    }
    for (i = 1 ; i <= n ; ++ i)
        if (!deg[i])
            dfs(i);
    for (i = 1 ; i <= O + P ; ++ i) {
        if (op[i].second < 0) {
            x = op[i].first , k = -op[i].second;
            for (j = 0 ; j < V[k].size() ; ++ j) {
                y = V[k][j].first;
                if (getf(x) != getf(y))
                    ans[V[k][j].second] = 0;
                if (!(L[y] <= L[x] && R[x] <= R[y]))
                    ans[V[k][j].second] = 0;
            }
        } else {
            x = op[i].first;
            y = op[i].second;
            f[getf(x)] = getf(y);
        }
    }


    for (i = 1 ; i <= Q ; ++ i)
        puts(ans[i] ? "YES" : "NO");

}

int main() {
    work();
    return 0;
}