#include <bits/stdc++.h>
using namespace std;

const int N = (int)2005, INF = (int)1e9;
typedef pair<int, int> P;

struct Pp{
    int l, r, id;
    //Pp(){}
    Pp(int _l, int _r, int _id){l = _l, r = _r, id = _id;}
    bool operator < (const Pp &other) const {
        return l + r > other.l + other.r;
    }
};

int n,m,r,c,x,y;
char maze[N][N];
int dis[N*N];
int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};
int res = 0;

bool can(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '*';
}

int id(int x, int y){
    return x * m + y;
}

void dijkstra(){

    fill(dis, dis+N*N, INF);
    dis[id(r, c)] = 0;
    priority_queue<Pp> pque;
    pque.push({0, 0, id(r, c)});

    while(!pque.empty()){
        Pp p = pque.top(); pque.pop();
        int i = p.id;

        int dist = p.l + p.r;
        if(dist > dis[i]) continue;
        //cout << i/m + 1 << ", " << i%m + 1 << ": " << p.l << ", " << p.r << endl;
        for(int d = 0; d < 4; d++){
            int nl = (d == 2 ? p.l + 1 : p.l);
            int nr = (d == 3 ? p.r + 1 : p.r);
            int nx = i / m + dx[d], ny = i % m + dy[d];
            int cost = (nl + nr - p.l - p.r);
            if(can(nx, ny) && nl <= x && nr <= y && dis[i] + cost < dis[id(nx,ny)]){
                //cout << "??" << endl;
                if(dis[id(nx, ny)] == INF) res++;
                dis[id(nx,ny)] = cost + dis[i];
                pque.push({nl, nr, id(nx,ny)});
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
    r--, c--;
    getchar();
    for(int i = 0; i < n; i++) scanf("%s", &maze[i]);
    dijkstra();
    cout << res + 1 << endl;
}