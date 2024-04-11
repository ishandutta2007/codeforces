#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,P,W,D;cin>>N>>P>>W>>D;
    ll a=-1,b=-1;
    for(ll i=0;i<D;i++){
        if((W*i)%D==P%D){
            a=i;
            b=(P-W*i)/D;
            break;
        }
    }
    
    if(b<0){
        cout<<-1<<endl;
        return 0;
    }
    
    ll rem=b/W;
    a+=rem*D;
    b-=rem*W;
    
    if(a+b<=N){
        cout<<a<<" "<<b<<" "<<N-a-b<<endl;
    }else{
        cout<<-1<<endl;
    }
}