#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,K;cin>>N>>K;
    for(ll i=1;i<=100000;i++){
        if(i*i+3*i-2*N-2*K==0){
            cout<<N-i<<endl;
            break;
        }
    }
}