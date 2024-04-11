#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int n,x,y,d;cin>>n>>x>>y>>d;
        if(abs(x-y)%d==0) cout<<abs(x-y)/d<<endl;
        else{
            int ans1,ans2;
            ans1=(x-1+d-1)/d+(y-1)/d;
            ans2=(n-x+d-1)/d+(n-y)/d;
            if((y-1)%d!=0) ans1=INF;
            if((n-y)%d!=0) ans2=INF;
            int ans=min(ans1,ans2);
            if(ans==INF) cout<<-1<<endl;
            else cout<<ans<<endl;
        }
    }
}