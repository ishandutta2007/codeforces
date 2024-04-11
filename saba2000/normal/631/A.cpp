#include<iostream>
using namespace std;
int n,a[1234],b[1234],ans=0,p;
main()
{
cin>>n;
for (int i=1; i<=n; i++)
{cin>>p; a[i]=a[i-1]|p;}
for (int j=1; j<=n; j++)
{cin>>p; b[j]=b[j-1]|p;}
for (int i=1; i<=n; i++)
for (int j=i; j<=n; j++)
{ans=max(ans,(a[j]|a[i-1])+(b[j]|b[i-1]));

}
cout<<ans<<endl;
}