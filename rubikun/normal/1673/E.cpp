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
const int mod=1000000007,MAX=1<<20,INF=1<<30;

bool ans[MAX+5];

bool comb(int a,int b){
    //cout<<a<<" "<<b<<" "<<!((~a)&b)<<endl;
    if(a<b) return 0;
    if((~a)&b) return 0;
    else return 1;
}

bool dp[25][MAX+5];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<ll> B(N);
    for(int i=0;i<N;i++) cin>>B[i];
    
    for(int i=0;i<25;i++){
        for(int j=0;j<=N+3;j++){
            dp[i][j+1]=dp[i][j]^comb(N-i,j);
        }
    }
    
    for(int i=0;i<N;i++){
        ll sum=0;
        for(int j=i;j<N;j++){
            if(j>i) sum+=B[j];
            if(sum>=20) break;
            if((B[i]<<sum)>=(1LL<<20)) break;
            
            int d=(B[i]<<sum);
            
            int rem=i+N-1-j;
            if(i) rem--;
            if(j<N-1) rem--;
            
            int need=K;
            if(i) need--;
            if(j<N-1) need--;
            
            if(need>rem) continue;
            
            int s=dp[N-rem][rem+1]^dp[N-rem][max(0,need)];
            
            if(s) ans[d]^=1;
            
            /*
            for(int k=max(0,need);k<=rem;k++){
                if(comb(rem,k)) ans[d]^=1;
            }
             */
        }
    }
    
    for(int i=MAX-1;i>=0;i--){
        if(ans[i]){
            for(int j=i;j>=0;j--) cout<<ans[j];
            cout<<"\n";
            return 0;
        }
    }
    cout<<0<<"\n";
}