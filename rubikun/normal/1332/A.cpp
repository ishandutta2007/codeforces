#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200001,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int a,b,c,d,x,y,x1,y1,x2,y2;cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
        
        bool ok=true;
        
        if(b-a+x>x2||b-a+x<x1) ok=false;
        if(d-c+y>y2||d-c+y<y1) ok=false;
        if(a&&b&&x1==x&&x2==x) ok=false;
        if(c&&d&&y1==y&&y2==y) ok=false;
        
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
}