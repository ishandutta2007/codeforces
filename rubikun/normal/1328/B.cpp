#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,K;cin>>N>>K;
        K=N*(N-1)/2-K+1;
        
        ll now=0;
        for(ll i=1;i<=N-1;i++){
            if(now+N-i<K) now+=N-i;
            else{
                string ans;
                for(int j=1;j<i;j++) ans+='a';
                ans+='b';
                for(int j=1;j<K-now;j++) ans+='a';
                ans+='b';
                while(ans.size()<N) ans+='a';
                
                cout<<ans<<"\n";
                break;
            }
        }
    }
}