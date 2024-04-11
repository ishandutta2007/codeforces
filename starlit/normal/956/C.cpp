#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m[N],v[N],sum,ln;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    scanf("%d",v+i),m[i]=v[i],v[i]=v[i]<v[i-1]?v[i-1]:v[i];
    for(int i=n-1;i;i--)
    v[i]=v[i]<v[i+1]?v[i+1]-1:v[i],ans+=v[i]-m[i];
    printf("%lld",ans+v[n]-m[n]);
}