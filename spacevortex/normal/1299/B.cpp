#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{ll x,y;};
const Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
const Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
const ll N=2e5+50;
ll n;
Point p[N];
int main()
{
	ios::sync_with_stdio(false);
	ll i;
	Point np;
	cin>>n;
	for(i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	if(n&1ll)
	{
		puts("No");return 0;
	}
	p[n+1]=p[1];
	for(i=1;i<=(n>>1);i++)
	{
		np=p[i+1]-p[i]+p[i+(n>>1)+1]-p[i+(n>>1)];
		if(np.x!=0||np.y!=0)
		{
			puts("No");return 0;
		}
	}
	puts("Yes");
	return 0;
}