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
    int a=0,b=0,ans=1,pre=0;
    while(Q--){
        int c,d;cin>>c>>d;
        int e=max(a,b);
        int f=min(c,d);
        if(pre==e){
            ans+=max(0,f-e);
            pre=max(f,pre);
        }else{
            ans+=max(0,f-e+1);
            pre=max(f,pre);
        }
        
        a=c;
        b=d;
    }
    cout<<ans<<endl;
}