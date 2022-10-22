#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
} e[N << 1];

int dep[N];

vector< tuple<int , int , int> > res;

int dfs(int x , int fa) {
    //cout << x << fa << endl;
    dep[x] = dep[fa] + 1;
    int cur = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!dep[y]) {
            int w = dfs(y , x);
            if (w) {
                res.emplace_back(make_tuple(w , y , x));
            } else {
                int w = y;
                if (cur) {
                    res.emplace_back(make_tuple(cur , x , w));
                    cur = 0;
                } else {
                    cur = w;
                }
            }
        } else if (dep[y] > dep[x]) {
            int w = y;
            if (w) {
                if (cur) {
                    res.emplace_back(make_tuple(cur , x , w));
                    cur = 0;
                } else {
                    cur = w;
                }
            }
        }
    }
    //cout << x << ' ' << cur << endl;
    return cur;
}

int main() {
    scanf("%d%d" , &n , &m);
    memset(pre , -1 , sizeof(pre));
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (!dep[i]) {
            dfs(i , 0);
        }
    }
    printf("%u\n" , res.size());
    for (auto it : res) {
        printf("%d %d %d\n" , get<0>(it), get<1>(it), get<2>(it));
    }
}