#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=int(S.size());
    ll ans=0;
    for(int i=0;i<N;i++){
        for(int j=i+2;j<N;j++){
            bool ok=false;
            for(int k=1;j-2*k>=i;k++){
                if(S[j-2*k]==S[j-k]&&S[j-k]==S[j]) ok=true;
            }
            if(ok){
                ans+=N-j;
                break;
            }
        }
    }
    
    cout<<ans<<endl;
}