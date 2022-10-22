#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
const int M = 600005;
int n , m , Q;
char g[N][N];
vector< tuple<int , int , int> > q[N][N];
bool res[M];
bitset<N> f[N][N] , h[N][N];
void solve(int l , int r) {
    if (l > r) return;
    int mid = l + r >> 1;
    int i , j;
    for (i = mid ; i <= r ; ++ i)
        for (j = 0 ; j < m ; ++ j) {
            f[i][j] &= 0;
            if (g[i][j] != '#') {
                if (i == mid)
                    f[i][j].set(j);
                else
                    f[i][j] = f[i - 1][j];
                if (j)
                    f[i][j] |= f[i][j - 1];
            }
        }
    
    for (i = mid ; i >= l ; -- i)
        for (j = m - 1 ; j >= 0 ; -- j) {
            h[i][j] &= 0;
            if (g[i][j] != '#') {
                if (i == mid)
                    h[i][j].set(j);
                else
                    h[i][j] |= h[i + 1][j];
                if (j + 1 < m)
                    h[i][j] |= h[i][j + 1];
            }
        }
    for (i = l ; i <= mid; ++ i)
        for (j = mid ; j <= r ; ++ j)
            for (auto& it : q[i][j])
                res[get<2>(it)] = (h[i][get<0>(it)] & f[j][get<1>(it)]).count();
    solve(l , mid - 1);
    solve(mid + 1 , r);

}

void work() {
    int i;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , g[i]);
    scanf("%d" , &Q);
    for (i = 0 ; i < Q ; ++ i) {
        int a , b , c , d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        -- a , -- b , -- c , -- d;
        q[a][c].push_back(make_tuple(b , d , i));
    }
    solve(0 , n - 1);
    for (i = 0 ; i < Q ; ++ i)
        puts(res[i] ? "Yes" : "No");
}

int main() {
    work();
    return 0;
}