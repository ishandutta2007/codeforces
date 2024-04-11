#include<iostream>
using namespace std;
long long n,a[10000],ans=0,b[10000];
int gdc(int a, int b)
{if (b==0) return a;
else return gdc(b,a%b);
}

main()
{
cin>>n;
cin>>a[0];
for (int i=1; i<n; i++)
{cin>>a[i];
if (gdc(a[i-1],a[i])!=1)  {ans++; b[i]=1;}}
cout<<ans<<endl<<a[0]<<" ";
for (int i=1; i<n; i++)
{if (b[i]!=0) cout<<b[i]<<" ";
cout<<a[i]<<" ";}

}