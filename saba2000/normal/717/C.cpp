#include<iostream>
#include<algorithm>
using namespace std;
main()
{int a[100009],n;
long long ans=0;
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
sort(a,a+n);
for (int i=0; i<n; i++)
ans=(ans+1ll*a[i]*a[n-1-i]%10007)%10007;

cout<<ans%10007<<endl;

}