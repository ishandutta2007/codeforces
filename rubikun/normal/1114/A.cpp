#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int x,y,z,a,b,c;cin>>x>>y>>z>>a>>b>>c;
    bool ok=true;
    
    if(x>a) ok=false;
    a-=x;
    b+=a;
    
    if(y>b) ok=false;
    b-=y;
    c+=b;
    
    if(z>c) ok=false;
    
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}