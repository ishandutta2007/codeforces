#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100006,INF=1<<30;

int H,W;

vector<int> dh={-1,-1,0,1,1,1,0,-1};
vector<int> dw={0,1,1,1,0,-1,-1,-1};

void preBFS(vector<vector<char>> &ma,vector<vector<vector<int>>> &can){
    vector<vector<int>> dis(H+2,vector<int>(W+2,INF));
    queue<pair<int,int>> Q;
    for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
            if(ma[i][j]=='.'){
                dis[i][j]=-1;
                Q.push({i,j});
            }
        }
    }
    
    while(!Q.empty()){
        pair<int,int> p=Q.front();Q.pop();
        int a=p.first,b=p.second;
        for(int k=0;k<8;k++){
            if(a+dh[k]<0||a+dh[k]>=H+2||b+dw[k]<0||b+dw[k]>=W+2) continue;
            if(dis[a+dh[k]][b+dw[k]]!=INF) continue;
            dis[a+dh[k]][b+dw[k]]=dis[a][b]+1;
            //can[i][j][8]=dis[i][j];
            Q.push({a+dh[k],b+dw[k]});
        }
    }
    
    for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
            can[i][j][8]=dis[i][j];
        }
    }
}

bool BFS(int s,vector<vector<char>> &ma,vector<vector<vector<int>>> &can){
    vector<vector<int>> dis(H+2,vector<int>(W+2,-1));
    queue<pair<int,int>> Q;
    for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
            if(can[i][j][8]>=s){
                dis[i][j]=s;
                if(s>=1) Q.push({i,j});
            }
        }
    }
    
    while(!Q.empty()){
        pair<int,int> p=Q.front();Q.pop();
        int a=p.first,b=p.second;
        for(int k=0;k<8;k++){
            if(a+dh[k]<0||a+dh[k]>=H+2||b+dw[k]<0||b+dw[k]>=W+2) continue;
            if(dis[a+dh[k]][b+dw[k]]!=-1) continue;
            dis[a+dh[k]][b+dw[k]]=dis[a][b]-1;
            if(dis[a+dh[k]][b+dw[k]]>=1) Q.push({a+dh[k],b+dw[k]});
        }
    }
    
    bool ok=true;
    
    for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
            if(ma[i][j]=='.'&&dis[i][j]>=0) ok=false;
            if(ma[i][j]=='X'&&dis[i][j]==-1) ok=false;
            
            if(!ok) return false;
        }
    }
    
    return true;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>H>>W;
    vector<vector<vector<int>>> can(H+2,vector<vector<int>>(W+2,vector<int>(9,-1)));
    
    vector<vector<char>> ma(H+2,vector<char>(W+2,'.'));
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>ma[i][j];
        }
    }
    
    preBFS(ma,can);
    
    int left=0,right=5000;
    
    while(right-left>1){
        int mid=(left+right)/2;
        bool it=BFS(mid,ma,can);
        if(it) left=mid;
        else right=mid;
    }
    
    for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
            if(ma[i][j]=='.') continue;
            if(can[i][j][8]>=left) ma[i][j]='X';
            else ma[i][j]='.';
        }
    }
    cout<<left<<"\n";
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cout<<ma[i][j];
        }
        cout<<"\n";
        //printf("\n");
    }
}