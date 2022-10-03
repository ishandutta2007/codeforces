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
    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<ll> A(N);
        ll x=0,y=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            x+=A[i];
            y^=A[i];
        }
        
        if(x==2*y){
            cout<<0<<endl;
            cout<<endl;
        }else{
            cout<<2<<endl;
            cout<<y<<" "<<x+y<<endl;
        }
    }
}