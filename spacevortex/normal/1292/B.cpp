#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200,inf=(ll)2e16+50;
ll n,ax,ay,bx,by,sx,sy,t,top,ans=0;
ll x[N],y[N],px[N],py[N];
int main()
{
	ios::sync_with_stdio(false);
	ll i,a,b,c,val,id;
	n=1;
	cin>>x[1]>>y[1]>>ax>>ay>>bx>>by;
	while(1)
	{
		n++;
		x[n]=x[n-1]*ax+bx;y[n]=y[n-1]*ay+by;
		if(x[n]>inf||y[n]>inf) break;
	}
	cin>>sx>>sy>>t;
	//cout<<n<<endl;return 0;
	for(a=1;a<=n;a++)
	{
		for(b=a;b<=n;b++)
		{
			for(c=b;c<=n;c++)
			{
				val=0;
				top=1;px[1]=sx;py[1]=sy;
				for(i=b;i>=a;i--) top++,px[top]=x[i],py[top]=y[i];
				for(i=b+1;i<=c;i++) top++,px[top]=x[i],py[top]=y[i];
				id=-1;
				for(i=2;i<=top;i++) 
				{
					val+=abs(px[i]-px[i-1])+abs(py[i]-py[i-1]);
					if(val>t) break;
					id=i;
				}
				if(id==top) ans=max(ans,c-a+1);

				val=0;
				top=1;px[1]=sx;py[1]=sy;
				for(i=b+1;i<=c;i++) top++,px[top]=x[i],py[top]=y[i];
				for(i=b;i>=a;i--) top++,px[top]=x[i],py[top]=y[i];
				id=-1;
				for(i=2;i<=top;i++) 
				{
					val+=abs(px[i]-px[i-1])+abs(py[i]-py[i-1]);
					if(val>t) break;
					id=i;
				}
				if(id==top) ans=max(ans,c-a+1);
			}
		}
	}
	cout<<ans;
	return 0;
}