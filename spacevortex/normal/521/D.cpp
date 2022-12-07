#include<bits/stdc++.h>
#define pb push_back
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
const ll N=1e5+50;
ll K,n,m,tot=0;
ll a[N],f[N],g[N],qop[N],qid[N];
struct Num
{
	ll a,b;
	Num(){}
	Num(ll _a,ll _b){a=_a,b=_b;}
};
bool operator >(Num x,Num y)
{
	return (x.a-x.b)*y.b>(y.a-y.b)*x.b;
}
struct Node
{
	ll id;Num w;
	Node(){}
	Node(ll _id,Num _w){id=_id;w=_w;}
}p[N];
bool cmp(const Node &a,const Node &b)
{
	return a.w>b.w;
}
bool cmp2(const ll &a,const ll &b)
{
	return qop[a]<qop[b];
}
vector<Node> vec[N];
vector<ll> h[N];
int main()
{
	ll i,j,sum,op,id,w,vsi,num;
	K=rd();n=rd();m=rd();
	for(i=1;i<=K;i++) a[i]=rd();
	memset(f,-1,sizeof(f));
	for(i=1;i<=n;i++)
	{
		op=rd();id=rd();w=rd();
		qop[i]=op;qid[i]=id;
		if(op==1)
		{
			if(w>f[id]) f[id]=w,g[id]=i;
		}
		else if(op==2)
		{
			vec[id].pb(Node(i,Num(w,1)));
		}
		else
		{
			p[++tot]=Node(i,Num(w,1));
		}
	}
	for(i=1;i<=K;i++)
	{
		if(f[i]>a[i])
		{
			vec[id].pb(Node(g[i],Num(f[i]-a[i],1)));
		}
	}
	for(i=1;i<=K;i++)
	{
		sort(vec[i].begin(),vec[i].end(),cmp);
		vsi=vec[i].size();
		sum=a[i];
		for(j=0;j<vsi;j++)
		{
			id=vec[i][j].id;w=vec[i][j].w.a;
			p[++tot]=Node(id,Num(w+sum,sum));
			sum+=w;
		}
	}
	sort(p+1,p+tot+1,cmp);
	num=min(tot,m);
	printf("%lld\n",num);
	for(i=1;i<=num;i++) h[qid[p[i].id]].pb(p[i].id);
	for(i=1;i<=K;i++)
	{
		sort(h[i].begin(),h[i].end(),cmp2);
		vsi=h[i].size();
		for(j=0;j<vsi;j++) printf("%lld ",h[i][j]);
	}
	return 0;
}