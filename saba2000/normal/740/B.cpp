#include<iostream>
using namespace std;
main()
{long long n,m,a[1000],l,r,ans=0;
cin>>n>>m;
for (int i=0; i<n; i++)
cin>>a[i];
for (int i=0; i<m; i++)
{cin>>l>>r; int k=0;
for (int j=l-1; j<=r-1; j++)
k+=a[j];
if (k>0) ans+=k;
}
cout<<ans<<endl;
return 0;
}