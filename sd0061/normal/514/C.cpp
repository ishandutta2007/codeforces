#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 600005;

int n , m;
int cnt;
int u[N][3];
bool vis[N];

char str[N];

bool dfs(int x , int d , int k) {
    if (d == n && vis[x] && k == 1)
        return 1;
    if (d >= n)
        return 0;
    int c = str[d] - 'a';
    if (u[x][c]) {
        if (dfs(u[x][c] , d + 1 , k))
            return 1;
    } 
    if (k) return 0;
    for (int i = 0 ; i < 3 ; ++ i) {
        if (c == i) continue;
        if (dfs(u[x][i] , d + 1 , k + 1))
            return 1;
    }
    
    return 0;
}

void work() {
    int i , j , x;
    scanf("%d%d",&n,&m);
    cnt = 1;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        x = 1;
        for (j = 0 ; str[j] ; ++ j) {
            int c = str[j] - 'a';
            if (!u[x][c])
                u[x][c] = ++ cnt;
            x = u[x][c];
        }
        vis[x] = 1;
    }
    for (i = 0 ; i < m ; ++ i) {
        scanf("%s" , str);
        n = strlen(str);
        puts(dfs(1 , 0 , 0) ? "YES" : "NO");
    }
    
}

int main() {
//    freopen("1" , "r" , stdin);

    work();
    return 0;
}