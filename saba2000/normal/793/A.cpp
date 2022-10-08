#include<bits/stdc++.h>
using namespace std;
int main()
{long long n,k,p,a[100009],ma,mi,z;
cin>>n>>k>>a[0]; mi=a[0];
z=a[0]%k;
long long q;
for(long long i=1; i<n; i++)
{cin>>a[i];
mi=min(mi,a[i]);
if(a[i]%k!=z){cout<<-1<<endl; return 0;}
}long long x=0;
for(long long i=0; i<n; i++)
x+=(a[i]-mi)/k;
cout<<x<<endl;
	
}