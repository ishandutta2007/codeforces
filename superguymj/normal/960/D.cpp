#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
int n,tp;
LL bin[100],x,k,mve[100];

int get(LL x)
{
	int rt=0;
	while(x) ++rt,x>>=1;
	return rt;
}

int main()
{
	scanf("%d",&n),bin[1]=1;
	rep(i,2,62) bin[i]=bin[i-1]<<1;
	while(n--)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%I64d%I64d",&x,&k);
			int c=get(x);
			mve[c]=(mve[c]+k)%bin[c];
		}
		if(tp==2)
		{
			scanf("%I64d%I64d",&x,&k);
			int c=get(x);
			k%=bin[c];
			rep(i,c,62)
			{
				mve[i]=(mve[i]+k)%bin[i];
				k<<=1;
			}
		}
		if(tp==3)
		{
			scanf("%I64d",&x);
			int c=get(x);
			LL a=x-bin[c];
			printf("%I64d",x);
			x=((a+mve[c])%bin[c]+bin[c])%bin[c]+bin[c];
			repd(i,c-1,1)
			{
				x>>=1;
				a=x-bin[i];
				printf(" %I64d",((a-mve[i])%bin[i]+bin[i])%bin[i]+bin[i]);
			}
			puts("");
		}
	}
	return 0;
}