#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
double c,T;
P a[MAXN];
vector<int> dis;
double bit[2*MAXN+1];
double sum(int i)
{
    double s=0;
    while(i>0)
    {
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void add(int i,double x)
{
    while(i<=n)
    {
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
bool cmp(P x,P y)
{
	if(1LL*x.F*y.S==1LL*x.S*y.F) return x.S<y.S;
	return 1LL*x.F*y.S<1LL*x.S*y.F;
}
const double eps=1e-12;
bool check(double x)
{
	memset(bit,0,sizeof(bit));
	double s=0;
	int px=0,qx=1;
	vector<P> v;
	for(int i=1;i<=n+1;i++)
	{
		if(i==n+1||1LL*px*a[i].S<1LL*qx*a[i].F)
		{
			for(auto p:v)
			{
				int rk=lower_bound(dis.begin(),dis.end(),p.S)-dis.begin()+1;
				double pt=p.S*(1.0-x*(s+p.F)/T);
				add(rk,pt);
			} 
			for(auto p:v) s+=p.F;
			v.clear();
			px=a[i].F; qx=a[i].S;
		}
		if(i<=n) v.push_back(a[i]);
	}
	px=0,qx=1;
	s=0;
	for(int i=1;i<=n+1;i++)
	{
		if(i==n+1||1LL*px*a[i].S<1LL*qx*a[i].F)
		{
			for(auto p:v) s+=p.F;
			for(auto p:v)
			{
				int rk=lower_bound(dis.begin(),dis.end(),p.S)-dis.begin()+1;
				double pt=p.S*(1.0-x*s/T);
				if(sum(rk-1)>pt+eps) return false;
			} 
			v.clear();
			px=a[i].F; qx=a[i].S;
		}
		if(i<=n) v.push_back(a[i]);
	}
	return true;
}
int main()
{
	T=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i].S);
		dis.push_back(a[i].S);
	}
	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(),dis.end()),dis.end());
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i].F);
		T+=a[i].F;
	}
	sort(a+1,a+n+1,cmp);
	double l=0.0,r=1.0;
	for(int i=0;i<100;i++)
	{
		double mid=(l+r)/2;
		if(check(mid)) l=mid; else r=mid;
	}
	printf("%.10f\n",l);
	return 0;
}