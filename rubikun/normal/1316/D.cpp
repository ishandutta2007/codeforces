#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1<<30;
int N;
pair<int,int> S[MAX][MAX],to[MAX][MAX];
vector<int> dh={0,1,0,-1},dw={1,0,-1,0};
bool visited[MAX][MAX];
char ans[MAX][MAX];
string dir="LURDX";

void BFS(){
    queue<pair<int,int>> Q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(ans[i][j]=='X'){
                Q.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    
    while(!Q.empty()){
        pair<int,int> p=Q.front();Q.pop();
        int h=p.first,w=p.second;
        for(int k=0;k<4;k++){
            int toh=h+dh[k],tow=w+dw[k];
            if(toh<0||toh>=N||tow<0||tow>=N) continue;
            
            if(S[toh][tow]==S[h][w]&&visited[toh][tow]==0){
                ans[toh][tow]=dir[k];
                visited[toh][tow]=1;
                Q.push({toh,tow});
            }
        }
    }
}

void roop(int h,int w){
    for(int k=0;k<4;k++){
        int toh=h+dh[k],tow=w+dw[k];
        if(toh<0||toh>=N||tow<0||tow>=N) continue;
        if(visited[toh][tow]) continue;
        
        if(S[toh][tow]==S[h][w]&&visited[toh][tow]==0){
            ans[toh][tow]=dir[k];
            visited[toh][tow]=1;
            
            roop(toh,tow);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j].first>>S[i][j].second;
            S[i][j].first--;
            S[i][j].second--;
            if(S[i][j].first==i&&S[i][j].second==j){
                ans[i][j]='X';
            }
        }
    }
    
    BFS();
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(S[i][j].first==-2&&S[i][j].second==-2&&visited[i][j]==0){
                for(int k=0;k<4;k++){
                    int toh=i+dh[k],tow=j+dw[k];
                    if(toh<0||toh>=N||tow<0||tow>=N) continue;
                    
                    if(S[toh][tow]==S[i][j]){
                        ans[toh][tow]=dir[k];
                        ans[i][j]=dir[(k+2)%4];
                        
                        visited[toh][tow]=1;
                        visited[i][j]=1;
                        
                        roop(i,j);
                        roop(toh,tow);
                        
                        break;
                    }
                }
                if(visited[i][j]==0) ok=false;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            bool flag=false;
            for(int k=0;k<5;k++){
                if(ans[i][j]==dir[k]) flag=true;
            }
            if(!flag) ok=false;
        }
    }
    
    if(!ok){
        cout<<"INVALID"<<endl;
    }else{
        cout<<"VALID"<<endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<ans[i][j];
            }
            cout<<"\n";
        }
    }
    
}