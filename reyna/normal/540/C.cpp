//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 510;
string S[Maxn];
int mark[Maxn][Maxn];
int n,m;
int sx,sy,tx,ty;
bool check(int i,int j){
    if(i < 0 || j < 0 || i >= n || j >= m) return 0;
    return 1;
}
int dfs(int i,int j){
    if(!check(i,j)) return 0;
    if(i == tx && j == ty) return 1;
    if(S[i][j] == 'X') return 0;
    if(mark[i][j]) return 0;
    mark[i][j] = 1;
    int ret = 0;
    for(int l = -1;l < 2;l++){
        for(int r = -1;r < 2;r++){
            if(abs(r + l) == 1 && check(i + l,j + r)){
                ret += dfs(i + l,j + r);
            }
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n;i++)
        cin >> S[i];
    cin >> sx >> sy >> tx >> ty;
    --sx,--sy,--tx,--ty;
    int y = 0;
    for(int l = -1;l < 2;l++){
        for(int r = -1;r < 2;r++){
            if(abs(r + l) == 1 && check(tx + l,ty + r)){
                int i = tx + l,j = ty + r;
                if(sx == i && sy == j || S[i][j] == '.')
                    y++;
            }
        }
    }
    int x = 0;
    for(int l = -1;l < 2;l++){
        for(int r = -1;r < 2;r++){
            if(abs(r + l) == 1 && check(sx + l,sy + r)){
                x += dfs(sx + l,sy + r);
            }
        }
    }
    if(sx == tx && sy == ty && y >= 1) cout << "YES\n";
    else if(x >= 1 && S[tx][ty] == 'X') cout << "YES\n";
    else if(x >= 1 && y >= 2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}