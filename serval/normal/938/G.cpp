#include <cstdio>

using namespace std;

const int maxn=200005;
const int maxm=400005;

const int hash_mod=600043;

const int qlog=20;

const int inf=0x3fffffff;

struct list
{
	int h,cur;
	int nx[maxm];
	void insert(int v){nx[v]=h;h=v;}
	void reset(){cur=h;}
	void next(){h=nx[cur];nx[cur]=0;cur=h;}
	int value(){return cur;}
	bool empty(){return cur==0;}
};

list L[qlog],R[qlog];

struct edge
{
	int u,v,w,st,ed;
};

edge G[maxm];

struct query
{
	int u,v;
};

query Q[maxn];

struct hash
{
	int x[hash_mod],y[hash_mod];
	int pos[hash_mod];
	int hash_func(int u,int v)
	{
		return (int)(((long long)u*17ll+(long long)v*191ll)%hash_mod);
	}
	void insert(int u,int v,int p)
	{
		int h=hash_func(u,v);
		int jump=0;
		while (pos[h]&&(x[h]!=u||y[h]!=v))
		{
			jump++;
			h=((long long)h+(long long)jump*(long long)jump)%hash_mod;
		}
		if (x[h]!=u||y[h]!=v)
		{
			x[h]=u;
			y[h]=v;
		}
		pos[h]=p;
	}
	int query(int u,int v)
	{
		int h=hash_func(u,v);
		int jump=0;
		while (pos[h]&&(x[h]!=u||y[h]!=v))
		{
			jump++;
			h=((long long)h+(long long)jump*(long long)jump)%hash_mod;
		}
		return pos[h];
	}
};

hash H;

struct ufs
{
	int f[maxn],w[maxn],rk[maxn];
	int stk[maxm],cur;
	int find(int u)
	{
		while (f[u])
			u=f[u];
		return u;
	}
	int dist(int u)
	{
		int ret=0;
		while (u)
		{
			ret^=w[u];
			u=f[u];
		}
		return ret;
	}
	void merge(int u,int v,int c)
	{
		if (rk[u]>rk[v])
			u^=v^=u^=v;
		if (rk[u]==rk[v])
		{
			stk[++cur]=-v;
			rk[v]++;
		}
		stk[++cur]=u;
		f[u]=v;
		w[u]=c;
	}
	int current(){return cur;}
	void restore(int p)
	{
		while (cur>p)
		{
			if (stk[cur]<0)
				rk[-stk[cur]]--;
			else
			{
				f[stk[cur]]=0;
				w[stk[cur]]=0;
			}
			cur--;
		}
	}
};

ufs S;

struct linear_basis
{
	int b[30];
	void insert(int u)
	{
		for (int i=29;i>=0;i--)
			if (u&(1<<i))
			{
				u^=b[i];
				if (b[i]==0)
				{
					b[i]=u;
					return;
				}
			}
	}
	int reduce(int u)
	{
		for (int i=29;i>=0;i--)
			if (u&(1<<i))
				u^=b[i];
		return u;
	}
	void copy(linear_basis &B)
	{
		for (int i=0;i<30;i++)
			b[i]=B.b[i];
	}
};

linear_basis I[qlog];

int n,m,q;
int i,j,k,v;

int opt;

int cnt,qt;

void cdq(int ql,int qr,int dep,list &E,linear_basis &B)
{
	int ver=S.current();
	int mid=(ql+qr)>>1;
	for (E.reset();!E.empty();E.next())
	{
		v=E.value();
		if (G[v].st>G[v].ed)
			continue;
		if (G[v].st<=ql&&qr<=G[v].ed)
		{
			i=S.find(G[v].u);
			j=S.find(G[v].v);
			k=S.dist(G[v].u)^S.dist(G[v].v)^G[v].w;
			if (i!=j)
				S.merge(i,j,k);
			else
				B.insert(k);
		}
		else
		{
			if (G[v].st<=mid&&G[v].ed>=ql)
				L[dep].insert(v);
			if (G[v].ed>mid&&G[v].st<=qr)
				R[dep].insert(v);
		}
	}
	if (ql==qr)
		printf("%d\n",B.reduce(S.dist(Q[ql].u)^S.dist(Q[ql].v)));
	else
	{
		I[dep].copy(B);
		cdq(ql,mid,dep+1,L[dep],I[dep]);
		I[dep].copy(B);
		cdq(mid+1,qr,dep+1,R[dep],I[dep]);
	}
	S.restore(ver);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		cnt++;
		scanf("%d%d%d",&G[cnt].u,&G[cnt].v,&G[cnt].w);
		G[cnt].st=0;
		G[cnt].ed=inf;
		H.insert(G[cnt].u,G[cnt].v,cnt);
		L[0].insert(cnt);
	}
	scanf("%d",&q);
	for (i=1;i<=q;i++)
	{
		scanf("%d",&opt);
		if (opt==1)
		{
			cnt++;
			scanf("%d%d%d",&G[cnt].u,&G[cnt].v,&G[cnt].w);
			G[cnt].st=qt+1;
			G[cnt].ed=inf;
			H.insert(G[cnt].u,G[cnt].v,cnt);
			L[0].insert(cnt);
		}
		if (opt==2)
		{
			scanf("%d%d",&j,&k);
			G[H.query(j,k)].ed=qt;
		}
		if (opt==3)
		{
			qt++;
			scanf("%d%d",&Q[qt].u,&Q[qt].v);
		}
	}
	cdq(1,qt,1,L[0],I[0]);
	return 0;
}