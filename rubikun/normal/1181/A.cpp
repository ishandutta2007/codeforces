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
    
    ll x,y,z;cin>>x>>y>>z;
    cout<<(x+y)/z<<" ";
    if(x/z+y/z==(x+y)/z) cout<<0<<endl;
    else{
        cout<<min(z-x%z,z-y%z)<<endl;
    }
}