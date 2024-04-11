#include <bits/stdc++.h>
using namespace std;
int n , m;
char a[55][55];
bool f[55][55];
int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1};
void dfs(int x , int y , int d) {
    if (f[x][y]) {
        puts("Yes");
        exit(0);
    }
    f[x][y] = 1;
    for (int i = 0 ; i < 4 ; ++ i) {
        if (i != d && a[x + dx[i]][y + dy[i]] == a[x][y]) {
            dfs(x + dx[i] , y + dy[i] , i ^ 2);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> (a[i] + 1);
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            memset(f , 0 , sizeof(f));
            dfs(i , j , -1);
        }
    puts("No");
}