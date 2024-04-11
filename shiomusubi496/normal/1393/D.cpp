#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
signed main(){
    int H,W;
    cin>>H>>W;
    vector<string> A(H);
    for(string &S:A)cin>>S;
    vector<vector<int>> B(H,vector<int>(W,-1));
    queue<pair<int,int>> Q;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i==0 || i==H-1 || j==0 || j==W-1){
                B[i][j]=1;
                Q.push({i,j});
                continue;
            }
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(A[i][j]!=A[x][y]){
                    B[i][j]=1;
                    Q.push({i,j});
                    break;
                }
            }
        }
    }
    while(!Q.empty()){
        pair<int,int> p=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x=p.first+dx[i],y=p.second+dy[i];
            if(0<=x && x<H && 0<=y && y<W && A[p.first][p.second]==A[x][y] && B[x][y]==-1){
                B[x][y]=B[p.first][p.second]+1;
                Q.push({x,y});
            }
        }
    }
    int ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ans+=B[i][j];
        }
    }
    cout<<ans<<endl;
}