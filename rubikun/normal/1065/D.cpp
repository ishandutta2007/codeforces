#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=303,INF=1<<29;

pair<int,int> dis[MAX][MAX];
vector<int> dx={1,2,2,1,-1,-2,-2,-1},dy={2,1,-1,-2,-2,-1,1,2};

void floyd(){
    for(int k=0;k<MAX;k++){
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                dis[i][j]=min(dis[i][j],{dis[i][k].first+dis[k][j].first,dis[i][k].second+dis[k][j].second});
            }
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<vector<int>> A(N,vector<int>(N));
    pair<int,int> dp[N*N+1][3];
    
    for(int i=0;i<N*N+1;i++){
        for(int j=0;j<3;j++){
            dp[i][j]={INF,0};
        }
    }
    
    vector<pair<int,int>> where(N*N+1);
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            dis[i][j]={INF,0};
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
            where[A[i][j]]=make_pair(i,j);
        }
    }
    
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int k=0;k<8;k++){
                int x=a+dx[k],y=b+dy[k];
                if(x<0||x>=N||y<0||y>=N) continue;
                dis[a*10+b][x*10+y]={1,0};
            }
        }
    }
    
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int tox=0;tox<N;tox++){
                for(int toy=0;toy<N;toy++){
                    if(tox-a==toy-b||tox-a==b-toy){
                        dis[100+a*10+b][100+tox*10+toy]={1,0};
                        dis[100+tox*10+toy][100+a*10+b]={1,0};
                    }
                }
            }
        }
    }
    
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int to=0;to<N;to++){
                dis[200+a*10+b][200+a*10+to]={1,0};
                dis[200+a*10+b][200+to*10+b]={1,0};
            }
        }
    }
    
    for(int i=0;i<100;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k) dis[100*j+i][100*k+i]={0,0};
                else dis[100*j+i][100*k+i]={1,1};
            }
        }
    }
    
    floyd();
    
    for(int j=0;j<3;j++) dp[1][j]={0,0};
    
    for(int i=1;i<N*N;i++){
        int a=where[i].first,b=where[i].second,c=where[i+1].first,d=where[i+1].second;
        int from=a*10+b,to=c*10+d;
        for(int n=0;n<3;n++){
            for(int m=0;m<3;m++){
                dp[i+1][n]=min(dp[i+1][n],make_pair(dp[i][m].first+dis[m*100+from][n*100+to].first,dp[i][m].second+dis[m*100+from][n*100+to].second));
            }
        }
        //cout<<from<<" "<<to<<endl;
        //cout<<dp[i+1][0].first<<" "<<dp[i+1][1].first<<" "<<dp[i+1][2].first<<endl;
    }
    
    pair<int,int> ans={INF,INF};
    
    for(int j=0;j<3;j++){
        //cout<<j<<" "<<dp[N*N][j].first<<" "<<dp[N*N][j].second<<endl;
        ans=min(ans,dp[N*N][j]);
    }
    
    cout<<ans.first<<" "<<ans.second<<endl;
    
    //cout<<dis[25][100].first<<" "<<dis[25][100].second<<endl;
    
    
}