#include<bits/stdc++.h>

#define mo 1000000007

using namespace std;

int n,cnt,ans,a[200020],b[5][200020],f[200020],inv[200020];

int power(int x,int m)
{
	int nowans=1;
	while(m)
	{
		if(m&1)nowans=1ll*nowans*x%mo;
		x=1ll*x*x%mo;
		m>>=1;
	}
	return nowans;
}

int main()
{
	scanf("%d",&n);
	if(n<=4)
	{
		cnt=0;
		if(n==1)b[0][1]=1;
		if(n==2)
		{
			b[0][1]=1;
			b[0][2]=1;
		}
		if(n==3)
		{
			b[0][1]=1;
			b[0][2]=2;
			b[0][3]=-1+mo;
		}
		if(n==4)
		{
			b[0][1]=1;
			b[0][2]=-1+mo;
			b[0][3]=1;
			b[0][4]=-1+mo;
		}
	}
	else
	{
		int N=n;
		while(N%4!=1)N--;
		int m=N;
		N=(N-1)/2;
		f[0]=1;
		for(int i=1;i<=N;i++)
			f[i]=1ll*i*f[i-1]%mo;
		inv[N]=power(f[N],mo-2);
		for(int i=N-1;i;i--)
			inv[i]=1ll*inv[i+1]*(i+1)%mo;
		inv[0]=1;
		for(int i=1;i<=m;i+=2)
			b[0][i]=1ll*f[N]*inv[(i-1)/2]%mo*inv[N-(i-1)/2]%mo;
		cnt=0;
		for(;m<n;)
		{
			m++;
			cnt++;
			for(int i=1;i<=m;i++)
			{
				if(i%4==1||i%4==3)
				{
					if(cnt!=2)b[cnt][i]=(b[cnt-1][i-1]+b[cnt-1][i])%mo;
					else b[cnt][i]=(b[cnt-1][i]-b[cnt-1][i-1]+mo)%mo;
				}
				if(i%4==2||i%4==0)
				{
					if(cnt!=3)b[cnt][i]=(b[cnt-1][i]+b[cnt-1][i-1])%mo;
					else b[cnt][i]=(b[cnt-1][i-1]-b[cnt-1][i]+mo)%mo;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=1ll*a[i]*b[cnt][i]%mo;
		ans%=mo;
	}
	printf("%d\n",ans);
}