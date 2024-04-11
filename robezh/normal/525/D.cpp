#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n,m;
string s[N];
int dx[2][2][3] = {{{-1, -1, 0}, {-1, -1, 0}}, {{1, 1, 0}, {1, 1, 0}}},
        dy[2][2][3] = {{{0, -1, -1}, {0, 1, 1}}, {{0, -1, -1}, {0, 1, 1}}};

bool good(int i, int j){
    if(!(i >= 0 && i + 1 < n && j >= 0 && j + 1 < m)) return false;
    int cnt_s = (s[i][j] == '*') + (s[i+1][j] == '*') + (s[i][j+1] == '*') + (s[i+1][j+1] == '*');
    return cnt_s == 1;
}

void dfs(int i, int j){
    for(int t = 0; t < 2; t++){
        for(int k = 0; k < 2; k++){
            if(s[i+t][j+k] == '*'){
                s[i+t][j+k] = '.';
                for(int x = 0; x < 3; x++){
                    int nx = i + dx[t][k][x], ny = j + dy[t][k][x];
                    if(good(nx, ny)) dfs(nx, ny);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            if(good(i, j)) dfs(i, j);
        }
    }
    for(int i = 0; i < n; i++) cout << s[i] << endl;
}