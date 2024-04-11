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
const ll INF=1LL<<40;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        if(c+1<=d){
            if(a>b*c) cout<<-1<<"\n";
            else cout<<a<<"\n";
        }else if(a>b*c) cout<<-1<<"\n";
        else if(a-(d-1)*b<=0) cout<<a<<"\n";
        else{
            ll ans=a,sum=0;
            
            ll lim=(a+b-1)/b;
            lim=lim/d;
            
            if(lim) lim--;
            
            sum=(a+b)*lim-lim*(lim+1)/2*b*d;
            chmax(ans,sum);
            
            for(ll l=(lim+1)*d;l<=(lim+4)*d;l+=d){
                if(l>c+1) l=c+1;
                chmax(ans,sum+a-((l+d-1)/d-1)*b);
                sum+=a;
                sum-=(l-1)*b;
                
                if(l==c+1){
                    chmax(ans,sum+a-((l+d-1)/d-1)*b);
                    break;
                }
            }
            
            cout<<ans<<"\n";
        }
    }
}