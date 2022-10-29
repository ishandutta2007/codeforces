#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int n=200000,N=2000005;
typedef long long LL;
LL t[N],ans[N],d[N];
struct D{int id,r;} ;
vector <D> vt[N];

void inc(int x,LL y)
{
	for(int i=x; i<=n; i+=i&-i) t[i]+=y;
}

LL query(int x)
{
	LL ret=0;	
	for(int i=x; i; i-=i&-i) ret+=t[i];
	return ret;
}

LL get(LL x)
{
	if(x==0) return 0;
	return (x-1)*(x-2)/2;
}

LL get(int l,int r)
{
	LL ret=0;
	int p;

	p=2*l;
	if(p<=r)
		ret+=r/6-(p-1)/6;
	p=(5*l+1)/2;
	if(p<=r)
		ret+=r/15-(p-1)/15;
	return ret;
}

int main()
{
	int T;
	cin>>T;
	rep(i,1,T)
	{
		int l,r;
		cin>>l>>r;
		vt[l].pb((D){i,r});
	}
	repd(i,n,1)
	{
		for(int j=i; j<=n; j+=i)
		{
			LL x=get(d[j]);
			++d[j],x=get(d[j])-x;
			inc(j,x);
		}
		for(auto x:vt[i])
		{
			int r=x.r,id=x.id;
			ans[id]=(LL)(r-i+1)*(r-i)*(r-i-1)/6-query(r)-get(i,r);
		}
	}
	rep(i,1,T) cout<<ans[i]<<endl;
	return 0;
}