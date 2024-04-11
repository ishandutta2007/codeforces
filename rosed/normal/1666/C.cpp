#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 zmakioi
struct node
{
	int x,y;
	inline bool operator != (const node &t) const
	{
		return x!=t.x||y!=t.y;
	}
}a[1000];
struct line
{
	node a,b;

}t[1000];
int tot;
inline bool cmp1(node a,node b)
{
	return a.x<b.x;
}
inline bool cmp2(node a,node b)
{
	return a.y<b.y;
}
inline void get(node a,node b)
{
	if(a.x==b.x&&a.y==b.y) return;
	if(a.x>b.x) swap(a,b);
	node t1;
	if(a.y==min(a.y,b.y))
	{
		t1.x=max(a.x,b.x),t1.y=min(a.y,b.y);
		if(t1!=a) t[++tot]=(line){a,t1};
		if(t1!=b) t[++tot]=(line){t1,b};
	}
	else
	{
		t1.x=max(a.x,b.x),t1.y=max(a.y,b.y);
		if(t1!=a) t[++tot]=(line){a,t1};
		if(t1!=b) t[++tot]=(line){t1,b};
	}
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int i=1;i<=3;++i) cin>>a[i].x>>a[i].y;
		sort(a+1,a+4,cmp1);
	a[4].x=a[2].x;
	sort(a+1,a+4,cmp2);
	a[4].y=a[2].y;
	get(a[1],a[4]);
	get(a[2],a[4]);
	get(a[3],a[4]);
	cout<<tot<<'\n';
	for(int i=1;i<=tot;++i) cout<<t[i].a.x<<' '<<t[i].a.y<<' '<<t[i].b.x<<' '<<t[i].b.y<<'\n';
	return 0;
}
/*
0 0
2 3
3 2

*/