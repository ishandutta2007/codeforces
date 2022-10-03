#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N;
    ll M;cin>>N>>M;
    
    if(M==0) cout<<N<<" "<<N<<endl;
    else{
        cout<<max(0LL,N-M*2)<<" ";
        ll d=-1;
        for(ll i=1;;i++){
            if(i*(i-1)/2>=M){
                d=i;
                break;
            }
        }
        cout<<max(0LL,N-d)<<endl;
    }
    
}