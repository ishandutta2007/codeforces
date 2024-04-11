#include<iostream>
using namespace std;
int n,m,p[1000000],k,ans[1000000],an=0;
main()
{
cin>>n>>m;
for (int i=0; i<n; i++)
{cin>>k;
if (k<900000) p[k]=1;}
for (int i=1; true; i++)
{if (m-i<0) break;
//cout<<i<<" "<<p[i]<<" "<<m<<" "<<endl;
if (p[i]==0) {ans[an]=i; an++; m-=i;}
}
cout<<an<<endl;
for (int i=0; i<an; i++)
cout<<ans[i]<<" ";

}