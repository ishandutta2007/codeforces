#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll a,b;cin>>a>>b;
        ll x=1,y=2*b-1,z=(x+y)*b/2;
        if(a>=z&&(a&1)==(z&1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}