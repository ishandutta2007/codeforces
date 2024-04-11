#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<pair<int,int>>> S(n);
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int x,y; cin >> x >> y;
            S[i].emplace_back(--x,--y);
        }
    }
    vector<vector<char>> ans(n,vector<char>(n,'.'));
    queue<pair<int,int>> que;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int x=S[i][j].first,y=S[i][j].second;
            if (x!=-2&&ans[x][y]!='X'){
                if (S[x][y]!=make_pair(x,y)){cout << "INVALID" << '\n'; return 0;}
                ans[S[i][j].first][S[i][j].second]='X';
                que.emplace(S[i][j].first,S[i][j].second);
            }
        }
    }
    const int dx[4]={1,0,-1,0};
    const int dy[4]={0,1,0,-1};
    string s="ULDR";
    while(!que.empty()){
        auto p=que.front(); que.pop();
        int x=p.first,y=p.second;
        for (int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx<0||n<=nx||ny<0||n<=ny) continue;
            if (ans[nx][ny]!='.') continue;
            if (S[nx][ny]!=S[x][y]) continue;
            ans[nx][ny]=s[i];
            que.emplace(nx,ny);
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (ans[i][j]!='.') continue;
            if (S[i][j].first!=-2){cout << "INVALID" << '\n'; return 0;}
            que.emplace(i,j);
            for (int k=0;k<4;++k){
                int nx=i+dx[k],ny=j+dy[k];
                if (nx<0||n<=nx||ny<0||n<=ny) continue;
                if (S[nx][ny]==S[i][j]) ans[i][j]=s[(k+2)%4];
            }
            if (ans[i][j]=='.'){cout << "INVALID" << '\n'; return 0;}
            while(!que.empty()){
                auto p=que.front(); que.pop();
                int x=p.first,y=p.second;
                for (int k=0;k<4;++k){
                    int nx=x+dx[k],ny=y+dy[k];
                    if (nx<0||n<=nx||ny<0||n<=ny) continue;
                    if (ans[nx][ny]!='.') continue;
                    if (S[nx][ny]!=S[x][y]) continue;
                    ans[nx][ny]=s[k];
                    que.emplace(nx,ny);
                }
            }
        }
    }
    cout << "VALID" << '\n';
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j) cout << ans[i][j];
        cout << '\n';
    }
}