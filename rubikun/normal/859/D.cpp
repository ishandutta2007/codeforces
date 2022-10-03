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
const int mod=1000000007,MAX=65,INF=1<<30;

#define ld long double
ld win[MAX][MAX];
ld P[8][MAX];
int K,N;

bool seen[MAX][MAX][8];
ld dp[MAX][MAX][8];

ld solve(int l,int r,int maxi){
    if(seen[l][r][maxi]) return dp[l][r][maxi];
    if(l+1==r){
        return P[maxi][l];
    }
    seen[l][r][maxi]=true;
    ld res=0;
    int def=0;
    for(int k=0;k<10;k++){
        if((r-l)&(1<<k)) def=k-1;
    }
    chmax(res,solve(l,(l+r)/2,maxi)+solve((l+r)/2,r,def));
    chmax(res,solve(l,(l+r)/2,def)+solve((l+r)/2,r,maxi));
    
    return dp[l][r][maxi]=res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>K;
    N=(1<<K);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int x;cin>>x;
            win[i][j]=x;
            win[i][j]/=100;
        }
        P[0][i]=1;
    }
    
    for(int t=1;t<=K;t++){
        for(int i=0;i<N;i++){
            ld sum=0;
            int l=i&(~((1<<(t-1))-1));
            l^=(1<<(t-1));
            int r=l+(1<<(t-1));
            for(int j=l;j<r;j++){
                sum+=P[t-1][j]*win[i][j];
            }
            sum*=P[t-1][i];
            P[t][i]=sum;
            
            //cout<<t<<" "<<i<<" "<<sum<<endl;
        }
    }
    for(int i=0;i<N;i++) P[0][i]=0;
    for(int t=1;t<=K;t++){
        for(int i=0;i<N;i++){
            P[t][i]*=(1<<(t-1));
            P[t][i]+=P[t-1][i];
        }
    }
    
    cout<<fixed<<setprecision(25)<<solve(0,N,K)<<endl;
}