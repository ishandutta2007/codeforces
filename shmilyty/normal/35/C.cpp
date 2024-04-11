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
int n,m,k,cnt,L[800001],R[800001],tag[800001],t[1200001],p[200001],ok[200001];
array<int,2> ans,a[100001];
array<int,4> b[100001];//x y xx yy
std::vector<array<int,4>> q;//0: add 1: remove 2: observe
void build(int x,int l,int r)
{
	tag[x]=t[x]=0;
	if(l==r)
	{
		L[x]=p[l];
		R[x]=p[l+1]-1;
		if(R[x]-L[x]>2)
			ok[x]=3;
		else
			ok[x]=1<<(L[x]&1);
		return ;
	}
	int mid=(l+r)>>1,xx=x<<1;
	build(xx,l,mid);
	build(xx|1,mid+1,r);
	L[x]=L[xx];
	R[x]=R[xx|1];
}
void modify(int x,int l,int r,int ll,int rr,int v)
{
	int mid=(l+r)>>1,xx=x<<1;
	if(ll<=l&&r<=rr)
	{
		tag[x]+=v;
		t[x]+=v;
		return ;
	}
	if(tag[x])
	{
		int k=tag[x];
		tag[x]=0;
		tag[xx]+=k;
		tag[xx|1]+=k;
		t[xx]+=k;
		t[xx|1]+=k;
	}
	if(ll<=mid)
		modify(xx,l,mid,ll,rr,v);
	if(rr>mid)
		modify(xx|1,mid+1,r,ll,rr,v);
	if(t[xx]<t[xx|1])
	{
		t[x]=t[xx];
		ok[x]=ok[xx];
	}
	elif(t[xx]>t[xx|1])
	{
		t[x]=t[xx|1];
		ok[x]=ok[xx|1];
	}
	else
	{
		t[x]=t[xx];
		ok[x]=ok[xx]|ok[xx|1];
	}
}
array<int,2> query(int x,int l,int r,int ll,int rr)
{
	if(ll<=l&&r<=rr)
		return {t[x],ok[x]};
	int mid=(l+r)>>1,xx=x<<1;
	array<int,2>res={INF,0};
	if(tag[x])
	{
		int k=tag[x];
		tag[x]=0;
		tag[xx]+=k;
		tag[xx|1]+=k;
		t[xx]+=k;
		t[xx|1]+=k;
	}
	if(ll<=mid)
	{
		auto k=query(xx,l,mid,ll,rr);
		if(res[0]>k[0])
			res=k;
		elif(res[0]==k[0])
			res[1]|=k[1];
	}
	if(mid<rr)
	{
		auto k=query(xx|1,mid+1,r,ll,rr);
		if(res[0]>k[0])
			res=k;
		elif(res[0]==k[0])
		res[1]|=k[1];
	}
	return res;
}
bool check(int T)//1: haven't finished yet
{
	for(int i=1;i<=k;i++)
	{
		array<int,2> x={a[i][0]+a[i][1],a[i][0]-a[i][1]};
		b[i]={max(x[0]-T,2ll),max(x[1]-T,1-m),min(x[0]+T,n+m)+1,min(n-1,x[1]+T)+1};
		p[++cnt]=b[i][1];
		p[++cnt]=b[i][3];
	}
	p[++cnt]=1-m;
	p[++cnt]=n;
	sort(p+1,p+1+cnt);
	cnt=unique(p+1,p+1+cnt)-p-1;
	build(1,1,cnt-1);
	q.clear();
	q.push_back({2,1,0,1});
	q.push_back({n+m+1,1,0,1});
	for(int i=1;i<=k;i++)
	{
		// cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<" "<<b[i][3]<<endl;
		int x=lower_bound(p+1,p+1+cnt,b[i][1])-p;
		int y=lower_bound(p+1,p+1+cnt,b[i][3])-p-1;
		q.push_back({b[i][0],x,y,2});
		q.push_back({b[i][2],x,y,0});
	}
	sort(ALL(q));
	ans={2,0};
	// cout<<endl;
	for(int i=0;i+1<q.size();i++)
	{
		if(q[i][3]%2==0)
			modify(1,1,cnt-1,q[i][1],q[i][2],q[i][3]-1);
		// for(int j=1;j<cnt;j++)
			// cout<<query(1,1,cnt-1,j,j)[0]<<" ";
		// cout<<endl;
		// cout<<q[i][0]<<" "<<q[i][1]<<" "<<q[i][2]<<" "<<q[i][3]<<endl;
		int L=q[i][0],R=q[i+1][0]-1;
		if(L>R)
			continue;
		int L1=1,R1=cnt-1;
		//DL
		int l=upper_bound(p+1,p+1+cnt,2-R)-p-1,r=upper_bound(p+1,p+1+cnt,2-L)-p-1;
		// cout<<l<<" "<<r<<endl;
		l=max(l,1ll);
		r=max(r,0ll);
		L1=max(L1,r+1);
		if(l<=r&&!query(1,1,cnt-1,l,r)[0])
		{
			for(int j=l;j<=r;j++)
				if(!query(1,1,cnt-1,j,j)[0])
				{
					ans[1]=max(2-R,p[j]);
					ans[0]=2-ans[1];
					return 1;
				}
		}
		//DR
		l=upper_bound(p+1,p+1+cnt,L-2*m)-p-1,r=upper_bound(p+1,p+1+cnt,R-2*m)-p-1;
		// cout<<l<<" "<<r<<endl;
		l=max(l,1ll);
		r=max(r,0ll);
		L1=max(L1,r+1);
		if(l<=r&&!query(1,1,cnt-1,l,r)[0])
		{
			for(int j=l;j<=r;j++)
				if(!query(1,1,cnt-1,j,j)[0])
				{
					ans[1]=max(L-2*m,p[j]);
					ans[0]=ans[1]+2*m;
					return 1;
				}
		}
		//UR
		l=upper_bound(p+1,p+1+cnt,2*n-R)-p-1,r=upper_bound(p+1,p+1+cnt,2*n-L)-p-1;
		// cout<<l<<" "<<r<<endl;
		l=min(l,cnt);
		r=min(r,cnt-1);
		R1=min(R1,l-1);
		if(l<=r&&!query(1,1,cnt-1,l,r)[0])
		{
			for(int j=l;j<=r;j++)
				if(!query(1,1,cnt-1,j,j)[0])
				{
					ans[1]=max(2*n-R,p[j]);
					ans[0]=2*n-ans[1];
					return 1;
				}
		}
		//UL
		l=upper_bound(p+1,p+1+cnt,L-2)-p-1,r=upper_bound(p+1,p+1+cnt,R-2)-p-1;
		// cout<<l<<" "<<r<<endl;
		l=min(l,cnt);
		r=min(r,cnt-1);
		R1=min(R1,l-1);
		if(l<=r&&!query(1,1,cnt-1,l,r)[0])
		{
			for(int j=l;j<=r;j++)
				if(!query(1,1,cnt-1,j,j)[0])
				{
					ans[1]=max(L-2,p[j]);
					ans[0]=ans[1]+2;
					return 1;
				}
		}
		//mid
		if(L1>R1)
			continue;
		auto k=query(1,1,cnt-1,L1,R1);
		if(!k[0])
		{
			if(L!=R||(k[1]>>(L&1))&1)
			{
				for(int j=L1;j<=R1;j++)
					if(!query(1,1,cnt-1,j,j)[0])
					{
						ans={L,p[j]};
						if((ans[0]+ans[1])%2==0)
							return 1;
						if(ans[0]+1<=R)
						{
							ans[0]++;
							return 1;
						}
						if(ans[1]+1<=p[j+1])
						{
							ans[1]++;
							return 1;
						}
					}
			}
		}
	}
	return 0;
}
signed main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=k;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
	}
	// cout<<check(9)<<endl;
	// cout<<ans[0]<<" "<<ans[1]<<endl;
	int L=0,R=INF;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check(mid))
			L=mid+1;
		else
			R=mid-1;
	}
	L--;
	if(L<0)
	{
		puts("1 1");
		return 0;
	}
	check(L);
	cout<<(ans[0]+ans[1])/2<<" "<<(ans[0]-ans[1])/2;
	// cout<<L<<endl;
	// cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}