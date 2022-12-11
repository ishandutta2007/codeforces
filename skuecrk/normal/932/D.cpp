#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 400000
#define LG 20
int fa[LG][MN+5],w[MN+5],mx[LG][MN+5],FA[LG][MN+5];
long long s[LG][MN+5];
int main()
{
	int q,t,ls=0,cnt=1,i;long long x,y;
	for(i=0;i<LG;++i)s[i][0]=1e18;
	for(i=1;i<LG;++i)s[i][1]=1e18;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%I64d%I64d",&t,&x,&y);
		x^=ls;y^=ls;
		if(t==1)
		{
			fa[0][++cnt]=x;mx[0][cnt]=w[cnt]=y;
			for(i=1;i<LG;++i)
				fa[i][cnt]=fa[i-1][fa[i-1][cnt]],
				mx[i][cnt]=max(mx[i-1][cnt],mx[i-1][fa[i-1][cnt]]);
			if(w[x]<w[cnt])for(i=LG;i--;)if(mx[i][x]<y)x=fa[i][x];
			FA[0][cnt]=x;s[0][cnt]=w[cnt];
			for(i=1;i<LG;++i)
				FA[i][cnt]=FA[i-1][FA[i-1][cnt]],
				s[i][cnt]=min(s[i-1][cnt]+s[i-1][FA[i-1][cnt]],(long long)1e18);
		}
		else
		{
			for(ls=0,i=LG;i--;)if(s[i][x]<=y)y-=s[i][x],ls+=1<<i,x=FA[i][x];
			printf("%d\n",ls);
		}
	}
}