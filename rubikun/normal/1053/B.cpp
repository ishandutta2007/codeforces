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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),sum(N+1),oddcnt(N+1),evencnt(N+1);
    for(int i=0;i<N;i++){
        ll x;cin>>x;
        for(int j=62;j>=0;j--){
            if(x&(1LL<<j)) A[i]++;
        }
        
        sum[i+1]=sum[i]+A[i];
        
        if(sum[i+1]&1) oddcnt[i+1]=1;
        else evencnt[i+1]=1;
        oddcnt[i+1]+=oddcnt[i];
        evencnt[i+1]+=evencnt[i];
    }
    
    ll ans=0;
    
    for(int j=1;j<=min(128,N);j++){
        int K=j;
        vector<int> B(N-K+1);//B[i]i~i+K-1
        deque<int> deq(N);
        int s=0,t=0;
        for(int q=0;q<N;q++){
            while(s<t&&A[deq[t-1]]<=A[q]) t--;
            deq[t]=q;
            t++;
            
            if(q-K+1>=0){
                B[q-K+1]=A[deq[s]];
                if(deq[s]==q-K+1) s++;
            }
        }
        
        for(int i=0;i<N-K+1;i++){
            int diff=sum[i+j]-sum[i];
            if(diff&1) continue;
            if(B[i]*2<=diff) ans++;
        }
        
    }
    
    for(int i=0;i<N;i++){
        if(sum[i]&1){
            int l=min(N,i+128);
            ans+=oddcnt[N]-oddcnt[l];
        }else{
            int l=min(N,i+128);
            ans+=evencnt[N]-evencnt[l];
        }
    }
    
    cout<<ans<<endl;
}