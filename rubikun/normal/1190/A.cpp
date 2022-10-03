#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
     std::cin.rdbuf(in.rdbuf());*/
    
    ll N,M,K;cin>>N>>M>>K;
    vector<ll> P(M);
    for(int i=0;i<M;i++){
        cin>>P[i];
    }
    int cnt=0;
    ll nownum=1,nowpos=0;
    while(1){
        ll plus=0;
        for(ll i=nowpos;i<M;i++){
            if(P[i]<=nownum+K-1){
                plus++;
            }else break;
        }
        if(plus){
            nownum+=plus;
            nowpos+=plus;
            cnt++;
        }else{
            nownum+=(P[nowpos]-nownum)/K*K;
        }
        
        if(nowpos==M) break;
    }
    
    cout<<cnt<<endl;
    
    
}