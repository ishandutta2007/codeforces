#include<bits/stdc++.h>
#define pb push_back
#define bel(x) ((x-1)/blo+1)
using namespace std;
typedef long long ll;
const ll N=1e5+50,blo=330,D1=blo+5,D2=N/D1+5;
ll n,len,Q,tot=0,cur=0,num,top=0;
char s[N];
ll id[N],nxt[N][30],fail[N],dfn[N],low[N],dfn2[N],low2[N],qas[N],val[D2],dy[N];
int cnt[N][D2];
ll L[D2],R[D2],tag[D2],a[N];
struct Act
{
	ll qi,t,x,tp;
}q[N<<2];
queue<ll> que;
vector<ll> e[N];
bool cmp(const Act &a,const Act &b){return a.t<b.t;}
void build()
{
	ll x,i;
	for(i=0;i<26;i++)
	{
		if(nxt[0][i]) que.push(nxt[0][i]);
	}
	while(!que.empty())
	{
		x=que.front();que.pop();
		for(i=0;i<26;i++)
		{
			if(nxt[x][i]) que.push(nxt[x][i]),fail[nxt[x][i]]=nxt[fail[x]][i];
			else nxt[x][i]=nxt[fail[x]][i];
		}
	}
}
void dfs(ll x)
{
	if(x) dfn[x]=++cur,dy[cur]=x;
	for(ll v:e[x]) dfs(v);
	low[x]=cur;
}
void srh(ll x)
{
	ll i,j,v;
	if(x) dfn2[x]=++cur;
	if(x) cnt[x][bel(dfn[x])]++;
	for(i=0;i<26;i++)
	{
		if((x==0&&nxt[x][i]==0)||(x>0&&nxt[x][i]==nxt[fail[x]][i])) continue;
		v=nxt[x][i];
		for(j=1;j<=num;j++) cnt[v][j]=cnt[x][j];
		srh(v);
	}
	low2[x]=cur;
}
void add(ll x,ll d)
{
	ll id;
	////printf("add%lld %lld\n",x,d);
	id=bel(x);
	tag[id]+=d;a[x]+=d;
}
int main()
{
	ll i,j,k,c,now,l,r,x,nx,nas,pos;
	scanf("%lld%lld",&n,&Q);
	
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		now=0;
		for(j=1;j<=len;j++)
		{
			c=s[j]-'a';
			if(!nxt[now][c]) nxt[now][c]=++tot;
			now=nxt[now][c];
		}
		id[i]=now;
	}
	build();
	//printf("tot%lld\n",tot);
	for(i=1;i<=tot;i++) ////printf("#%lld %lld\n",i,fail[i]);
	for(i=1;i<=tot;i++) e[fail[i]].pb(i);
	num=(tot-1)/blo+1;
	for(i=1;i<=num;i++) L[i]=(i-1)*blo+1,R[i]=min(i*blo,tot);
	cur=0;dfs(0);
	cur=0;srh(0);
	for(i=1;i<=Q;i++)
	{
		scanf("%lld%lld%lld",&l,&r,&x);
		q[++top]=(Act){i,r,x,1ll};
		q[++top]=(Act){i,l-1,x,-1ll};
	}
	now=0;
	sort(q+1,q+top+1,cmp);
	for(i=1;i<=top;i++)
	{
		while(now<q[i].t) 
		{
			now++;
			//printf("INS%lld\n",now);
			x=id[now];
			l=dfn[x];r=low[x];
			//printf("x%lld l%lld r%lld\n",x,l,r);
			//printf("H%lld %lld\n",L[1],R[1]);
			for(j=1;j<=num;j++)
			{
				if(L[j]>=l&&R[j]<=r) val[j]++;
				else if(R[j]>=l||L[j]<=r)
				{
					for(k=max(l,L[j]);k<=min(r,R[j]);k++)
					{
						nx=dy[k];
						//printf("nx%lld  %lld %lld %lld\n",nx,dfn2[nx],low2[nx],tag[1]);
						add(dfn2[nx],1);
						//printf("nx%lld  %lld %lld %lld\n",nx,dfn2[nx],low2[nx],tag[1]);
						if(low2[nx]<tot) add(low2[nx]+1,-1);
						//printf("nx%lld  %lld %lld %lld\n",nx,dfn2[nx],low2[nx],tag[1]);
					}
				} 
			}
		}
		x=id[q[i].x];pos=dfn2[x];
		nas=0;
		//printf("U%lld %lld\n",dfn2[x],tag[1]);
		//////printf("P%lld\n",cnt[x][1]);
		for(j=1;j<=num;j++) nas+=cnt[x][j]*val[j];
		for(j=1;j<=num;j++)
		{
			if(L[j]<=pos) 
			{
				if(R[j]<=pos) nas+=tag[j];
				else 
				{
					for(k=L[j];k<=pos;k++) nas+=a[k];
				}
			} 
		}
		//printf("Query %lld  %lld\n",q[i].qi,nas);
		qas[q[i].qi]+=nas*q[i].tp;
	}
	for(i=1;i<=Q;i++) printf("%lld\n",qas[i]);
	return 0;
}