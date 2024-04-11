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
const int mod=1000000007,MAX=100005;
const int INF=1<<30;
//const ll INF=1LL<<60;

ll cost(ll a,ll b){
    ll x=(a/b)*(a/b)*(b-a%b);
    ll y=(a/b+1)*(a/b+1)*(a%b);
    
    return x+y;
}

//ab

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    ll sum=0,ans=0;
    
    priority_queue<pair<ll,int>> PQ;
    
    for(int i=0;i<N;i++){
        B[i]=1;
        sum++;
        
        if(B[i]==A[i]) continue;
        ll a=cost(A[i],B[i]);
        ll b=cost(A[i],B[i]+1);
        
        PQ.push(mp(a-b,i));
    }
    
    while(sum<K){
        auto x=PQ.top();PQ.pop();
        int i=x.se;
        
        sum++;
        B[i]++;
        
        if(B[i]==A[i]) continue;
        ll a=cost(A[i],B[i]);
        ll b=cost(A[i],B[i]+1);
        
        PQ.push(mp(a-b,i));
    }
    
    for(int i=0;i<N;i++){
        ans+=cost(A[i],B[i]);
    }
    
    cout<<ans<<endl;
}