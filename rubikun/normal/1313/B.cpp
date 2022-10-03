#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,X,Y;cin>>N>>X>>Y;
        
        if(X+Y<1+N){
            cout<<1<<" ";
        }else{
            cout<<min(N,(X+Y+1-N))<<" ";
        }
        
        if(X+Y>=1+N){
            cout<<N<<endl;
        }else{
            cout<<X+Y-1<<endl;
        }
    }
}