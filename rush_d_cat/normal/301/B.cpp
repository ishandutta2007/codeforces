#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 502;
int n,d,a[N];
int x[N],y[N];

map< pair<int,int>, int > dis, mp;
struct Nod {
    int x,y,dis;
    bool operator<(const Nod&o)const{
        return dis>o.dis;
    }
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dijkstra() {
    priority_queue<Nod> q; 
    q.push((Nod){x[n],y[n],0});
    dis[make_pair(x[n], y[n])]=0; 
    while(q.size()) {
        Nod tmp = q.top(); q.pop();
        int X=tmp.x, Y=tmp.y;
        if(tmp.dis > d * (abs(x[1]-x[n])+abs(y[1]-y[n])) ) continue;
        if(tmp.dis > dis[make_pair(X,Y)] || X < -100 || X > 100 || Y < -100 || Y > 100) continue;
        // printf("# %d %d, %d\n", X, Y, tmp.dis);
        if(X == x[1] && Y == y[1]) break;
        for(int i=0;i<4;i++){
            int nx=X+dx[i], ny=Y+dy[i];
            int v = d + max(0, tmp.dis - mp[make_pair(X,Y)]);
            if(!dis.count(make_pair(nx,ny)) || dis[make_pair(nx,ny)] > v) {
                dis[make_pair(nx, ny)] = v;
                q.push((Nod){nx,ny,v});
            }
        }
    }
    printf("%d\n", dis[make_pair(x[1], y[1])]);
}
int main() {
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n-1;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=2;i<n;i++) mp[make_pair(x[i],y[i])] = a[i];
    dijkstra();
}