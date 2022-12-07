#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=2e5+50;
ll n,m=0,num=0,ans=0;
ll a[N],b[N];
int main()
{
	ll i,K,w,p,vmi,vmx;
	n=rd();
	for(i=1;i<=n;i++)
	{
		K=rd();K--;
		vmi=vmx=rd();
		bool pd=0;
		while(K--)
		{
			w=rd();
			if(w>vmi) pd=1;
			vmi=min(vmi,w);vmx=max(vmx,w);
		}
		if(pd==0) m++,a[m]=vmi,b[m]=vmx;
		else num++;
	}
	sort(a+1,a+m+1);
	sort(b+1,b+m+1);
	for(i=1,p=1;i<=m;i++)
	{
		while(p<=m&&b[p]<=a[i]) p++;
		ans+=m-p+1;
	}
	ans+=num*n*2ll-num*num;
	cout<<ans;
	return 0;
}