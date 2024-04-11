#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
#define N 205
int n , m , K;
int Ll , L[N];
int Rl , R[N];
int a[N];

struct Acm {
    int nodecnt;
    int u[N][20] , f[N] , val[N];
    inline int newnode() {
        val[nodecnt] = 0 , memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
        return nodecnt ++;
    }
    void clear() {
        nodecnt = 0 , newnode();
    }
    void insert(int *s , int len , int weight) {
        int x = 0;
        for (int i = 0 ; i < len ; ++ i) {
            int c = s[i];
            if (!u[x][c])
                u[x][c] = newnode();
            x = u[x][c];
        }
        val[x] += weight;
    }
    void getFail() {
        queue<int> Q;
        for (int i = 0 ; i < m ; ++ i)
            if (u[0][i])
                f[u[0][i]] = 0 , Q.push(u[0][i]);
        while (!Q.empty()) {
            int x = Q.front() ; Q.pop();
            for (int i = 0 ; i < m ; ++ i) {
                int y = u[x][i];
                if (!y) {
                    u[x][i] = u[f[x]][i];
                    continue;
                }
                Q.push(y); int j = f[x];
                while (j && !u[j][i]) j = f[j];
                f[y] = u[j][i] , val[y] += val[f[y]];
            }
        }
    }
}T;

int f[N][N][505] , Q = 1e9 + 7;
int digit[N] , tmp;
inline void add(int& x , int y) {
    x += y;
    if (x >= Q)
        x -= Q;
}

int cnt(int pos , int x , int tot , bool doing , bool large) {
    if (pos == -1)
        return 1;
    if (!doing && large && ~f[pos][x][tot])
        return f[pos][x][tot];
    int end = doing ? digit[pos] : m - 1 , ans = 0;
    for (int i = 0 ; i <= end ; ++ i) {
        if (!large && !i)
            add(ans , cnt(pos - 1 , x , tot , doing && (i == end) , 0));
        else {
            int y = T.u[x][i];
            if (tot + T.val[y] <= K)
                add(ans , cnt(pos - 1 , y , tot + T.val[y] , doing && (i == end) , 1));
        }
    }
    if (!doing && large) f[pos][x][tot] = ans;
    return ans;
}

int cal() {
    memset(f , -1 , sizeof(f));
    return cnt(tmp - 1 , 0 , 0 , 1 , 0);
}

void work() {
    int i , j , x , y;
    T.clear();
    scanf("%d%d%d",&n,&m,&K);
    scanf("%d" , &Ll);
    for (i = 0 ; i < Ll ; ++ i)
        scanf("%d",&L[i]);
    reverse(L , L + Ll);
    i = 0 , -- L[i];
    while (L[i] < 0) {
        L[i ++] += m;
        -- L[i];
    }
    while (Ll > 1 && !L[Ll - 1])
        -- Ll;
    scanf("%d" , &Rl);
    for (i = 0 ; i < Rl ; ++ i)
        scanf("%d",&R[i]);
    reverse(R , R + Rl);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&y);
        for (j = 0 ; j < y ; ++ j)
            scanf("%d" , &a[j]);
        scanf("%d",&x);
        T.insert(a , y , x);
    }
    T.getFail();
    memcpy(digit , R , sizeof(digit)) , tmp = Rl;
    int ans = cal();
    memcpy(digit , L , sizeof(digit)) , tmp = Ll;
    ans += (Q - cal()) , ans %= Q;
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}