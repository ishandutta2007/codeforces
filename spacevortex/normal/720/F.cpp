#include<bits/stdc++.h>
#define lb(x) ((x)&(-x))
#define cle(x) memset(x,0,sizeof(x))
#define pb push_back
#define ls (rt<<1)
#define rs ((rt<<1)|1)
#define cmax(a,b) a=max(a,b)
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
const ll N=2e5+50,inf=2e10,inf2=9e18,Log=20;
ll n,K,S,cnt=0,W1,W2,C1,C2,zs=0,c1=0,c2=0,top=0,tot;
ll A[N],sum[N],pl[N],dy[N],vm1[Log+3][N],vm2[Log+3][N],lo[N];
struct Bit
{
	ll val[N];
	void update(ll x,ll w)
	{
		while(x<=cnt)
		{
			val[x]+=w;x+=lb(x);
		}
	}
	ll query(ll x)
	{
		ll ras=0;
		while(x>0)
		{
			ras+=val[x];x-=lb(x);
		}
		return ras;
	}
}bst,bst2;
///
ll solve(ll W,ll typ)
{
	ll i,bval,pos,ras=0;
	cle(bst.val);
	for(i=0;i<=n;i++)
	{
		if(i>0)
		{
			bval=sum[i]-W;
			pos=upper_bound(pl+1,pl+cnt+1,bval)-pl;
			pos--;
			if(typ==0) ras+=bst.query(pos);
			else ras+=bst.query(pos)*sum[i]-bst2.query(pos);
		}
		bst.update(dy[i],1);
		if(typ==1) bst2.update(dy[i],sum[i]);
	}
	return ras;
}
vector<ll> vec[N],vmi[N];
struct Data
{
	ll l,r,w;
}h[N];
bool cmp(const Data &a,const Data &b)
{
	return a.w<b.w;
}
// 
struct Segment_tree
{
	vector<ll> vec[N<<1];
	ll vmi[N<<1];
	void mup(ll rt){vmi[rt]=min(vmi[ls],vmi[rs]);}
	void insert(ll rt,ll l,ll r,ll x,ll w)
	{
		vec[rt].pb(w);
		if(l==r) {vmi[rt]=w;return ;}
		ll mid=(l+r)>>1;
		if(mid>=x) insert(ls,l,mid,x,w);
		else insert(rs,mid+1,r,x,w);
		mup(rt);
	}
	void query(ll rt,ll l,ll r,ll x,ll y,ll R)
	{
		if(l>=x&&r<=y)
		{
			ll vsi,i;
			vsi=vec[rt].size();
			for(i=0;i<vsi;i++)
			{
				h[++top]=(Data){vec[rt][i]+1,R,sum[R]-sum[vec[rt][i]]};
			}
			return ;
		}
		ll mid=(l+r)>>1;
		if(mid>=x) query(ls,l,mid,x,y,R);
		if(mid<y) query(rs,mid+1,r,x,y,R);
	}
	ll gmin(ll rt,ll l,ll r,ll x,ll y)
	{
		if(l>=x&&r<=y) return vmi[rt];
		ll mid=(l+r)>>1,ras=inf;
		if(mid>=x) ras=min(ras,gmin(ls,l,mid,x,y));
		if(mid<y) ras=min(ras,gmin(rs,mid+1,r,x,y));
		return ras;
	}
}sgt;
//2 
struct Segment_tree2
{
	ll siz[N<<1];
	ll query2(ll rt,ll l,ll r)
	{
		if(l==r) return l;
		ll mid=(l+r)>>1;
		if(siz[ls]<mid-l+1) return query2(ls,l,mid);
		else return query2(rs,mid+1,r);
	}
	ll query(ll rt,ll l,ll r,ll x,ll y)
	{
		if(l>=x&&r<=y)
		{
			if(siz[rt]<r-l+1) return query2(rt,l,r);
			else return 0;
		}
		ll mid=(l+r)>>1,ras=0;
		if(mid>=x) ras=query(ls,l,mid,x,y);
		if(ras==0&&mid<y) ras=query(rs,mid+1,r,x,y);
		return ras;
	}
	void chg(ll rt,ll l,ll r,ll x)
	{
		siz[rt]++;
		if(l==r) return; 
		ll mid=(l+r)>>1;
		if(mid>=x) chg(ls,l,mid,x);
		else chg(rs,mid+1,r,x);
	}
}sgt2;
set<ll> st;
//
ll qry(ll l,ll r,ll typ)
{
	ll ras,nas,p;
	if(l>r) return 0;
	ras=0;
	if(typ) ras+=sum[r]-sum[l-1];
	p=lo[r-l+1];
	nas=max(max(vm1[p][l],vm1[p][r-(1ll<<p)+1])-sum[l-1],0ll);
	if(typ==4) return nas;
	ras-=nas;
	nas=max(sum[r]-min(vm2[p][l-1],vm2[p][r-(1ll<<p)]),0ll);
	if(typ==3) return nas;
	ras-=nas;
	if(typ==0) ras=-ras;
	return ras;
}
ll bas=0,zas=0,has=0,gcn=0,ans=-inf2;
struct M_heap
{
	ll si;
	priority_queue<ll,vector<ll>,greater<ll> > q1,q2;
	void pop(ll x){q2.push(x);si--;}
	void push(ll x){q1.push(x);si++;}
	bool empty(){return si==0;}
	ll top(){while((!q1.empty())&&(!q2.empty())&&q1.top()==q2.top()){q1.pop();q2.pop();}return q1.top();}
}prq1;
struct M_heap2
{
	ll si;
	priority_queue<ll> q1,q2;
	void pop(ll x){q2.push(x);si--;}
	void push(ll x){q1.push(x);si++;}
	bool empty(){return si==0;}
	ll top(){while((!q1.empty())&&(!q2.empty())&&q1.top()==q2.top()){q1.pop();q2.pop();}return q1.top();}
}prq2;
void mswap();
void push(ll x){prq1.push(x);gcn++;has+=x;mswap();}
void del(ll x){if((!prq1.empty())&&prq1.top()<=x) prq1.pop(x),gcn--,has-=x;else prq2.pop(x);mswap();}
void mswap()
{
	ll x,y;
	while((!prq1.empty())&&(!prq2.empty())&&prq1.top()<prq2.top())
	{
		x=prq1.top();y=prq2.top();
		prq1.pop(x);prq1.push(y);
		prq2.pop(y);prq2.push(x);
		has+=y-x;
	}
}
void balance()
{
	ll x;
	while(gcn<tot-S)
	{
		gcn++;
		x=prq2.top();has+=x;
		prq1.push(x);prq2.pop(x);
	}
	while(gcn>tot-S)
	{
		gcn--;
		x=prq1.top();has-=x;
		prq1.pop(x);prq2.push(x);
	}
	mswap();
}
//
void update(ll L,ll R)
{
	ll pos,a,b;
	set<ll>::iterator bi,ni;
	while(1)
	{
		pos=sgt2.query(1,1,n,L,R);
		if(pos==0) break;
		sgt2.chg(1,1,n,pos);
		a=b=-1;
		bi=st.find(pos);
		tot--;zas-=A[pos];
		if(bi!=st.begin()){ni=bi;ni--;a=*ni;}
		ni=bi;ni++;if(ni!=st.end()){b=*ni;}
		if(a!=-1&&b!=-1)
		{
			del(qry(a+1,pos-1,1));has-=qry(a+1,pos-1,0);
			del(qry(pos+1,b-1,1));has-=qry(pos+1,b-1,0);
			push(qry(a+1,b-1,1));has+=qry(a+1,b-1,0);
		}
		if(a!=-1&&b==-1)
		{
			//puts("Y");
			del(qry(a+1,pos-1,1));has-=qry(a+1,pos-1,0);
			has-=qry(pos+1,n,4);has+=qry(a+1,n,4);
		}
		if(a==-1&&b!=-1)
		{
			del(qry(pos+1,b-1,1));
			has-=qry(pos+1,b-1,0);
			has-=qry(1,pos-1,3);
			has+=qry(1,b-1,3);
		}
		if(a==-1&&b==-1)
		{
			has-=qry(1,pos-1,3)+qry(pos+1,n,4);
		}
		st.erase(pos);
	}
}
int main()
{
	//puts("OK");
	ll i,j,len,l,r,mid,bw,pos,vsi,a,b,L,bx;
	n=rd();K=rd();
	pl[++cnt]=0;
	for(i=1;i<=n;i++) 
	{
		A[i]=rd();
		zas+=A[i];
		sum[i]=sum[i-1]+A[i];
		pl[++cnt]=sum[i];
	}
	//max
	for(i=0;i<=n;i++) vm1[0][i]=vm2[0][i]=sum[i];
	for(i=1;i<=Log;i++)
	{
		len=(1ll<<i);mid=(len>>1);
		for(j=0;j<=n-len+1;j++)
		{
			vm1[i][j]=max(vm1[i-1][j],vm1[i-1][j+mid]);
			vm2[i][j]=min(vm2[i-1][j],vm2[i-1][j+mid]);
		}
	}
	for(i=2;i<=n+5;i++) lo[i]=lo[i>>1]+1;
	sort(pl+1,pl+cnt+1);
	cnt=unique(pl+1,pl+cnt+1)-pl-1;
	for(i=0;i<=n;i++)
	{
		dy[i]=lower_bound(pl+1,pl+cnt+1,sum[i])-pl;
	}
	S=max(K-n,0ll);
	l=-inf;r=inf;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(solve(mid,0)>=K) l=mid;
		else r=mid-1;
	}
	W1=l;
	C1=K-solve(W1+1,0);
	l=-inf;r=inf;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(solve(mid,0)>=S) l=mid;
		else r=mid-1;
	}
	W2=l;
	C2=solve(W2,0)-S;
	bas=solve(W2+1,1)+(S-solve(W2+1,0))*W2;
	if(W1==W2) C1=K-S,C2=0;
	tot=n;
	for(i=1;i<=n;i++) st.insert(i);
	memset(sgt.vmi,0x3f,sizeof(sgt.vmi));
	for(i=1;i<n;i++) prq1.push(0),gcn++;
	for(i=0;i<=n;i++)
	{
		if(i>0)
		{
			L=inf;
			bw=sum[i]-W1;
			pos=lower_bound(pl+1,pl+cnt+1,bw)-pl;
			if(pos<=cnt&&pl[pos]==bw)
			{
				vsi=vec[pos].size();
				for(j=vsi-1;j>=0&&c1<C1;j--)
				{
					c1++;
					h[++top]=(Data){vec[pos][j]+1,i,sum[i]-sum[vec[pos][j]]};
				}
				
			}
			b=pos-1;
			bw=sum[i]-W2;
			pos=lower_bound(pl+1,pl+cnt+1,bw)-pl;
			if(pos<=cnt&&pl[pos]==bw) 
			{
				vsi=vec[pos].size();
				for(j=vsi-1;j>=0&&c2<C2;j--)
				{
					c2++;
					h[++top]=(Data){vec[pos][j]+1,i,sum[i]-sum[vec[pos][j]]};
				}
				if(j>=0) L=vmi[pos][j];
				a=pos+1;
			}
			else a=pos;
			bx=pos-1;
			if(a<=b) 
			{
				sgt.query(1,1,cnt,a,b,i);
			}
			if(bx>=1) L=min(L,sgt.gmin(1,1,cnt,1,bx));
			L++;
			if(L<=i) update(L,i);
		}
		vec[dy[i]].pb(i);vmi[dy[i]].pb(i);
		vsi=vmi[dy[i]].size();
		if(vsi>1) vmi[dy[i]][vsi-1]=min(vmi[dy[i]][vsi-1],vmi[dy[i]][vsi-2]);
		sgt.insert(1,1,cnt,dy[i],i);		
	}
	S=K-S;
	sort(h+1,h+top+1,cmp);
	while(S>=0)
	{
		if((S!=0&&tot>=S)||(S==0&&tot==0))
		{
			balance();
			ans=max(ans,bas+zas+has);
		}
		if(S>0) 
		{
			update(h[S].l,h[S].r);
			bas+=h[S].w;
		}
		S--;
	}
	printf("%I64d",ans);
}