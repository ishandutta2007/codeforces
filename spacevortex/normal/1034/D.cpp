#include<bits/stdc++.h>
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
const ll N=3e5+50,inf=(ll)1e9+5;
ll n,K,top=0,cur,L,R,sum,now,val;
ll a[N],b[N],f[N];
struct Node
{
	ll l,r,id;
	bool operator <(const Node &a)const
	{
		if(l!=a.l) return l<a.l;
		else return id<a.id;
	}
};
set<Node> st;
struct Act
{
	ll t,id,der;
}stk[N*4];
bool ins(Node bno)
{
	set<Node> ::iterator ni;
	Node p;
	ni=st.lower_bound(bno);
	if(ni!=st.end())
	{
		p=*ni;
		if(p.l<bno.r)
		{
			stk[++top]=(Act){cur,p.id,p.l-min(bno.r,p.r)};
			st.erase(p);
			if(p.r>bno.r) st.insert((Node){bno.r,p.r,p.id});
			return 0;
		}
	}
	if(ni!=st.begin())
	{
		ni--;p=*ni;
		if(p.r>bno.l)
		{
			stk[++top]=(Act){cur,p.id,bno.l-min(bno.r,p.r)};
			st.erase(p);
			st.insert((Node){p.l,bno.l,p.id});
			if(p.r>bno.r) st.insert((Node){bno.r,p.r,p.id});
			return 0;
		}
	}
	st.insert(bno);
	return 1;
}
void chg(ll id,ll der)
{
	f[id]+=der;
	if(id<L) now+=id*der;
	else now+=L*der,sum+=der,val+=der;
}
ll query(ll W,ll opt)
{
	ll num=0,ans=0;
	ll pos;
	now=0;val=0;
	L=1;R=0;pos=0;
	sum=0;
	memset(f,0,sizeof(f));
	for(R=1;R<=n;R++)
	{
		while(pos<top&&stk[pos+1].t==R)
		{
			pos++;chg(stk[pos].id,stk[pos].der);
		}
		while(L<R&&val-f[L]>=W) 
		{
			sum-=f[L];
			now+=sum;
			val-=f[L];
			L++;
		}
		//printf("R%lld  L%lld val%lld\n",R,L,val);
		//printf("F%lld  %lld\n",f[1],f[2]);
		if(val>=W) 
		{
			num+=L;
			ans+=now;
		}
	}
	if(opt==0) return num;
	else return ans-W*(num-K);
}
int main()
{
	ll i,sl,sr,mid,val,ans;
	n=rd();K=rd();
	for(i=1;i<=n;i++)
	{
		a[i]=rd();b[i]=rd();
	}
	for(i=1;i<=n;i++)
	{
		cur=i;
		stk[++top]=(Act){cur,i,b[i]-a[i]};
		while(ins((Node){a[i],b[i],i})==0);
	}
	//for(i=1;i<=top;i++) printf("#%lld  %lld %lld %lld\n",i,stk[i].t,stk[i].id,stk[i].der);
	//printf("Query %lld\n",query(4,0));
	//return 0;
	sl=1;sr=inf;
	while(sl<sr)
	{
		mid=(sl+sr+1)>>1;
		val=query(mid,0);
		if(val>=K) sl=mid;
		else sr=mid-1;
	}
	ans=query(sl,1);
	printf("%lld",ans);
	return 0;
}