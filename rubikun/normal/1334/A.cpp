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
        int N;cin>>N;
        int a,b;cin>>a>>b;
        bool ok=true;
        if(a<b) ok=false;
        N--;
        while(N--){
            int c,d;cin>>c>>d;
            if(a>c||b>d||c<d) ok=false;
            if(c-a<d-b) ok=false;
            
            a=c;
            b=d;
        }
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}