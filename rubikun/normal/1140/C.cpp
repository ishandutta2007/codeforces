#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000003,MAX=200001,INF=1<<30;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second==b.second) return a.first>b.first;
    return a.second>b.second;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    vector<pair<ll,ll>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first>>A[i].second;
    }
    
    sort(all(A),compare);
    
    priority_queue<ll,vector<ll>,greater<ll>> PQ;
    
    ll ans=0,sum=0;
    
    for(int i=0;i<K;i++){
        sum+=A[i].first;
        ans=max(ans,sum*A[i].second);
        PQ.push(A[i].first);
    }
    
    for(int i=K;i<N;i++){
        sum+=A[i].first;
        PQ.push(A[i].first);
        ll a=PQ.top();PQ.pop();
        sum-=a;
        ans=max(ans,sum*A[i].second);
    }
    
    cout<<ans<<endl;
}