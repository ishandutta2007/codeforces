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
const int mod=1000000007,MAX=500005,INF=1<<30;

ll dp[MAX],rui[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    if(N==1){
        cout<<0<<endl;
        return 0;
    }
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    reverse(all(A));
    
    ll nowsum=0;
    int ng=0;
    for(int i=0;i<N-1;i++){
        nowsum+=A[i];
        if(nowsum<0) ng++;
    }
    if(nowsum>=0||ng<=K){
        nowsum=0;
        ll ans=0;
        for(int i=0;i<N-1;i++){
            nowsum+=A[i];
            ans+=max(0LL,nowsum);
        }
        cout<<ans<<endl;
        return 0;
    }
    
    N=N-1-K;
    
    K++;
    
    while(si(A)>N) A.pop_back();
    
    reverse(all(A));
    
    ll ans=-(1LL<<60);
    
    ll sum=0;
    
    dp[0]=0;
    rui[0]=0;
    for(int i=1;i<=N;i++){
        dp[i]=dp[i-1]+A[i-1]*i;
        rui[i]=rui[i-1]+A[i-1];
    }
    
    for(int i=0;i<N;i++){
        chmax(ans,sum+dp[N]-dp[i]-(rui[N]-rui[i])*(i-i/K));
        sum+=A[i]*(i/K+1);
    }
    
    cout<<ans<<endl;
}