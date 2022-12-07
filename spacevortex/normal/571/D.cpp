#include<bits/stdc++.h>
#define vc vector<ll>
#define pb push_back
using namespace std;
typedef long long ll;
const ll N=1e6+50;
ll n,Q,m=0,top=0;
ll bel[N],zrt[N],mgt[N],val[N],qas[N],tag[N],dy[N];
char s[5];
struct Act
{
	ll op,x,y;
}act[N];
struct Query
{
	ll t,x,id;
}q[N];
vc vec[N];
ll qry(ll x)
{
	if(val[bel[x]]>mgt[x]) return val[bel[x]];
	else return zrt[x];
}
bool cmp(const Query &a,const Query &b)
{
	return a.t<b.t;
}
int main()
{
	ll i,j,x,id1,id2,si1,si2,w;
	scanf("%lld%lld",&n,&Q);
	for(i=1;i<=Q;i++)
	{
		scanf("%s",s+1);
		if(s[1]=='U') 
		{
			act[i].op=1;
			scanf("%lld%lld",&act[i].x,&act[i].y);
		}
		else if(s[1]=='M') 
		{
			act[i].op=2;
			scanf("%lld%lld",&act[i].x,&act[i].y);
		}
		else if(s[1]=='A') 
		{
			act[i].op=3;
			scanf("%lld",&act[i].x);
		}
		else if(s[1]=='Z') 
		{
			act[i].op=4;
			scanf("%lld",&act[i].x);
		}
		else 
		{
			act[i].op=5;
			scanf("%lld",&act[i].x);
		}
	}
	memset(zrt,-1,sizeof(zrt));
	memset(mgt,-1,sizeof(mgt));
	memset(val,-1,sizeof(val));
	for(i=1;i<=n;i++) bel[i]=i,dy[i]=i,vec[i].pb(i);
	for(i=1;i<=Q;i++)
	{
		if(act[i].op==2)
		{
			id1=dy[act[i].x];id2=dy[act[i].y];
			si1=vec[id1].size();si2=vec[id2].size();
			if(si1<si2) swap(id1,id2),swap(si1,si2),swap(dy[act[i].x],dy[act[i].y]);
			for(j=0;j<si2;j++)
			{
				x=vec[id2][j];
				w=qry(x);
				zrt[x]=w;mgt[x]=i;bel[x]=id1;
				vec[id1].pb(x);
			}
		}
		if(act[i].op==4) val[dy[act[i].x]]=i;
		if(act[i].op==5)
		{
			q[++m]=(Query){i,act[i].x,i};
			w=qry(act[i].x);
			//printf("#%lld  %lld\n",i,w);
			if(w>0) q[++m]=(Query){w,act[i].x,-i};
		}
	}
	sort(q+1,q+m+1,cmp);
	top=0;
	memset(val,0,sizeof(val));
	memset(tag,0,sizeof(tag));
	for(i=1;i<=n;i++) bel[i]=i,dy[i]=i,vec[i].clear(),vec[i].pb(i);
	for(i=1;i<=Q;i++)
	{
		if(act[i].op==1)
		{
			id1=dy[act[i].x];id2=dy[act[i].y];
			si1=vec[id1].size();si2=vec[id2].size();
			if(si1<si2) swap(id1,id2),swap(si1,si2),swap(dy[act[i].x],dy[act[i].y]);
			for(j=0;j<si2;j++)
			{
				x=vec[id2][j];
				val[x]+=tag[id2]-tag[id1];
				bel[x]=id1;
				vec[id1].pb(x);
			}
		}
		if(act[i].op==3)
		{
			tag[dy[act[i].x]]+=vec[dy[act[i].x]].size();
		}
		while(top<m&&q[top+1].t<=i)
		{
			top++;
			w=val[q[top].x]+tag[bel[q[top].x]];
			if(q[top].id>0) qas[q[top].id]+=w;
			else qas[-q[top].id]-=w;
		}
	}
	for(i=1;i<=Q;i++)
	{
		if(act[i].op==5) printf("%lld\n",qas[i]);
	}
	return 0;
}