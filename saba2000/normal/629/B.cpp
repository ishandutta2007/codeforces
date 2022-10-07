#include<iostream>
using namespace std;
int n,f[400],m[400],ans=0;
main()
{
char p;
int a,b;
cin>>n;
for (int i=0; i<n; i++)
{cin>>p>>a>>b;
for (int j=a; j<=b; j++)
if (p=='F') f[j]++;
else m[j]++;
}
for (int i=1; i<=366; i++)
ans=max(ans,min(f[i],m[i]));
cout<<ans*2<<endl;

}