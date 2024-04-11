#include<bits/stdc++.h>
using namespace std;
long long k,a[500009],s,ans=0,p,l;
int main()
{int n;
cin>>n; 
for (int i=0; i<n; i++)
{cin>>a[i]; s+=a[i];}
if (s%3!=0) {cout<<0<<endl; return 0;}
s/=3;
for (int i=0; i<n-1; i++)
{p+=a[i];
if (p==2*s) ans+=l;
if (p==s) l++;

}
cout<<ans<<endl;
}