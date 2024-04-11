#include<bits/stdc++.h>
using namespace std;
map<long long,long long> m;
long long n,k;
long long a[300009];
long long d[300009];
main()
{cin>>n>>k;
for (long long i=0; i<n; i++)
cin>>a[i];
for(long long i=0; i<n; i++)
{if(a[i]%k==0) d[i]=m[a[i]/k];
m[a[i]]++;	}
m.clear();
long long ans=0;
for (long long i=n-1; i>=0; i--)
{ans+=d[i]*m[a[i]*k];
m[a[i]]++;}
	
cout<< ans;
}