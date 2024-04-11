#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=4005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--){
        ll a,b,c;cin>>a>>b>>c;
        if(max({a,b,c})*2<=a+b+c+1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}