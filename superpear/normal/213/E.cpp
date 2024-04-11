#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn=300000;

int f[maxn],a[maxn],b[maxn],u[maxn],back[maxn];
int n,m,last,e,cs,ans;

void mplus(int place,int num)
{
	while (place<=m)
	{
		f[place]+=num;
		place+=place&(-place);
	}
}

int getsum(int place)
{
	int k=0;
	while (place>0)
	{
		k+=f[place];
		place-=place&(-place);
	}
	return k;
}

int main()
{
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&cs);
		a[cs]=i;
	}
    //for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
	    u[i]=getsum(a[i]-1);
	    mplus(a[i],1);
	}
	memset(f,0,sizeof(f));
	last=0;
	back[1]=0;
	mplus(a[1],1);
	for (int i=2;i<=n;i++)
	{
        e=back[i-1];
        //cout<<last<<" "<<i-e-1<<endl;
        for (int j=last+1;j<=i-e-1;j++) mplus(a[j],-1);
        last=i-e-1;
        while ((e>0)&&(getsum(a[i])!=u[e+1]))
        {
            e=back[e];
            for (int j=last+1;j<=i-e-1;j++) mplus(a[j],-1);
            last=i-e-1;
        }
        //cout<<e<<"  "<<u[e+1]<<endl;
        if (u[e+1]==getsum(a[i])) ++e;
        back[i]=e;
        mplus(a[i],1);
	}
	//for (int i=1;i<=n;i++) cout<<back[i]<<" ";cout<<endl;

	for (int i=1;i<=m;i++)
	{
		scanf("%d",&cs);
		b[cs]=i;
	}
	memset(f,0,sizeof(f));
    e=0;
    last=0;
    ans=0;
	for (int i=1;i<=m;i++)
	{
        for (int j=last+1;j<=i-e-1;j++) mplus(b[j],-1);
        last=i-e-1;
        while ((e>0)&&(getsum(b[i])!=u[e+1]))
        {
            e=back[e];
            for (int j=last+1;j<=i-e-1;j++) mplus(b[j],-1);
            last=i-e-1;
        }
        //cout<<e<<endl;
        if (u[e+1]==getsum(b[i])) ++e;
        if (e==n)
        {
            ++ans;
            e=back[e];
            for (int j=last+1;j<=i-e-1;j++) mplus(b[j],-1);
            last=i-e-1;
        }
        mplus(b[i],1);
	}
	cout<<ans<<endl;

	return 0;
}