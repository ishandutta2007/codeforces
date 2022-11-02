#include<cstdio>
#include<algorithm>

using namespace std;

int n,q,l,r,top;
int a[100010],val[100010],b[100010];
long long ans,nowans;

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		val[i]=abs(a[i+1]-a[i]);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		nowans=ans=top=0;
		for(int i=l;i<r;i++)
		{
			while(top&&val[b[top]]<=val[i])
			{
				if(top>1)nowans-=1ll*(b[top]-b[top-1])*val[b[top]];
				else nowans-=1ll*(b[top]-l+1)*val[b[top]];
				top--;
			}
			if(top)nowans+=1ll*(i-b[top])*val[i];
			else nowans+=1ll*(i-l+1)*val[i];
			b[++top]=i;
			ans+=nowans;
		}
		printf("%I64d\n",ans);
	}
}