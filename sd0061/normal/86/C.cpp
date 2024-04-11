#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;
const int Q = 1e9 + 9;
int nodecnt;
int u[N][4] , f[N] , len[N];
queue<int> q;

inline int id(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
    return -1;
}

void insert(char str[] , int p) {
    int x = 0;
    for (int i = 0 ; str[i] ; ++ i) {
        int c = id(str[i]);
        if (!u[x][c])
            u[x][c] = nodecnt ++;
        x = u[x][c];
    }
    len[x] = p;
}
void getFail() {
    for (int i = 0 ; i < 4 ; ++ i)
        if (u[0][i])
            f[u[0][i]] = 0 , q.push(u[0][i]);
    while (!q.empty()) {
        int x = q.front() ; q.pop();
        for (int i = 0 ; i < 4 ; ++ i) {
            int y = u[x][i];
            if (!y) {u[x][i] = u[f[x]][i]; continue;}
            q.push(y); int j = f[x];
            while (j && !u[j][i]) j = f[j];
            f[y] = u[j][i] , len[y] = max(len[y] , len[f[y]]);
        }
    }
}
int n , m;
char s[N];
int F[1005][105][15];

inline void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}
void work() {
    int i , j , k , l;
    scanf("%d%d",&n,&m);
    nodecnt = 1;
    for (i = 0 ; i < m ; ++ i) {
        scanf("%s" , s);
        insert(s , strlen(s));
    }
    getFail();
    F[0][0][0] = 1;
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j < nodecnt ; ++ j)
            for (k = 0 ; k < 10 ; ++ k) {
                if (!F[i][j][k])
                    continue;
                for (l = 0 ; l < 4 ; ++ l) {
                    int x = u[j][l];
                    int y = len[x];
                    if (y > k)
                        add(F[i + 1][x][0] , F[i][j][k]);
                    else if (k != 9)
                        add(F[i + 1][x][k + 1] , F[i][j][k]);    
                }
            }
    int res = 0;
    for (i = 0 ; i < nodecnt ; ++ i)
        add(res , F[n][i][0]);
    cout << res << endl; 
}


int main() {
    work();
    return 0;
}