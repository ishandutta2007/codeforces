#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int seed;
int rnd()
{
	int ret = seed;
    seed = (seed * 7ll + 13) % 1000000007;
    return ret;
}
int n,m,vmax;
int a[233333];
inline long long poww(long long x,int y,int mod)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return ret;
}
struct itv
{
	int l,r;
	long long val;
	inline bool operator<(const itv &x)const{return l<x.l;}
}srt[233333];
int top;
inline bool cmp(const itv &x,const itv &y){return x.val<y.val;}
set<itv> line;
int main()
{
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for (int i=1;i<=n;i++)
	{
	    a[i] = (rnd() % vmax) + 1;
//	    cout<<a[i]<<' ';
		line.insert({i,i,a[i]});
	}
//	cout<<endl;
	
	int op,l,r,x,y;
	for (int t=1;t<=m;t++)
	{
		op = (rnd() % 4) + 1;
	    l = (rnd() % n) + 1;
	    r = (rnd() % n) + 1;
	    if (l > r)
			swap(l, r);
	    if (op == 3)
	        x = (rnd() % (r - l + 1)) + 1;
	    else
	        x = (rnd() % vmax) + 1;
	    if (op == 4)
	        y = (rnd() % vmax) + 1;
//	    cout<<op<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
	    auto ll=--line.upper_bound({l,l,0});
	    itv _=*ll;
	    if(_.l!=l)
	    {
	    	line.erase(ll);
	    	line.insert({_.l,l-1,_.val});
	    	line.insert({l,_.r,_.val});
		}
		auto rr=--line.upper_bound({r,r,0});
		_=*rr;
		if(_.r!=r)
	    {
	    	line.erase(rr);
	    	line.insert({_.l,r,_.val});
	    	line.insert({r+1,_.r,_.val});
		}
		ll=--line.upper_bound({l,l,0});
		rr=line.upper_bound({r,r,0});
	    if(op==1)
	    {
	    	for(auto it=ll;it!=rr;)
	    	{
	    		_=*it;
	    		it=line.erase(it);
	    		_.val+=x;
	    		line.insert(_);
			}
		}
		else if(op==2)
	    {
	    	itv tmp({ll->l,rr->l-1,x});
	    	line.erase(ll,rr);
	    	line.insert(tmp);
		}
		else if(op==3)
	    {
	    	top=1;
	    	for(auto it=ll;it!=rr;++it)
	    	{
	    		srt[top++]=*it;
			}
			sort(srt+1,srt+top,cmp);
			int cur=x;
			long long ans=0;
			for(int i=1;i<top;i++)
			{
				if(cur<=srt[i].r-srt[i].l+1)
				{
					ans=srt[i].val;
					break;
				}
				cur-=srt[i].r-srt[i].l+1;
			}
			printf("%lld\n",ans);
		}
		else 
		{
			long long ans=0;
	    	for(auto it=ll;it!=rr;++it)
	    	{
	    		ans+=(it->r-it->l+1)*poww(it->val%y,x,y);
	    		ans%=y;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;   
}