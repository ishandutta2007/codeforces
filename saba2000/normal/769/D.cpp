#include<bits/stdc++.h>
using namespace std;
int n,k,a[100009];
long long f[18009];
long long ans;
int main()
{cin>>n>>k;
for (int i=0; i<n; i++){
cin>>a[i];
f[a[i]]++;}
if (k==0){
for (int i=0; i<=10000; i++)
ans+=f[i]*(f[i]-1)/2;
cout<<ans<<endl; return 0;}
for (int i=0; i<=16383; i++)
{int p=0;
for (int j=0; (1<<j)<=i; j++)
if (i&(1<<j)) p++;

if (p!=k) continue;
//if (n==10001) cout<<i<<" ";
for (int j=0; j<=10000; j++)
ans+=f[j]*f[(j^i)];

//cout<<ans<<endl;
}
cout<<ans/2<<endl;
}
//a^a==x
//11 -- 1
//2 -- 0