#include<cstdio>

typedef long long ll;
int n,ans[100005];
ll a[100005],sum,sa,l[60],bs,b[60],pos[60],s[60],tot=60;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i),sum^=a[i],ans[i]=2;
	for(int i=59;i>=0;i--)if(!(sum>>i&1))l[--tot]=i,sa|=1ll<<tot;
	for(int i=59;i>=0;i--)if(sum>>i&1)l[--tot]=i;
	for(int i=1;i<=n;i++)
	{
		ll x=0;
		for(int j=59;j>=0;j--)x|=(a[i]>>l[j]&1)<<j;
		bs=0;
		for(int j=59;j>=0;j--)
			if(x>>j&1)
			{
				if(!b[j]){b[j]=x;pos[j]=i;s[j]=bs^(1ll<<j);break;}
				else x^=b[j],bs^=s[j];
			}
	}
	bs=0;
	for(int j=59;j>=0;j--)
		if((sa^b[j])<sa)sa^=b[j],bs^=s[j];
	for(int j=59;j>=0;j--)
		if(bs>>j&1)ans[pos[j]]=1;
	for(int j=1;j<=n;j++)printf("%d%c",ans[j]," \n"[j==n]);
}