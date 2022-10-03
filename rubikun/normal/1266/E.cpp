#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N+1),cnt(N+1);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i+1];
        sum+=A[i+1];
    }
    map<pair<int,int>,int> app;
    
    int Q;cin>>Q;
    while(Q--){
        int s,t,u;cin>>s>>t>>u;
        
        if(app[{s,t}]==0){
            if(u!=0){
                app[{s,t}]=u;
                if(cnt[u]<A[u]){
                    sum--;
                }
                cnt[u]++;
            }
        }else{
            int v=app[{s,t}];
            if(cnt[v]<=A[v]){
                sum++;
            }
            cnt[v]--;
            
            app[{s,t}]=u;
            
            if(u!=0){
                if(cnt[u]<A[u]){
                    sum--;
                }
                cnt[u]++;
            }
        }
        
        cout<<sum<<endl;
    }
}