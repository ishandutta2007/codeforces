#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
struct node{
	int to,nxt,cap;
}e[50001];
int n,k,cnt,tot,one,n1,n2,sum,odd[101],eve[101],h[301],lev[301],lst[301],p[200001];
vector<int> pri;
array<int,3> a[101];
array<int,2> b[101];
void add(int x,int y,int v)
{
//	if(v!=INF)
//		sum+=v;
	e[++cnt]={y,h[x],v};
	h[x]=cnt;
}
void bfs()
{
	for(int i=1;i<=tot+2;i++)
		lev[i]=-1;
	queue<int> q;
	q.push(tot+1);
	lev[tot+1]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=h[x];~i;i=e[i].nxt)
			if(e[i].cap>0&&lev[e[i].to]==-1)
			{
				lev[e[i].to]=lev[x]+1;
				q.push(e[i].to);
			}
	}
}
int dfs(int x,int y,int now)
{
//	cout<<x<<" "<<y<<" "<<now<<endl;
	if(x==y)
		return now;
	for(int &i=lst[x];~i;i=e[i].nxt)
	{
		node &E=e[i];
		if(E.cap>0&&lev[E.to]==lev[x]+1)
		{
			int d=dfs(E.to,y,min(now,E.cap));
//			cout<<d<<endl;
			if(d)
			{
				E.cap-=d;
				e[i^1].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int flow()
{
	int res=0;
	while(1)
	{
		bfs();
		if(lev[tot+2]<0)
			return res;
//		for(int i=1;i<=tot+2;i++)
//			cout<<lev[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=tot+2;i++)
			lst[i]=h[i];
		int f=0;
		while(f=dfs(tot+1,tot+2,INF))
			res+=f;
	}
}
bool ispri(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 1;
	return 0;
}
bool check(int x)
{
	one=tot=sum=n1=n2=0;
	cnt=-1;
	for(int i=1;i<=n;i++)
		if(a[i][0]<=x)
		{
			if(a[i][2]==1)
			{
				if(!one)
				{
					b[++tot][1]=1;
					one=tot;
				}	
				b[one][0]=max(b[one][0],a[i][1]);
			}
			else
				b[++tot]={a[i][1],a[i][2]};
		}
//	cout<<tot<<endl;
	if(!tot)
		return 0;
	for(int i=1;i<=tot;i++)
		if(b[i][1]&1)
			odd[++n1]=i;
		else
			eve[++n2]=i;
	for(int i=1;i<=tot;i++)
		sum+=b[i][0];
	for(int i=1;i<=tot+3;i++)
		h[i]=-1;
	for(int i=1;i<=n1;i++)
	{
		add(tot+1,odd[i],b[odd[i]][0]);
		add(odd[i],tot+1,0);
//		cout<<tot+1<<" "<<odd[i]<<" "<<b[odd[i]][0]<<endl;
	}
//	puts("1");
	for(int i=1;i<=n2;i++)
	{
		for(int l=1;l<=n1;l++)
			if(!ispri(b[odd[l]][1]+b[eve[i]][1]))
			{
//				cout<<odd[l]<<" "<<eve[i]<<" "<<b[eve[i]][0]<<endl;
				add(odd[l],eve[i],INF);
				add(eve[i],odd[l],0);
			}
		add(eve[i],tot+2,b[eve[i]][0]);
		add(tot+2,eve[i],0);
//		cout<<eve[i]<<" "<<tot+2<<" 1000000"<<endl;
	}
	int fl=flow();
//	cout<<"ans="<<sum<<" "<<fl<<endl;
	return ((sum-fl)>=k);
}
signed main()
{
	for(int i=2;i<=2e5;i++)
	{
		if(!p[i])
			pri.push_back(i);
		for(int l:pri)
		{
			if(l*i>2e5)
				break;
			p[l*i]=1;
			if(i%l==0)
				break;
		}
	}
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={z,x,y};
	}
//	cout<<check(2)<<endl;
	if(!check(n+1))
	{
		puts("-1");
		return 0;
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
//		cout<<mid<<" "<<check(mid)<<endl;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l;
	return 0;
}