#include<bits/stdc++.h>
using namespace std;
typedef long double db;
struct Node{int id;db w;};
struct Comp1
{
	bool operator ()(const Node &a,const Node &b)
	{
		if(a.w!=b.w) return a.w<b.w;
		else return a.id<b.id;
	}
};
set<Node,Comp1> s1;
struct Comp2
{
	bool operator ()(const Node &a,const Node &b)
	{
		if(a.w!=b.w) return a.w>b.w;
		else return a.id<b.id;
	}
};
set<Node,Comp2> s2;
const int N=2e5+50;
int n,t,Q;
db ans=0;
db p[N];
int l[N],c[N];
db qry(int id,int m)
{
	return (db)p[id]*l[id]/((db)(l[id]+m)*(l[id]+m-1));
}
void update(int id,int d1,int d2)
{
	if(c[id]>0) s1.erase((Node){id,qry(id,c[id])});
	if(c[id]<l[id]) s2.erase((Node){id,qry(id,c[id]+1)});
	ans-=(db)p[id]*c[id]/(c[id]+l[id]);
	l[id]+=d1;c[id]+=d2;t-=d2;
	ans+=(db)p[id]*c[id]/(c[id]+l[id]);
	if(c[id]>0) s1.insert((Node){id,qry(id,c[id])});
	if(c[id]<l[id]) s2.insert((Node){id,qry(id,c[id]+1)});
}
int main()
{
	ios::sync_with_stdio(false);
	int i,der,id;
	Node bno;
	cin>>n>>t>>Q;
	for(i=1;i<=n;i++) cin>>p[i];
	for(i=1;i<=n;i++) cin>>l[i];
	for(i=1;i<=n;i++) s2.insert((Node){i,qry(i,1)});
	while(t>0&&(!s2.empty()))
	{
		bno=*s2.begin();
		update(bno.id,0,1);
	}
	//printf("U%d %lf\n",t,ans);return 0;
	while(Q--)
	{
		cin>>der>>id;
		if(der==2) der=-1;
		if(c[id]>0) update(id,0,-1);
		update(id,der,0);
		if(!s1.empty())
		{
			bno=*s1.begin();update(bno.id,0,-1);
		}
		
		while(t>0&&(!s2.empty()))
		{
			bno=*s2.begin();
			update(bno.id,0,1);
		}
		printf("%.10lf\n",(double)ans);
	}
	return 0;
}