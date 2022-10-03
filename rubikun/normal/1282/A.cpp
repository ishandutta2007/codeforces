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
        int a,b,c,r;cin>>a>>b>>c>>r;
        if(a>b) swap(a,b);
        int d=b-a;
        
        a=max(a,c-r);
        b=min(b,c+r);
        
        cout<<d-max(0,(b-a))<<endl;
        
    }
}