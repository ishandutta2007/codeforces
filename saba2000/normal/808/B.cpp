#include<bits/stdc++.h>
using namespace std;
main()
{
int n,k,a[1000009];
cin>>n>>k;
for(int i=0; i<n; i++)
cin>>a[i];
long long s=0,S=0;
for (int i=0; i<k; i++)
s+=a[i];
for(int i=0; i<=n-1-k; i++)
{S+=s;
s+=a[i+k]-a[i];
}
S+=s;double A=S,b=n-k+1;
cout.precision(10);
cout<<A/b<<endl;
}