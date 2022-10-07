#include<iostream>
#include<algorithm>
using namespace std;
int a[60],ans=100000000;
main()
{int n,m;
cin>>n>>m;
for (int i=0; i<m; i++) cin>>a[i];
sort (a,a+m);
for (int i=0; i<=m-n; i++)
ans=min(ans,a[i+n-1]-a[i]);
cout<<ans<<endl;
}