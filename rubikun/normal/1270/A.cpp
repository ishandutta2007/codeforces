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
        int N,A,B;cin>>N>>A>>B;
        bool ok=false;
        
        for(int i=0;i<A;i++){
            int a;cin>>a;
            if(a==N) ok=true;
        }
        for(int i=0;i<B;i++){
            int a;cin>>a;
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}