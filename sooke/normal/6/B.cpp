#include <iostream>

using namespace std;

int n , m , ans = 0;
char c[101][101] , pc;
bool f[101][101];

void BuildCache(int x , int y , char nc){
    if(x <= 0 || x > n || y <= 0 || y > m)
        return;
    if(f[x][y] || c[x][y] != nc)
        return;
    f[x][y] = true;
    BuildCache(x + 1 , y , nc);
    BuildCache(x - 1 , y , nc);
    BuildCache(x , y + 1 , nc);
    BuildCache(x , y - 1 , nc);
}
void Dfs(int x , int y , char nc){
    if(x <= 0 || x > n || y <= 0 || y > m)
        return;
    if(f[x][y] || c[x][y] == '.')
        return;
    if(c[x][y] != nc){
        ans++;
        BuildCache(x , y , c[x][y]);
        return;
    }
    f[x][y] = true;
    Dfs(x + 1 , y , nc);
    Dfs(x - 1 , y , nc);
    Dfs(x , y + 1 , nc);
    Dfs(x , y - 1 , nc);
}

int main(){
    cin >> n >> m >> pc;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> c[i][j];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(c[i][j] == pc)
                Dfs(i , j , pc);
    cout << ans;
    return 0;
}