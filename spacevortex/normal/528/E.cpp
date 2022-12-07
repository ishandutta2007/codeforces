#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
struct Point{db x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
db cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
const ll N=6050,inf=(ll)1e10;
ll n;
db ans=0;
struct Line{ll a,b,c;}h[N];
db t[3][4];
ll i,j,k;
db xs;
Point inter(Line l1,Line l2)
{
	t[1][1]=l1.a;t[1][2]=l1.b;t[1][3]=l1.c;
	t[2][1]=l2.a;t[2][2]=l2.b;t[2][3]=l2.c;
	for(i=1;i<=2;i++)
	{
		for(j=i;j<=2;j++)
		{
			if(abs(t[j][i])>abs(t[i][i])) swap(t[i],t[j]); 
		}
		for(j=3;j>=i;j--) t[i][j]/=t[i][i];
		for(j=1;j<=2;j++)
		{
			if(i==j) continue;
			xs=t[j][i]/t[i][i];
			for(k=i;k<=3;k++) t[j][k]-=t[i][k]*xs;
		}
	}
	return (Point){t[1][3],t[2][3]};
}
bool cmp(const Line &x,const Line &y)
{
	if(x.b==0) return 1;
	if(y.b==0) return 0;
	return (db)(x.c-x.a*(-inf))/(db)x.b>(db)(y.c-y.a*(-inf))/(db)y.b;
}
int main()
{
	ios::sync_with_stdio(false);
	ll i,j;
	Point sum,now;
	cin>>n;
	for(i=1;i<=n;i++) cin>>h[i].a>>h[i].b>>h[i].c;
	sort(h+1,h+n+1,cmp);
	for(i=1;i<=n;i++) h[i+n]=h[i];
	for(i=1;i<=n;i++)
	{
		sum=(Point){0,0};
		for(j=i+1;j<i+n;j++)
		{
			now=inter(h[i],h[j]);
			ans+=cross(sum,now);
			sum=sum+now;
		}
	}
	ans/=2.0;
	ans/=n*(n-1)*(n-2)/6;
	printf("%.8lf",ans);
	return 0;
}