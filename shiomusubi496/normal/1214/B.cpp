#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int a,b,n; cin>>a>>b>>n;
    int ans=0;
    for(int i=0;i<=n;i++){
        if(i<=a && (n-i)<=b)ans++;
    }
    cout<<ans<<endl;
}