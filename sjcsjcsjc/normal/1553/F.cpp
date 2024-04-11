#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,maxv,a[300010],bit1[300010],addv1[1200010];
long long ans[300010],bit2[300010],addv2[1200010];

inline void add1(int p,int v)
{
	while(p<=maxv){
		bit1[p]+=v;
		p+=p&(-p);
	}
}

inline int sum1(int p)
{
	int s=0;
	while(p>0){
		s+=bit1[p];
		p-=p&(-p);
	}
	return s;
}

inline void add2(int p,long long v)
{
	while(p<=maxv){
		bit2[p]+=v;
		p+=p&(-p);
	}
}

inline long long sum2(int p)
{
	long long s=0ll;
	while(p>0){
		s+=bit2[p];
		p-=p&(-p);
	}
	return s;
}

inline void pushdown(int o)
{
	addv1[o*2]+=addv1[o];addv1[o*2+1]+=addv1[o];
	addv2[o*2]+=addv2[o];addv2[o*2+1]+=addv2[o];
	addv1[o]=0;addv2[o]=0ll;
}

inline void update(int o,int l,int r,int x,int y,int val1,long long val2)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		addv1[o]+=val1;addv2[o]+=val2;
		return;
	}
	pushdown(o);
	int mid=(l+r)/2;
	update(o*2,l,mid,x,y,val1,val2);
	update(o*2+1,mid+1,r,x,y,val1,val2);
	return;
}

inline long long query(int o,int l,int r,int x)
{
	if(r<x||l>x) return 0ll;
	if(x==l&&r==x){
		return 1ll*addv1[o]*l+addv2[o];
	}
	pushdown(o);
	long long res=0ll;
	int mid=(l+r)/2;
	res+=query(o*2,l,mid,x);
	res+=query(o*2+1,mid+1,r,x);
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxv=max(maxv,a[i]);
	ans[1]=0ll;
	for(int j=a[1];j<=maxv;j+=a[1]){
		int l=j,r=min(maxv,j+a[1]-1);
		update(1,1,maxv,l,r,1,-1ll*j);
	}
	for(int i=2;i<=n;i++){
		ans[i]=ans[i-1];
		add1(a[i-1],1);
		add2(a[i-1],1ll*a[i-1]);
		int cnt=0;
		for(int j=0;j<=maxv;j+=a[i]){
			int l=j,r=min(maxv,j+a[i]-1);
			int val1=sum1(r)-sum1(l-1);
			long long val2=sum2(r)-sum2(l-1);
			ans[i]+=val2-1ll*val1*cnt*a[i];
			if(j>=a[i]) ans[i]+=1ll*val1*a[i];
			cnt++;
		}
		ans[i]+=query(1,1,maxv,a[i]);
		for(int j=a[i];j<=maxv;j+=a[i]){
			int l=j,r=min(maxv,j+a[i]-1);
			update(1,1,maxv,l,r,1,-1ll*j);
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}