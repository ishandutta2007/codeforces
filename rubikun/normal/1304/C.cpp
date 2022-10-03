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
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll M;cin>>N>>M;
        vector<ll> t(N),l(N),r(N);
        for(int i=0;i<N;i++) cin>>t[i]>>l[i]>>r[i];
        
        bool ok=true;
        ll canl=M,canr=M,nowt=0;
        
        for(int i=0;i<N;i++){
            ll tol=max(canl-(t[i]-nowt),l[i]);
            ll tor=min(canr+(t[i]-nowt),r[i]);
            
            if(tol>tor){
                ok=false;
                break;
            }
            
            canl=tol;
            canr=tor;
            nowt=t[i];
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}