#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=300005;
int n,m,ans[N],id[N];
struct data{int a,b,id;} dat[N],p[N];

bool cmpb(data x,data y)
{
	return x.b<y.b;
}

bool cmpa(data x,data y)
{
	return x.b>y.b;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&dat[i].a,&dat[i].b),dat[i].id=i;
	m=0;
	rep(i,1,n) if(dat[i].a>dat[i].b) p[++m]=dat[i];
	if(m)
	{
		sort(p+1,p+1+m,cmpb);
		data tmp=p[1];
		int len=1;
		id[len]=p[1].id;
		rep(i,2,m)
			if(p[i].a>tmp.b) tmp=p[i],id[++len]=p[i].id;
		if(*ans<len)
			rep(i,1,len) ans[i]=id[i];
		*ans=max(*ans,len);
	}
	m=0;
	rep(i,1,n) if(dat[i].a<dat[i].b) p[++m]=dat[i];
	if(m)
	{
		sort(p+1,p+1+m,cmpa);
		data tmp=p[1];
		int len=1;
		id[len]=p[1].id;
		rep(i,2,m)
			if(p[i].a<tmp.b) tmp=p[i],id[++len]=p[i].id;
		if(*ans<len)
			rep(i,1,len) ans[i]=id[i];
		*ans=max(*ans,len);
	}
	printf("%d\n",*ans);
	rep(i,1,*ans) printf("%d ",ans[i]);
	puts("");
	return 0;
}