#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,cnt,R[300001],q[300001],ty[300001];
array<int,2> a[300001];
vector<int> v,t[1200001];
vector<double> t1[1200001];
bool cmp(int x,int y)
{
	if(a[x]==a[y])
		return x<y;
	return a[x]<a[y];
}
double tan(int x,int y)
{
	return 1.0*(a[x][1]-a[y][1])/(a[y][0]-a[x][0]);
}
void add(int x,int y)
{
//	cout<<"add: "<<x<<" "<<y<<endl;
	while(!t[x].empty()&&a[t[x].back()][0]==a[y][0]&&a[t[x].back()][1]<=a[y][1])
	{
		t[x].pop_back();
		if(!t[x].empty())
			t1[x].pop_back();
	}
	while(t[x].size()>1&&tan(t[x][t[x].size()-2],y)>tan(t[x][t[x].size()-1],y))
	{
		t[x].pop_back();
		t1[x].pop_back();
	}
	if(!t[x].empty())
		t1[x].push_back(tan(t[x].back(),y));
	t[x].push_back(y);
}
void modify(int x,int l,int r,int ll,int rr,int v)
{
	if(ll<=l&&r<=rr)
	{
		add(x,v);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify(x<<1,l,mid,ll,rr,v);
	if(mid<rr)
		modify(x<<1|1,mid+1,r,ll,rr,v);
}
int ask(int x,int v)
{
	if(t[x].empty())
		return -INF;
	if(t1[x].empty())
		return a[t[x][0]][0]*v+a[t[x][0]][1];
	int it=lower_bound(ALL(t1[x]),1.0*v)-t1[x].begin();
	return a[t[x][it]][0]*v+a[t[x][it]][1];
}
int query(int x,int l,int r,int pos,int v)
{
	int res=ask(x,v);
	if(l==r)
		return res;
	int mid=(l+r)>>1;
	if(mid>=pos)
		return max(res,query(x<<1,l,mid,pos,v));
	return max(res,query(x<<1|1,mid+1,r,pos,v));
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		ty[i]=read();
		if(ty[i]==1)
		{
			int x=read(),y=read();
			a[i]={x,y};
			R[i]=n;
			v.push_back(i);
		}
		elif(ty[i]==2)
			R[read()]=i;
		else
			q[i]=read();
	}
	sort(ALL(v),cmp);
	for(int i:v)
	{
//		cout<<i<<endl;
		modify(1,1,n,i,R[i],i);
	}
//	for(int i=1;i<=2*n;i++)
//		cout<<t[i].size()<<endl;
	for(int i=1;i<=n;i++)
		if(ty[i]==3)
		{
//			cout<<i<<endl;
			int x=query(1,1,n,i,q[i]);
			if(x==-INF)
				puts("EMPTY SET");
			else
				cout<<x<<'\n';
		}
	return 0;
}