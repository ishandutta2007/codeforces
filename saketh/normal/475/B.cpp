#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
string h, v;

bool vis[32][32];
bool go(int i, int j){
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > bfs;
    bfs.push(make_pair(i, j));

    int tot = 0;
    while(!bfs.empty()){
        int x = bfs.front().first, y = bfs.front().second;
        bfs.pop();

        int vy = y + ((h[x]=='<')?-1:1);
        if(0<=vy && vy<M && !vis[x][vy]){
            vis[x][vy] = true;
            tot++;
            bfs.push(make_pair(x, vy));
        }
        int hx = x + ((v[y]=='^')?-1:1);
        if(0<=hx && hx<N && !vis[hx][y]){
            vis[hx][y] = true;
            tot++;
            bfs.push(make_pair(hx, y));
        }
    }
    return tot == N*M;
}

int main(){
    cin >> N >> M >> h >> v;
    bool good = true;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            good &= go(i, j);
    cout << (good?"YES":"NO") << endl;
}