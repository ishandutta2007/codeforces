#include<bits/stdc++.h>
using namespace std;
int main()
{long long n,b,a[100009],c,m,e,o,ans;
cin>>n>>b;
for (int i=0; i<n-1; i++)
{cin>>c;
a[i]=abs(c-b);
b=c;}
m=a[0]; ans=a[0]; 
for (int i=2; i<n-1; i+=2)
{m=max((long long)a[i],m-a[i-1]+a[i]);
ans=max(ans,m);}
if (n==2) {cout<<ans<<endl; return 0;}
m=a[1]; ans=max(ans,a[1]);
for (int i=3; i<n-1; i+=2){
m=max((long long)a[i],m-a[i-1]+a[i]);
ans=max(ans,m);}
cout<<ans<<endl;
}