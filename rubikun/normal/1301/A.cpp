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
        string a,b,c;cin>>a>>b>>c;
        bool ok=true;
        
        for(int i=0;i<a.size();i++){
            ok=false;
            if(a[i]==c[i]||b[i]==c[i]) ok=true;
            
            if(!ok) break;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}