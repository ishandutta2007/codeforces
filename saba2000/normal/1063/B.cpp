#include<bits/stdc++.h>
using namespace std;
int dist[2009][2009];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int l[4] ={1,1,0,0};
string a[2009];
int n, m;
bool C(int x, int y){
    if(x >=0 && x < n && y>=0 && y < m && a[x][y]!='*') return 1;
    return 0;
}
main(){
    cin >> n >> m;
    int r, c, x, y;
    cin>>r>>c>>x>>y;
    r--; c--;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    deque <pair<int,int> > Q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j] = 1e9;
    dist[r][c] = 0;
    Q.push_back({r,c});

    while (!Q.empty())
    {
        pair<int,int> v = Q.front();
        int x = v.first, y = v.second;
        Q.pop_front();
        for(int i=  0; i < 4; i++){
            if(!C(x+dx[i],y+dy[i])) continue;
            int E = l[i];
            int nx = x+dx[i], ny = y+dy[i];
            if (dist [nx][ny] > dist[x][y] + E)
            {
                dist [nx][ny] = dist[x][y] + E;
                if (E == 0)
                    Q.push_front({nx, ny});
                else
                    Q.push_back({nx, ny});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!C(i,j) || dist[i][j] == 1e9) continue;
            int D = dist[i][j];
            int d1 = j - c;
            //2x-D = d1
            int y1 = (D + d1)/2;
            int x1 = (D - d1)/2;
            if(x1 <= x && y1 <= y) ans++;
        }
    }
    cout<<ans<<endl;
}