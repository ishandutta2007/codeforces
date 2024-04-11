#include<bits/stdc++.h>
using namespace std;
long long int arr[10000000];
long long int arr2[10000000];
#define mod 998244353
int main()
{
	long long int a,b=0,c=0,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,idx=0;
	scanf("%lld",&n);
	arr[1]=1;
	arr[2]=1;
	arr[3]=3;
	long long int hap=2;
	for(i=4;i<=n;i++)
    {
        arr[i]=( ((arr[i-1]+hap)%mod) *(i-1))-1;
        hap=(hap*(i-1))%mod;
        arr[i]=arr[i]%mod;
        if(arr[i]==0) arr[i]=mod;
    }
    printf("%lld",(n*arr[n])%mod);
}