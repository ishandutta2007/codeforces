#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<ll> S(N);
        for(int i=0;i<N;i++) cin>>S[i];
        vector<vector<int>> G(N);
        
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[b].push_back(a);
        }
        
        for(int i=0;i<N;i++) sort(all(G[i]));
        
        map<vector<int>,ll> MA;
        
        for(int i=0;i<N;i++){
            if(G[i].size()>=1) MA[G[i]]+=S[i];
        }
        ll ans=0;
        
        for(auto it=MA.begin();it!=MA.end();it++){
            ans=gcd((*it).second,ans);
            
            //cout<<(*it).second<<endl;
        }
        
        cout<<ans<<"\n";
    }
}