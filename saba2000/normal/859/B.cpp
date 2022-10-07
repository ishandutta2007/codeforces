#include<bits/stdc++.h>
using namespace std;
int k;
main()
{int n;
cin>>n;
int ans=5*n;
for (int i=1; i<=n; i++)
ans=min(ans,2*(i+(n+i-1)/i));
cout<<ans<<endl;
}