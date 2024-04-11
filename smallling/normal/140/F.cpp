#include<cstdio>
#include<algorithm>

#define fi first
#define se second
#define mp make_pair

using namespace std;

int l,r,n,m,cnt,Ans,ANS;
pair<int,int>a[200010];
pair<double,double>A,B,nowpoint,ans[200020];

int work(pair<double,double>point)
{
	l=1;
	r=n;
	cnt=0;
	while(l<=r)
	{
		A=mp(point.fi-a[l].fi,point.se-a[l].se);
		B=mp(a[r].fi-point.fi,a[r].se-point.se);
		if(A==B)l++,r--;
		else if(A<B)r--,cnt++;
		else l++,cnt++;
	}
	return cnt<=m;
}

int main()
{
	scanf("%d%d",&n,&m);
	if(m>=n)return puts("-1"),0;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+1+n);
	for(int i=1;i<=m+1;i++)
		for(int j=n;j>=n-m;j--)
		{
			nowpoint=mp((a[i].fi+a[j].fi)/2.,(a[i].se+a[j].se)/2.);
			if(work(nowpoint))ans[++Ans]=nowpoint;
		}
	sort(ans+1,ans+1+Ans);
	for(int i=2;i<=Ans;i++)
		if(ans[i]>ans[i-1])ANS++;
	if(Ans)ANS++;
	printf("%d\n",ANS);
	if(Ans)printf("%.6lf %.6lf\n",ans[1].fi,ans[1].se);
	for(int i=2;i<=Ans;i++)
		if(ans[i]>ans[i-1])printf("%.6lf %.6lf\n",ans[i].fi,ans[i].se);
}