#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
#define cmax(a,b) a=max(a,b)
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
struct Point{ll x,y,z;};
const ll N=2e5+50,inf=(ll)3e18+50,inf2=(ll)1e18+5,inf3=(ll)5e18+60;
ll n;
Point p[N],ans;
ll lx[N],rx[N],ly[N],ry[N];
bool ty(ll a,ll b){return abs(a%2ll)==abs(b%2ll);}
bool solve(ll D,ll mid)
{
	ll i,mlx,mrx,mly,mry,d;
	for(i=1;i<=n;i++)
	{
		d=D-abs(mid-p[i].z);
		lx[i]=(p[i].x-d)-p[i].y;
		ly[i]=(p[i].x-d)+p[i].y;
		rx[i]=lx[i]+(d<<1);
		ry[i]=ly[i]+(d<<1);
	}
	mlx=-inf3;mly=-inf3;mrx=inf3;mry=inf3;
	for(i=1;i<=n;i++)
	{
		cmax(mlx,lx[i]);cmin(mrx,rx[i]);
		cmax(mly,ly[i]);cmin(mry,ry[i]);
		if(mlx>mrx||mly>mry) return 0;
	}
	if(mlx==mrx&&mly==mry&&ty(mlx,mly)==0) return 0;
	return 1;
}
bool check(ll D)
{
	//printf("check %lld\n",D);
	ll sl,sr,mid,i,mlx,mrx,mly,mry,id,d,p1,p2,der=0;
	sl=-inf2;sr=inf2;
	for(i=1;i<=n;i++)
	{
		cmax(sl,p[i].z-D);
		cmin(sr,p[i].z+D);
	}
	while(sl<=sr)
	{
		mid=(sl+sr)/2ll;mid+=der;
		//printf("U%lld %lld %lld\n",sl,sr,mid);
		for(i=1;i<=n;i++)
		{
			d=D-abs(mid-p[i].z);
			lx[i]=(p[i].x-d)-p[i].y;
			ly[i]=(p[i].x-d)+p[i].y;
			rx[i]=lx[i]+(d<<1);
			ry[i]=ly[i]+(d<<1);
		}
		mlx=-inf3;mly=-inf3;mrx=inf3;mry=inf3;
		for(i=1;i<=n;i++)
		{
			cmax(mlx,lx[i]);cmin(mrx,rx[i]);
			cmax(mly,ly[i]);cmin(mry,ry[i]);
			if(mlx>mrx||mly>mry) break;
		}
		if(i==n+1) 
		{
			if(mlx==mrx&&mly==mry&&ty(mlx,mly)==0)
			{
				if(mid<sr&&solve(D,mid+1)) der=1;
				else if(mid>sl&&solve(D,mid-1)) der=-1;
				else return 0;
			}
			else
			{
				//printf("P%lld %lld %lld %lld\n",mlx,mrx,mly,mry);
				ans.z=mid;
				
				if(ty(mlx,mly)==0)
				{
					if(mlx<mrx) mlx++;
					else mly++;
				}
				ans.x=(mlx+mly)/2ll;
				ans.y=(mly-mlx)/2ll;
				//printf("U%lld %lld %lld \n",ans.x,ans.y,ans.z);
				return 1;
			}
		}
		else
		{
			id=i;
			for(i=1;i<id;i++)
			{
				if(lx[i]>rx[id]||rx[i]<lx[id]||ly[i]>ry[id]||ry[i]<ly[id]) 
				{
					if(mid*2ll>=(p[i].z+p[id].z)) sr=mid-1;
					else sl=mid+1;
					break;
				}
			}
		}
	}
	//printf("NO ans on %lld\n",D);
	return 0;
}
void Solve()
{
	ll i,sl,sr,mid;
	n=rd();
	for(i=1;i<=n;i++)
	{
		p[i].x=rd();p[i].y=rd();p[i].z=rd();
	}
	sl=0;sr=inf;
	while(sl<sr)
	{
		mid=(sl+sr)>>1;
		if(check(mid)==1) sr=mid;
		else sl=mid+1; 
	}
	check(sl);
	//printf("S%lld\n",sl);
	printf("%lld %lld %lld\n",ans.x,ans.y,ans.z);
}
int main()
{
	ll T;
	T=rd();
	while(T--) Solve();
}