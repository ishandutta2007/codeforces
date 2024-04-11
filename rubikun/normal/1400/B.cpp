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
const int mod=1000000007,MAX=2005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll p,f,a,b,c,d;cin>>p>>f>>a>>b>>c>>d;
        
        if(c>d){
            swap(a,b);
            swap(c,d);
        }
        ll ans=0;
        
        for(ll i=0;i<=a;i++){
            if(i*c>p) break;
            ll j=(p-i*c)/d;
            chmin(j,b);
            
            ll sum=i+j;
            
            ll re=f;
            if((a-i)*c<=re){
                re-=(a-i)*c;
                sum+=(a-i);
                
                sum+=min(b-j,re/d);
            }else{
                sum+=re/c;
            }
            
            chmax(ans,sum);
        }
        
        cout<<ans<<"\n";
    }
}