#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll L,R;cin>>L>>R;
    cout<<"YES"<<endl;
    for(ll i=L;i+1<=R;i+=2){
        cout<<i<<" "<<i+1<<"\n";
    }
}