#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{ll x,y;};
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
ll cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
const ll N=4050,V=4e6+50;
ll n,S,tot=0;
Point p[N],l[V];
ll pl[N],dy[N];
bool cmp(const Point &a,const Point &b)
{
	return cross(p[a.y]-p[a.x],p[b.y]-p[b.x])>0;
}
bool cmp1(const ll &a,const ll &b)
{
	return cross(p[l[1].y]-p[l[1].x],p[a]-p[l[1].x])<cross(p[l[1].y]-p[l[1].x],p[b]-p[l[1].x]);
}
ll qry(Point a,Point b,Point c)
{
	return cross(b-a,c-a);
}
void print(Point a,Point b,Point c)
{
	cout<<"Yes"<<endl;
	cout<<a.x<<" "<<a.y<<endl;
	cout<<b.x<<" "<<b.y<<endl;
	cout<<c.x<<" "<<c.y<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	ll i,j,sl,sr,mid;
	Point a,b;
	cin>>n>>S;
	S<<=1;
	for(i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			l[++tot]=(Point){i,j};
			if(p[i].x>p[j].x) swap(l[tot].x,l[tot].y);
		}
	}
	sort(l+1,l+tot+1,cmp);
	for(i=1;i<=n;i++) pl[i]=i;
	sort(pl+1,pl+n+1,cmp1);
	for(i=1;i<=n;i++) dy[pl[i]]=i;
	for(i=1;i<=tot;i++)
	{
		a=p[l[i].x];b=p[l[i].y];
		sl=1;sr=n;
		while(sl<sr)
		{
			mid=(sl+sr)>>1;
			if(qry(a,b,p[pl[mid]])>=S) sr=mid;
			else sl=mid+1;
		}
		if(qry(a,b,p[pl[sl]])==S)
		{
			print(a,b,p[pl[sl]]);
			return 0;
		}

		sl=1;sr=n;
		while(sl<sr)
		{
			mid=(sl+sr+1)>>1;
			if(qry(a,b,p[pl[mid]])<=-S) sl=mid;
			else sr=mid-1;
		}
		if(qry(a,b,p[pl[sl]])==-S)
		{
			print(a,b,p[pl[sl]]);
			return 0;
		}
		swap(pl[dy[l[i].x]],pl[dy[l[i].y]]);
		swap(dy[l[i].x],dy[l[i].y]);
	}
	cout<<"No"<<endl;
	return 0;
}