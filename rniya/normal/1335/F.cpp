#include <bits/stdc++.h>
using namespace std;

int n,m;
string dir="LRUD";
queue<pair<int,int>> que;

const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
const int ex[4]={0,0,1,-1};
const int ey[4]={1,-1,0,0};

void solve(vector<string> &c,vector<string> &s){
    vector<vector<int>> visited(n,vector<int>(m,0));
    set<pair<int,int>> turn;
    vector<pair<int,int>> cycle;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (!visited[i][j]){
                int x=i,y=j;
                while(!visited[x][y]){
                    visited[x][y]=1;
                    turn.emplace(x,y);
                    for (int k=0;k<4;++k) if (dir[k]==s[x][y]){
                        x+=dx[k],y+=dy[k]; break;
                    }
                }
                if (turn.count({x,y})) cycle.emplace_back(x,y);
                turn.clear();
            }
        }
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            visited[i][j]=0;
    vector<vector<int>> dist(n,vector<int>(m,-1));
    int ans1=0,ans2=0;
    for (auto p:cycle){
        int x=p.first,y=p.second,t=0;
        while(!visited[x][y]){
            visited[x][y]=1; ++t;
            for (int k=0;k<4;++k) if (dir[k]==s[x][y]){
                x+=dx[k],y+=dy[k]; break;
            }
        }
        vector<int> black(t,0);
        que.emplace(x,y);
        dist[x][y]=0;
        while(!que.empty()){
            auto p=que.front(); que.pop();
            int nowx=p.first,nowy=p.second;
            if (c[nowx][nowy]-'0'==0) black[dist[nowx][nowy]%t]=1;
            for (int k=0;k<4;++k){
                int nx=nowx+ex[k],ny=nowy+ey[k];
                if (nx<0||n<=nx||ny<0||m<=ny) continue;
                if (dist[nx][ny]!=-1) continue;
                if (s[nx][ny]==dir[k]){
                    dist[nx][ny]=dist[nowx][nowy]+1;
                    que.emplace(nx,ny);
                }
            }
        }
        ans1+=t;
        for (int i=0;i<t;++i) ans2+=black[i];
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> m;
        vector<string> c(n),s(n);
        for (int i=0;i<n;++i) cin >> c[i];
        for (int i=0;i<n;++i) cin >> s[i];
        solve(c,s);
    }
}