#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int A,B,C;cin>>A>>B>>C;
        vector<vector<ll>> S(3,vector<ll>());
        
        for(int i=0;i<A;i++){
            ll x;cin>>x;
            S[0].push_back(x);
        }
        for(int i=0;i<B;i++){
            ll x;cin>>x;
            S[1].push_back(x);
        }
        for(int i=0;i<C;i++){
            ll x;cin>>x;
            S[2].push_back(x);
        }
        
        for(int i=0;i<3;i++){
            S[i].push_back(3000000000);
            S[i].push_back(-3000000000);
        }
        sort(all(S[0]));
        sort(all(S[1]));
        sort(all(S[2]));
        
        ll ans=INF;
        
        for(int i=0;i<3;i++){
            for(int j=1;j+1<S[i].size();j++){
                for(int k=0;k<3;k++){
                    if(i==k) continue;
                    
                    auto it=lower_bound(all(S[k]),S[i][j]);
                    
                    int l=3-i-k;
                    
                    ll a=S[i][j],c=*it;
                    
                    if(abs(c)==3000000000) continue;
                    
                    auto it2=lower_bound(all(S[l]),(a+c)/2);
                    if(abs((*it2))!=3000000000){
                        ll b=*it2;
                        ans=min(ans,(a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c));
                    }
                    it2--;
                    if(abs((*it2))!=3000000000){
                        ll b=*it2;
                        ans=min(ans,(a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c));
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}