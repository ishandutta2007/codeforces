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
    
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    
    int ans=0;
    
    for(int i=0;i<=100000;i++){
        if(i>b||i>c||i>d) continue;
        int j=min(a,d-i);
        
        ans=max(ans,j*e+i*f);
    }
    
    cout<<ans<<endl;
    
}