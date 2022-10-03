#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=105,INF=1<<30;
bool dp[MAX][MAX][MAX*MAX][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    set<int> SE;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        SE.insert(A[i]);
    }
    sort(all(A));
    
    if(si(SE)<=2){
        cout<<N<<endl;
        return 0;
    }
    
    int ans=0;
    
    dp[0][0][0][0]=dp[N][0][0][1]=1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=j*100;k++){
                if(!dp[i][j][k][0]) continue;
                dp[i+1][j][k][0]=1;
                dp[i+1][j+1][k+A[i]][0]=1;
            }
        }
    }
    
    for(int i=N;i>=1;i--){
        for(int j=0;j<=N-i;j++){
            for(int k=0;k<=j*100;k++){
                if(!dp[i][j][k][1]) continue;
                dp[i-1][j][k][1]=1;
                dp[i-1][j+1][k+A[i-1]][1]=1;
            }
        }
    }
    
    for(int t=1;t<=100;t++){
        int s=INF,g=-1;
        for(int i=0;i<N;i++){
            if(A[i]==t){
                chmin(s,i);
                chmax(g,i);
            }
        }
        //cout<<s<<" "<<g<<endl;
        for(int x=1;x<=g-s+1;x++){
            bool ok=true;
            for(int j=0;j<=x;j++){
                for(int k=0;k<=t*x;k++){
                    for(int d=0;x-d-j>=0&&d<x;d++){
                        if(dp[s][j][k][0]&&dp[g+1][x-d-j][t*(x-d)-k][1]){
                            ok=false;
                            break;
                        }
                    }
                    if(!ok) break;
                }
                if(!ok) break;
            }
            if(ok) chmax(ans,x);
        }
    }
    
    cout<<ans<<endl;
}