#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int inv[1000010];
long long a,b,p,x;
int l[1000010],r[1000010];
int pos[1000010];
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&p,&x);
	inv[1]=1;
	for(int i=2;i<p;i++)
    {
        inv[i]=(1ll*(p/i+1)*inv[i-p%i])%p;
    }
    l[0]=1;
    for(int i=1;i<p;i++)
	{
		l[i]=1ll*l[i-1]*a%p;
		r[i]=1ll*b*inv[i]%p;
		pos[r[i]]=i;
		//cout<<i<<' '<<l[i]<<' '<<r[i]<<endl;
	}
	x++;
	long long rep=x/(p*(p-1));x%=(p*(p-1));
	long long ans=rep*(p-1);
	long long rep2=x/(p-1),left=x%(p-1);
	for(int i=0;i<p-1;i++)
	{
		int rr=pos[l[i]],t=(i+(p)-rr)%(p);
		//cout<<l[i]<<' '<<rr<<' '<<t<<endl;
		if(t<rep2+(i<=left-1))ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
//2 3 5 8