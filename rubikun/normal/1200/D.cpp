#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    int ans=0;
    
    vector<vector<int>> S(N+1,vector<int>(N+1)),yoko(N+1,vector<int>(N-K+1)),tate(N-K+1,vector<int>(N+1));
    vector<int> yokoall(N+1),tateall(N+1);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c;cin>>c;
            if(c=='W') S[i+1][j+1]=1;
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<=N;j++){
            S[i][j]+=S[i-1][j];
        }
    }
    for(int j=1;j<=N;j++){
        for(int i=0;i<=N;i++){
            S[i][j]+=S[i][j-1];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N-K+1;j++){
            if(S[i+1][j]+S[i][0]-S[i+1][0]-S[i][j]+S[i+1][N]+S[i][j+K]-S[i+1][j+K]-S[i][N]==N-K){
                yoko[i+1][j]=1;
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<N-K+1;j++){
            yoko[i][j]+=yoko[i-1][j];
        }
    }
    
    for(int j=0;j<N;j++){
        for(int i=0;i<N-K+1;i++){
            if(S[i][j+1]+S[0][j]-S[0][j+1]-S[i][j]+S[N][j+1]+S[i+K][j]-S[i+K][j+1]-S[N][j]==N-K){
                tate[i][j+1]=1;
            }
        }
    }
    
    for(int j=1;j<=N;j++){
        for(int i=0;i<N-K+1;i++){
            tate[i][j]+=tate[i][j-1];
        }
    }
    
    for(int i=0;i<N;i++){
        if(S[i+1][N]+S[i][0]-S[i+1][0]-S[i][N]==N) yokoall[i+1]=1;
    }
    
    for(int i=1;i<=N;i++) yokoall[i]+=yokoall[i-1];
    
    for(int j=0;j<N;j++){
        if(S[N][j+1]+S[0][j]-S[0][j+1]-S[N][j]==N) tateall[j+1]=1;
    }
    
    for(int j=1;j<=N;j++) tateall[j]+=tateall[j-1];
    
    for(int i=0;i<N-K+1;i++){
        for(int j=0;j<N-K+1;j++){
            int ok=0;
            ok+=yokoall[i]-yokoall[0]+yokoall[N]-yokoall[i+K];
            ok+=tateall[j]-tateall[0]+tateall[N]-tateall[j+K];
            
            ok+=yoko[i+K][j]-yoko[i][j];
            ok+=tate[i][j+K]-tate[i][j];
            
            ans=max(ans,ok);
        }
    }
    
    cout<<ans<<endl;
    
}