#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;

int n , m , M , F;
char g[30][30];
int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1};
int dist[30][30][30][30];
void bfs(int x , int y , int d[30][30]) {
    queue<int> Q;
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j)
            d[i][j] = 1 << 30;
    Q.push(x) , Q.push(y) , d[x][y] = 0;
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        y = Q.front() , Q.pop();
        for (int i = 0 ; i < 4 ; ++ i) {
            int X = x + dx[i] , Y = y + dy[i];
            if (g[X][Y] != '#' && d[X][Y] == 1 << 30) {
                d[X][Y] = d[x][y] + 1;
                Q.push(X) , Q.push(Y);
            }
        }
    }
}
pair<int , int> pos[N];
int T[N];

int s , t;
struct arc {
    int x , f , next;
}e[N * N * 2];
int pre[N] , mcnt;
void addarc(int x ,int y ,int z) {
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N] , q[N];
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

struct event {
    LL T;
    int x , y , w;
    bool operator < (const event& R) const {
        return T < R.T;
    }
};

void work() {
    int i , j , x , y;
    scanf("%d%d%d%d",&n,&m,&M,&F);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , g[i] + 1);
    for (i = 0 ; i <= m + 1 ; ++ i)
        g[0][i] = g[n + 1][i] = '#';
    for (i = 0 ; i <= n + 1 ; ++ i)
        g[i][0] = g[i][m + 1] = '#';
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (g[i][j] != '#') {
                bfs(i , j , dist[i][j]);
            }
    for (i = 1 ; i <= M + F + 1 ; ++ i)
        scanf("%d%d%d",&pos[i].first , &pos[i].second , &T[i]);
    if (abs(M - F) != 1) {
        puts("-1");
        return;
    }
    if (M > F) {
        swap(pos[1] , pos[M + 1]);
        swap(T[1] , T[M + 1]);        
        ++ F;
    } else
        ++ M;

    //vector<event> V;
    int num = n * m;
    s = M + F + num + num + 1 , t = s + 1;
        
    LL l = 0 , r = 1LL << 42 , mid;
    while (l < r) {
        mid = l + r >> 1;
        memset(pre , -1 , sizeof(pre)) , mcnt = 0;
        for (i = 1 ; i <= M ; ++ i)
            addarc(s , i , 1);
        for (i = 1 ; i <= F ; ++ i)
            addarc(M + i , t , 1);
        for (i = 1 ; i <= num ; ++ i)
            addarc(M + F + i , M + F + num + i , 1);
        for (i = 1 ; i <= M + F ; ++ i) {
            int (*d1)[30] = dist[pos[i].first][pos[i].second];
            for (x = 1 ; x <= n ; ++ x)
                for (y = 1 ; y <= m ; ++ y) {
                    if (d1[x][y] == 1 << 30) continue;
                    LL q = (LL)d1[x][y] * T[i];
                    if (q <= mid) {
                        int w = (x - 1) * m + y;
                        if (i <= M)
                            addarc(i , M + F + w , 1);
                        else
                            addarc(M + F + num + w , i , 1);    
                    }
                }            
            
        }
        int res = 0;
        while (BFS()) {
            memcpy(cur , pre , sizeof(pre));
            res += DFS(s);
        }
        if (res == M)
            r = mid;
        else
            l = mid + 1;
    }
    if (l == (1LL << 42))
        puts("-1");
    else
        cout << l << endl;
}

int main() {
    work();
    return 0;
}