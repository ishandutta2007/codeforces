#include <bits/stdc++.h>
using namespace std;

char c[55][55];

int stx, sty;
int edx, edy;
int dr[4] = {0,1,2,3};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;
string num;

bool in_bound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool check(){
    int ix = stx, iy = sty;
    for(int i = 0; i < num.length(); i++){
        int ddx = dx[dr[num[i]-'0']], ddy = dy[dr[num[i]-'0']];
        ix += ddx;
        iy += ddy;
        if(!in_bound(ix, iy) || c[ix][iy] == '#') return false;
        if(c[ix][iy] == 'E') return true;
    }
    return false;
}

int main() {
    int cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(c[i][j] == 'S'){
                stx = i;
                sty = j;
            }
            else if(c[i][j] == 'E'){
                edx = i;
                edy = j;
            }
        }
    }

    getchar();
    getline(cin, num);
    do{
        if(check()) cnt++;
    } while(next_permutation(dr, dr+4));

    cout << cnt << endl;
}