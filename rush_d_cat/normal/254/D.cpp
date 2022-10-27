#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1202;
vector< pair<int,int> > vec;
vector< pair<int,int> > dot;
int n,m,d;
char s[N][N];
int dis[N][N], T;
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.second < b.second;
}
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool in(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=m && dis[x][y]==-1 && s[x][y] != 'X';
}
vector< pair<int,int> > gen(int x,int y) {
    vector< pair<int,int> > vis;
    dis[x][y]=0; vis.push_back(make_pair(x,y));
    queue< pair<int,int> > q; q.push(make_pair(x,y));
    while(q.size()) {
        pair<int,int> tmp = q.front(); q.pop();
        //printf("%d, %d , dis=%d\n", tmp.first,tmp.second,dis[tmp.first][tmp.second]);
        for(int i=0;i<4;i++){
            int nx=tmp.first + dx[i];
            int ny=tmp.second + dy[i];
            if (in(nx,ny)) {
                if (dis[tmp.first][tmp.second] + 1 <= d) {
                    dis[nx][ny] = dis[tmp.first][tmp.second] + 1;
                    q.push(make_pair(nx,ny)); vis.push_back(make_pair(nx,ny));
                }
            }
        }
    }
    for(auto p: vis) {
        dis[p.first][p.second] = -1;
    }
    return vis;
}
void ok(int x1,int y1,int x2,int y2) {
    if(s[x1][y1] == 'X' || s[x2][y2] == 'X') return;
    vector< pair<int,int> > vis;
    dis[x1][y1]=0,dis[x2][y2]=0; vis.push_back(make_pair(x1,y1)); vis.push_back(make_pair(x2,y2));
    queue< pair<int,int> > q; q.push(make_pair(x1,y1)); q.push(make_pair(x2,y2));
    while(q.size()) {
        pair<int,int> tmp = q.front(); q.pop();
        //printf("%d, %d , dis=%d\n", tmp.first,tmp.second,dis[tmp.first][tmp.second]);
        for(int i=0;i<4;i++){
            int nx=tmp.first + dx[i];
            int ny=tmp.second + dy[i];
            if (in(nx,ny)) {
                if (dis[tmp.first][tmp.second] + 1 <= d) {
                    dis[nx][ny] = dis[tmp.first][tmp.second] + 1;
                    q.push(make_pair(nx,ny)); vis.push_back(make_pair(nx,ny));
                }
            }
        }
    }
    sort(vis.begin(),vis.end()); vis.erase(unique(vis.begin() ,vis.end()), vis.end());
    int ans=0;
    for(auto p: vis) {
        if (s[p.first][p.second] == 'R') ans++;
        dis[p.first][p.second] = -1;
    }
    if (ans == vec.size()) {
        
        if (x1==x2 && y1==y2) {
            for(auto p: dot) {
                if (p!=make_pair(x1,y1)) {
                    x2=p.first, y2=p.second;
                    break;
                }
            }
        }
        
        printf("%d %d %d %d\n", x1,y1,x2,y2); exit(0);
    }
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dis,-1,sizeof(dis));
 
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        if(s[i][j] == 'R') vec.push_back(make_pair(i,j));
        if(s[i][j] == '.' || s[i][j] == 'R') dot.push_back(make_pair(i,j));
    }
    if(dot.size() < 2) return !printf("-1\n");
    if (vec.size() == 0) {
        printf("%d %d %d %d\n", dot[0].first,dot[0].second,dot[1].first,dot[1].second);
        return 0;
    } 
 
    int dx,dy;
    int mnx,mxx,mny,mxy;
 
    sort(vec.begin(), vec.end());
    vector< pair<int,int> > v1 = gen(vec[0].first, vec[0].second);
    vector< pair<int,int> > v2 = gen(vec[vec.size()-1].first, vec[vec.size()-1].second);
    for(auto p1: v1) for(auto p2: v2) ok(p1.first,p1.second,p2.first,p2.second);
    dx=vec[vec.size()-1].first - vec[0].first; mnx = vec[0].first, mxx = vec[vec.size()-1].first;
 
    sort(vec.begin(), vec.end(), cmp);
    v1 = gen(vec[0].first, vec[0].second);
    v2 = gen(vec[vec.size()-1].first, vec[vec.size()-1].second);
    for(auto p1: v1) for(auto p2: v2) ok(p1.first,p1.second,p2.first,p2.second);
    dy=vec[vec.size()-1].second - vec[0].second; mny=vec[0].second, mxy = vec[vec.size()-1].second;
 
    if (dx > 20 || dy > 20) return !printf("-1\n");
    for(int x1=mnx;x1<=mxx;x1++)for(int y1=mny;y1<=mxy;y1++)
    for(int x2=mnx;x2<=mxx;x2++)for(int y2=mny;y2<=mxy;y2++) 
    {
        ok(x1,y1,x2,y2);
    }
    printf("-1\n");
}