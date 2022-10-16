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

int n,q,a[200010],pos[200010],pre[200010],nxt[200010],sum1[800010],tag1[800010],len[800010];
long long ans[1000010],sum2[800010],tag2[800010];
vector<pair<int,int> > v[1000010];

inline void build(int o,int l,int r)
{
	len[o]=r-l+1;
	if(l<r){
		int mid=(l+r)/2;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r); 
	}
}

inline void pushdown1(int o)
{
	if(tag1[o]){
		sum1[o*2]+=len[o*2]*tag1[o];tag1[o*2]+=tag1[o];
		sum1[o*2+1]+=len[o*2+1]*tag1[o];tag1[o*2+1]+=tag1[o]; 
		tag1[o]=0;
	}
}

inline void update1(int o,int l,int r,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		tag1[o]+=v;sum1[o]+=len[o]*v;
		return;
	}
	int mid=(l+r)/2;
	pushdown1(o);
	update1(o*2,l,mid,x,y,v);
	update1(o*2+1,mid+1,r,x,y,v);
	sum1[o]=sum1[o*2]+sum1[o*2+1];
}

inline int query1(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return 0;
	if(x<=l&&r<=y) return sum1[o];
	pushdown1(o);
	int mid=(l+r)/2,res=0;
	res+=query1(o*2,l,mid,x,y);
	res+=query1(o*2+1,mid+1,r,x,y);
	return res; 
}

inline void pushdown2(int o)
{
	if(tag2[o]){
		sum2[o*2]+=1ll*len[o*2]*tag2[o];tag2[o*2]+=tag2[o];
		sum2[o*2+1]+=1ll*len[o*2+1]*tag2[o];tag2[o*2+1]+=tag2[o]; 
		tag2[o]=0ll;
	}
}

inline void update2(int o,int l,int r,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y){
		tag2[o]+=1ll*v;sum2[o]+=1ll*len[o]*v;
		return;
	}
	int mid=(l+r)/2;
	pushdown2(o);
	update2(o*2,l,mid,x,y,v);
	update2(o*2+1,mid+1,r,x,y,v);
	sum2[o]=sum2[o*2]+sum2[o*2+1];
}

inline long long query2(int o,int l,int r,int x,int y)
{
	if(r<x||l>y) return 0ll;
	if(x<=l&&r<=y) return sum2[o];
	pushdown2(o);
	int mid=(l+r)/2;long long res=0ll;
	res+=query2(o*2,l,mid,x,y);
	res+=query2(o*2+1,mid+1,r,x,y);
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],pos[a[i]]=i;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		v[r].push_back(make_pair(l,i));
	}
	build(1,1,n);
	stack<pair<int,int> > s;
	for(int i=1;i<=n;i++){
		pair<int,int> now=make_pair(a[i],i);
		while(!s.empty()){
			pair<int,int> t=s.top();
			if(t.first<now.first){
				update1(1,1,n,pre[t.second],nxt[t.second],-1);
				update2(1,1,n,pre[t.second],nxt[t.second],i-1);
				pre[t.second]=0;nxt[t.second]=0;s.pop();
			}
			else break;
		}
		if(!s.empty()){
			pre[i]=s.top().second+1;nxt[i]=pre[i]-1;
			for(int j=2;j*a[i]<=n;j++) if(pre[pos[j*a[i]]]){
				if(j==a[i]) continue;
				int x=pos[j*a[i]],y=pos[j],p=nxt[x];
				if(y<=i){
					nxt[x]=max(nxt[x],min(y,x));
				}
				if(nxt[x]>p){
					update1(1,1,n,p+1,nxt[x],1);
					update2(1,1,n,p+1,nxt[x],-(i-1));
				}
			}
		}
		else{
			pre[i]=1;nxt[i]=0;
		}
		s.push(now);
		for(int j=1;j*j<=a[i];j++) if(a[i]%j==0){
			if(j*j==a[i]) continue;
			int x=pos[j],y=pos[a[i]/j];
			if(x>=pre[i]&&y>=pre[i]&&x<=i&&y<=i){
				nxt[i]=max(nxt[i],min(x,y));
			}
		}
		if(pre[i]<=nxt[i]){
			update1(1,1,n,pre[i],nxt[i],1);
			update2(1,1,n,pre[i],nxt[i],-(i-1));
		}
		for(int j=0;j<v[i].size();j++){
			int l=v[i][j].first,id=v[i][j].second;
			ans[id]+=1ll*query1(1,1,n,l,i)*i;
			ans[id]+=query2(1,1,n,l,i);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}