#include<bits/stdc++.h>
using namespace std;
long long b[100009],g[100009],a[100009],dp[100009],q[100009],l=1,cur,i;
main()
{   int n;
    cin>>n;
    for(i=0; i<2*n; i++)  i<n ? cin>>a[i] : cin>>b[i-n];
    for(g[0]=-1,i=1;i<n;g[i]=(dp[i]-dp[q[l-1]])/(b[q[l-1]]-b[i]),q[l]=i,i++,l++){
        while(cur<l-1 && a[i]>=g[q[cur+1]]) cur++;
        dp[i]=b[q[cur]]*a[i]+dp[q[cur]];
        while(l>1 && dp[i]-dp[q[l-2]]<=g[q[l-1]]*(b[q[l-2]]-b[i])) l--;
        }
    cout<<dp[n-1];
}