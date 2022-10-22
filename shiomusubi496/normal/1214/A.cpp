#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n; cin>>n;
    int d,e; cin>>d>>e;
    e*=5;
    int ans=n;
    for(int i=0;i<=500 && i*d<=n;i++){
        ans=min(ans,(n-i*d)%e);
    }
    cout<<ans<<endl;
}