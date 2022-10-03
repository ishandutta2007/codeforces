#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=500005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        bool ok=false;
        if(a==c&&a==b+d) ok=true;
        if(a==d&&a==b+c) ok=true;
        if(b==c&&b==a+d) ok=true;
        if(b==d&&b==a+c) ok=true;
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}