#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=85,INF=1<<30;
int dp[MAX][MAX][MAX][3];
int when[MAX][3];
pair<int,int> tim[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    
    int a=0,b=0,c=0;
    
    for(int i=0;i<N;i++){
        if(S[i]=='V'){
            when[a][0]=i;
            tim[i]={a,0};
            a++;
        }else if(S[i]=='K'){
            when[b][1]=i;
            tim[i]={b,1};
            b++;
        }else{
            when[c][2]=i;
            tim[i]={c,2};
            c++;
        }
    }
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            for(int k=0;k<MAX;k++){
                for(int l=0;l<3;l++){
                    dp[i][j][k][l]=INF;
                }
            }
        }
    }
    
    dp[0][0][0][2]=0;
    
    for(int i=0;i<N;i++){
        for(int x=0;x<N;x++){
            for(int y=0;y<N;y++){
                for(int l=0;l<3;l++){
                    if(dp[i][x][y][l]==INF) continue;
                    int z=i-x-y;
                    if(x>i||y>i||z>i) continue;
                    if(x>a||y>b||z>c) continue;
                    
                    if(x+1<=a){
                        int cnt=0;
                        for(int t=0;t<when[x][0];t++){
                            if(tim[t].se==1){
                                if(tim[t].fi>=y) cnt++;
                            }
                            if(tim[t].se==2){
                                if(tim[t].fi>=z) cnt++;
                            }
                        }
                        chmin(dp[i+1][x+1][y][0],dp[i][x][y][l]+cnt);
                        
                        //cout<<i<<" "<<x<<" "<<y<<" "<<cnt<<endl;
                    }
                    if(y+1<=b&&l!=0){
                        int cnt=0;
                        for(int t=0;t<when[y][1];t++){
                            if(tim[t].se==0){
                                if(tim[t].fi>=x) cnt++;
                            }
                            if(tim[t].se==2){
                                if(tim[t].fi>=z) cnt++;
                            }
                        }
                        chmin(dp[i+1][x][y+1][1],dp[i][x][y][l]+cnt);
                    }
                    if(z+1<=c){
                        int cnt=0;
                        for(int t=0;t<when[z][2];t++){
                            if(tim[t].se==0){
                                if(tim[t].fi>=x) cnt++;
                            }
                            if(tim[t].se==1){
                                if(tim[t].fi>=y) cnt++;
                            }
                        }
                        chmin(dp[i+1][x][y][2],dp[i][x][y][l]+cnt);
                    }
                }
            }
        }
    }
    
    int ans=INF;
    
    chmin(ans,dp[N][a][b][0]);
    chmin(ans,dp[N][a][b][1]);
    chmin(ans,dp[N][a][b][2]);
    
    cout<<ans<<endl;
    
}