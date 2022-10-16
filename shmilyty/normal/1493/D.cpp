#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
vector<pair<int,int> > s[N];
const int mod=1e9+7;
struct node{
	int ls,rs,val;
} tr[N*70]; 
int tot,n,q,np[N],p[N],rt[N],cnt;
ll ans=1;
void pushup(int p)
{
	tr[p].val=min(tr[tr[p].ls].val,tr[tr[p].rs].val);
}
void update(int p,int l,int r,int x,int k) 
{
	if(l==r) 
	{
		tr[p].val+=k; 
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) 
	{
		if(tr[p].ls==0)
			tr[p].ls=++tot;
    	update(tr[p].ls,l,mid,x,k);
	} 
	else 
	{
		if(tr[p].rs==0)
			tr[p].rs=++tot;
    	update(tr[p].rs,mid+1,r,x,k);
	}
	pushup(p);
}
ll qp(ll x,ll y) 
{
	if(x==1)
		return 1;
	if(y==0)
		return 1;
	if(y==1)
		return x;
	ll res=qp(x,y/2);
	(res*=res)%=mod;
	if(y&1)
		(res*=x)%=mod;
	return res;
}
int minn(int x)
{
	return tr[x].val;
}
void modify(int x,int y) 
{
//	cout<<y<<endl;
	for(const auto& t:s[y]) 
	{
//		cout<<t.first<<" "<<t.second<<endl; 
    	int pre=minn(rt[t.first]);
    	update(rt[t.first],1,n,x,t.second);
    	(ans*=qp(t.first,minn(rt[t.first])-pre))%=mod;
	}
//	cout<<endl;
}
signed main() 
{
	n=read();
	q=read();
	for(int i=2;i<N;i++)
	{
		if(!np[i])
		{
			p[++cnt]=i;
			rt[i]=++tot;
		}
		for(int l=1;l<=cnt&&i*p[l]<N;l++)
			np[i*p[l]]=1;
	}
//	cout<<cnt<<endl<<endl;
	for(int i=1;i<=cnt;i++)
		for(int l=1;p[i]*l<N;l++)
		{
			int t=l,c=0;
			while(t%p[i]==0)
			{
				t/=p[i];
				c++;
			}
			s[p[i]*l].push_back(make_pair(p[i],c+1));
		}
	for(int i=1;i<=n;i++)
		modify(i,read());
	while(q--)
	{
		int x=read(),y=read();
		modify(x,y);
		cout<<ans<<endl;
	}
	return 0;
}