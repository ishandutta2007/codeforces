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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        ll ans=0;
        vector<int> check(N+1);
        for(ll i=1;i<=N;i++){
            for(ll j=i;j<=N;j+=i){
                if(S[j-1]=='0'){
                    if(!check[j]){
                        ans+=i;
                        check[j]=true;
                    }
                }else{
                    break;
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}