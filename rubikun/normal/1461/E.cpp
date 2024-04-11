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
const ll INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll k,l,r,t,x,y;cin>>k>>l>>r>>t>>x>>y;
    
    if(x==y){
        if(l<=k-x&&k-x<=r) cout<<"Yes\n";
        else if(l<=k+y&&k+y<=r) cout<<"Yes\n";
        else cout<<"No\n";
        
        return 0;
    }
    
    if(x>y){
        ll need=(k-(l+x-1)+x-y-1)/(x-y);
        if(need+1<=t) cout<<"No\n";
        else cout<<"Yes\n";
        
        return 0;
    }
    
    ll sumt=0,syuu=0;
    bool ok=true;
    
    while(sumt<t&&syuu<3000000){
        ll p=(k-l)/x;
        sumt+=p;
        if(sumt>=t) break;
        
        k-=p*x;
        if(k+y>r){
            ok=false;
            break;
        }
        k+=y;
        syuu++;
    }
    
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}