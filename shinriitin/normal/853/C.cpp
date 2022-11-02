#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

typedef long long ll;

const int max_N=2e5;

inline ll C2(int n){
	return 1ll*n*(n-1)/2;
}

int n,q,p[max_N+21],rp[max_N+21],cnt[max_N+21][4],bit[max_N+21];

ll ans[max_N+21];

struct event{
	int x,l,r,id;
	inline bool operator<(const event&o)const{
		return x<o.x;
	}
};

#define add push_back

std::vector<event>events;

int main(){
	read(n),read(q);
	for(int i=1;i<=n;++i)read(p[i]);
	for(int i=1,l,d,r,u;i<=q;++i){
		read(l),read(d),read(r),read(u);
		ans[i]=C2(n);
		ans[i]-=C2(l-1)+C2(n-r)+C2(d-1)+C2(n-u);
		if(l>1){
			if(d>1)events.add({l-1,1,d-1,i*4+0});
			if(u<n)events.add({l-1,u+1,n,i*4+1});
		}
		if(r<n){
			if(d>1){
				events.add({n,1,d-1,i*4+2});
				events.add({r,1,d-1,-(i*4+2)});
			}
			if(u<n){
				events.add({n,u+1,n,i*4+3});
				events.add({r,u+1,n,-(i*4+3)});
			}
		}
	}
	std::sort(events.begin(),events.end());
	int cur=0;
	for(auto&eve:events){
		while(cur<eve.x)for(int i=p[++cur];i<=n;i+=i&-i)++bit[i];
		int tmp=0;
		for(int i=eve.r;i;i-=i&-i)tmp+=bit[i];
		for(int i=eve.l-1;i;i-=i&-i)tmp-=bit[i];
		int f=1;
		if(eve.id<0)f=-1,eve.id*=-1;
		int id1=eve.id/4,id2=eve.id%4;
		cnt[id1][id2]+=tmp*f;
	}
	for(int i=1;i<=q;++i)for(int j=0;j<4;++j)ans[i]+=C2(cnt[i][j]);
	for(int i=1;i<=q;++i)printf("%I64d\n",ans[i]);
	return 0;
}