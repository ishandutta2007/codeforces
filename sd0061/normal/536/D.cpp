#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;
int n , m , pre[N] , mcnt , p[N];
struct edge {
    int x , w , next;
}e[200005];
int s , t , a[N] , b[N] , A , B;
LL d[N] , c[N];
bool vis[N];
int Dijkstra(int x , int *D) {
    int i , y , z;
    priority_queue< pair<int , int> > Q;
    for (i = 1 ; i <= n ; ++ i)
        d[i] = 1LL << 60 , vis[i] = 0;
    d[x] = 0 , Q.push(make_pair(0 , x));   
    while (!Q.empty()) {
        x = Q.top().second; Q.pop();
        if (vis[x]) continue; vis[x] = 1;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = e[i].w;
            if (!vis[y] && d[y] > d[x] + z) {
                d[y] = d[x] + z;
                Q.push(make_pair(-d[y] , y));
            }
        }
    }
    memcpy(c , d , sizeof(d));
    sort(c + 1 , c + n + 1);
    int m = unique(c + 1 , c + n + 1) - c - 1;
    for (i = 1 ; i <= n ; ++ i)
        D[i] = lower_bound(c + 1 , c + m + 1 , d[i]) - c;
    return m;
}
LL f[N][N][2] , val[N][N] , R[N][N] , D[N][N];
int cnt[N][N] , rr[N][N] , dd[N][N];
void work() {
    int i , j , x , y , z;
    LL sum = 0;
    scanf("%d%d%d%d" , &n , &m , &s , &t);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &p[i]) , sum += p[i];
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    A = Dijkstra(s , a);
    B = Dijkstra(t , b);
    for (i = 1 ; i <= n ; ++ i) {
        //cout << a[i] << ' ' << b[i] << endl;
        ++ cnt[a[i]][b[i]];
        val[a[i]][b[i]] += p[i];
    }
    for (i = A ; i > 0 ; -- i)
        for (j = B ; j > 0 ; -- j) {
            val[i][j] += val[i + 1][j] + val[i][j + 1];
            val[i][j] -= val[i + 1][j + 1];
            cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1];
            cnt[i][j] -= cnt[i + 1][j + 1];            
        }
    memset(f , 0xC0 , sizeof(f));
    for (i = A ; i >= 0 ; -- i)
        for (j = B ; j >= 0 ; -- j) {
            if (!cnt[i + 1][j + 1]) {
                f[i][j][0] = f[i][j][1] = 0;
                dd[i][j] = A , rr[i][j] = B;
            } else {                
                LL w = val[i + 1][j + 1];
                int &k = dd[i][j] , &l = rr[i][j];
                k = dd[i + 1][j] , l = rr[i][j + 1];
                while (cnt[i + 1][j + 1] > cnt[k][j + 1]) -- k;
                while (cnt[i + 1][j + 1] > cnt[i + 1][l]) -- l;
                
                    /*for (k = i + 1 ; k <= A ; ++ k)
                    if (cnt[i + 1][j + 1] > cnt[k + 1][j + 1])
                        f[i][j][0] = max(f[i][j][0] , -f[k][j][1]);
                for (k = j + 1 ; k <= B ; ++ k)
                    if (cnt[i + 1][j + 1] > cnt[i + 1][k + 1])
                    f[i][j][1] = max(f[i][j][1] , -f[i][k][0]);*/
                f[i][j][0] = D[k][j] + w;
                f[i][j][1] = R[i][l] + w;                
            }
            if (i == A)
                D[i][j] = -f[i][j][1];
            else
                D[i][j] = max(D[i + 1][j] , -f[i][j][1]);
            if (j == B)
                R[i][j] = -f[i][j][0];
            else
                R[i][j] = max(R[i][j + 1] , -f[i][j][0]);
        }
    LL A = f[0][0][0] , B = sum - A;
    if (A > B) puts("Break a heart");
    if (A == B) puts("Flowers");
    if (A < B) puts("Cry");
    
}

int main() {
    work();
    return 0;
}