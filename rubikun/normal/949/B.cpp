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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll M;int Q;cin>>M>>Q;
    while(Q--){
        ll N=M;
        ll x;cin>>x;
        ll plus=0;
        x--;
        bool check=false;
        while(1){
            if(check){
                if(x&1LL){
                    cout<<x/2+1+plus<<"\n";
                    break;
                }else{
                    plus+=N/2;
                    if(N&1LL){
                        check=false;
                    }else{
                        check=true;
                    }
                    N=(N+1)/2;
                    x/=2;
                }
            }else{
                if(!(x&1LL)){
                    cout<<x/2+1+plus<<"\n";
                    break;
                }else{
                    plus+=(N+1)/2;
                    if(N&1LL){
                        check=true;
                    }else{
                        check=false;
                    }
                    N/=2;
                    x/=2;
                }
            }
        }
        
    }
}