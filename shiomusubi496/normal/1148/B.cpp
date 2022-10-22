#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,m,a,b,k; cin>>n>>m>>a>>b>>k;
    if(n<=k || m<=k)return puts("-1"),0;
    vector<int> A(n),B(m);
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<m;i++)cin>>B[i];
    int ans=0;
    for(int i=0;i<n && i<=k;i++){
        int t=k-i;
        int itr=lower_bound(B.begin(),B.end(),A[i]+a)-B.begin();
        if(itr+t>=m)return puts("-1"),0;
        ans=max(ans,B[itr+t]+b);
    }
    cout<<ans<<endl;
}