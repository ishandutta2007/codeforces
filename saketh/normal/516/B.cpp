#include <iostream>
#include <queue>
using namespace std;

int N, M, D;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string a = "<>^v";
string b = "><v^";

char g[2005][2005];
int nbr[2005][2005];
queue<pair<int, int> > uni;

bool valid(int i, int j){
    if(i<0 || j<0) return false;
    if(i>=N || j>=M) return false;
    return true;
}

void inc(int i, int j){
    if(!valid(i, j)) return;
    nbr[i][j]++;
}

void dec(int i, int j){
    if(!valid(i, j)) return;
    nbr[i][j]--;
    if(g[i][j] != '.') return;
    if(nbr[i][j] == 1) uni.push(make_pair(i, j));
}

void used(int i, int j){
    for(int k=0; k<4; k++){
        dec(i+dir[k][0], j+dir[k][1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            cin >> g[i][j];
            if(g[i][j] == '.'){
                for(int k=0; k<4; k++)
                    inc(i+dir[k][0], j+dir[k][1]);                
                D++;
            }
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(nbr[i][j] == 1){
                uni.push(make_pair(i, j));
            }

    while(uni.size()){
        pair<int, int> loc = uni.front();
        uni.pop();
        int x = loc.first, y = loc.second;

        if(g[x][y] != '.') continue;
        for(int i=0; i<4; i++){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if(!valid(xx, yy)) continue;
            if(g[xx][yy] != '.') continue;
            
            g[x][y] = a[i];
            g[xx][yy] = b[i]; 
            used(x, y);
            used(xx, yy);

            D -= 2;
        }
    }

    if(D == 0){
        for(int i=0; i<N; i++){
           for(int j=0; j<M; j++)
              cout << g[i][j]; 
           cout << endl;
        }
    }
    else cout << "Not unique" << endl;
    
}