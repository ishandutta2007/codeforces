#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
#define pii pair<double,double>
#define fi first
#define se second
using namespace std;
#define db double
#define MAXN 105
#define eps 1e-4
pii ak[MAXN];int n;
db MO(pii x){return x.fi*x.fi+x.se*x.se;}
db xj(pii x,pii y)
{
	return x.fi*y.se-x.se*y.fi;
	}
double dis(pii a,pii b){return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);}
int check_kind(pii a,pii b,pii c)
{
	if(fabs(xj(pii(b.fi-a.fi,b.se-a.se),pii(c.fi-a.fi,c.se-a.se)))<=1e-5)return 3;
	db bs[4];bs[1]=dis(a,b);bs[2]=dis(b,c);bs[3]=dis(a,c);
	sort(bs+1,bs+1+3);
	if(fabs(bs[1]+bs[2]-bs[3])<eps)return 2;
	if(bs[1]+bs[2]<bs[3])return 3;
	return 1;
}
bool JU(pii a,pii b,pii c,pii d)
{
	if(dis(a,b)!=dis(c,d))return 0;
	if(fabs(a.fi+b.fi-c.fi-d.fi)>eps)return 0;
	if(fabs(a.se+b.se-c.se-d.se)>eps)return 0;
	return 1;
}
bool jie(db a,db b,db c,db d,db e,db f,pii &res)
{
	db s=a*e-b*d;if(s<=1e-6&&s>=-1e-6)return 0;
	res.fi=(b*f-e*c)/s;
	res.se=(d*c-a*f)/s;
	return 1;
}
bool center(pii a,pii b,pii c,pii &res)
{
	if(!jie(2*(b.fi-a.fi),2*(b.se-a.se),MO(a)-MO(b),2*(c.fi-b.fi),2*(c.se-b.se),MO(b)-MO(c),res))return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);rep(i,1,n){scanf("%lf%lf",&ak[i].fi,&ak[i].se);}
	db ans=-1;
	rep(i,1,n)rep(j,1,n)rep(k,1,n)if(i!=j&&j!=k&&i!=j)
	if(ak[i]!=ak[j]&&ak[i]!=ak[k]&&ak[j]!=ak[k])
	{
		if(check_kind(ak[i],ak[j],ak[k])==1)
		{
			pii u;
			if(!center(ak[i],ak[j],ak[k],u))continue;
			db de=dis(ak[i],u);bool fs=1;
			rep(p,1,n)
			{
				if(dis(ak[p],u)+eps<de)fs=0;;
			}
			if(fs)ans=max(ans,de);
		}
		else if(check_kind(ak[i],ak[j],ak[k])==2)
		{
			rep(p,1,n)
			if(p!=i&&p!=j&&p!=k)
			if(ak[p]!=ak[i]&&ak[p]!=ak[j]&&ak[p]!=ak[k])
			if(JU(ak[i],ak[j],ak[k],ak[p]))
			{
				pii u=pii((ak[i].fi+ak[j].fi)/2,(ak[i].se+ak[j].se)/2);
				db de=dis(ak[i],u);bool fst=1;
				rep(p,1,n)if(dis(ak[p],u)+eps<de)fst=0;
				if(fst)ans=max(ans,de);
			}
		}
	}
	if(ans<0)printf("-1\n");else 
	printf("%.8lf\n",sqrt(ans));
	return 0;
}