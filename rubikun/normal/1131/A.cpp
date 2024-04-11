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
    
    ll w1,h1,w2,h2;cin>>w1>>h1>>w2>>h2;
    ll ans=0;
    ans+=(w1+2)*(h1+h2+2);
    ans-=h1*w1;
    ans-=h2*w2;
    ans-=(w1-w2)*h2;
    
    cout<<ans<<endl;
}