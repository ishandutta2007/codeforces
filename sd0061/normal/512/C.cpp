#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 405;
const int M = 20005;
int n , a[N];
bool f[M];
int s , t;
struct arc {
    int x , f , next;
}e[N * N * 2];
int pre[N] , mcnt;
void addarc(int x ,int y ,int z) {
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N] , q[N] , re[N];
bool BFS() {
    memset(d , -1 , sizeof(d));
    int top = 0 , bot = -1;
    q[++ bot] = s , d[s] = 1;
    while (top != bot + 1) {
        int x = q[top ++];
        for (int i = pre[x] ; ~i ;i = e[i].next) {
            int y = e[i].x;
            if (!~d[y] && e[i].f) {
                d[y] = d[x] + 1 , q[++ bot] = y;
                if (y == t) return 1;
            }
        }
    }
    return 0;
}
int DFS(int x , int flow = 1 << 30) {
    if (x == t || !flow) return flow;
    int sum = 0 , u;
    for (int& i = cur[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (d[y] == d[x] + 1 && (u = DFS(y , min(flow , e[i].f)))) {
            e[i].f -= u , e[i ^ 1].f += u;
            sum += u , flow -= u;
            if (!flow) break;
        }
    }
    if (!sum) d[x] = -1;
    return sum;
}
int dinic() {
    int ans = 0;
    while (BFS()) {
        memcpy(cur , pre , sizeof(cur));
        ans += DFS(s);
    }
    return ans;
}

void work() {
    int i , j , x;
    for (i = 2 ; i * i < M ; ++ i) {
        if (f[i]) continue;
        for (j = i * i ; j < M ; j += i)
            f[j] = 1;
    }
    scanf("%d",&n);
    x = 0 , s = n + 1 , t = s + 1;
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
        if (a[i] & 1) {
            ++ x;
            addarc(i , t , 2);
        } else {
            -- x;
            addarc(s , i , 2);
        }
    }
    if (x) {
        puts("Impossible");
        return;
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (a[i] & 1) continue;
        ++ x;
        for (j = 1 ; j <= n ; ++ j) {
            if (~a[j] & 1) continue;
            if (!f[a[i] + a[j]]) {
                addarc(i , j , 1);
            }
        }
    }
    int res = dinic();
    if (res != x + x) {
        puts("Impossible");
        return;    
    }
    for (i = 1 ; i <= n ; ++ i) {
        for (j = pre[i] ; ~j ; j = e[j].next) {
            if (a[i] & 1) {
                if (e[j].f) {
                    x = e[j].x;
                    if (!re[i])
                        re[i] = x;
                    else
                        re[i + n] = x;
                }
            } else {
                if (e[j ^ 1].f) {
                    x = e[j].x;
                    if (!re[i])
                        re[i] = x;
                    else
                        re[i + n] = x;
                }            
            }

        }
    }    
    vector< vector<int> > ans;
    memset(f , 0 , sizeof(f));
    for (i = 1 ; i <= n ; ++ i) {
        if (f[i]) continue;
        vector<int> L;
        x = i;
        while (1) {
            if (x > n)
                x -= n;
            L.push_back(x);
            f[x] = f[x + n] = 1;
            if (!f[re[x]])
                x = re[x];
            else if (!f[re[x + n]])
                x = re[x + n];
            else
                break;
        }
        ans.push_back(L);
    }
    printf("%d\n" , (int)ans.size());
    for (auto& it1 : ans) {
        printf("%d" , (int)it1.size());
        for (auto it2 : it1) {
            printf(" %d" , it2);
        }
        puts("");
    }
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}