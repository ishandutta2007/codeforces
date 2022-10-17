#include<cstdio>
#include<queue>
const int N=3e5+6;
int T,n,a[N],b[N],tot[N],pos[N];
std::queue<int>q[N];
int d[N<<2];
void build(int l,int r,int o) {
	if(l==r)d[o]=a[l];
	else {
		const int mid=l+r>>1;
		build(l,mid,o<<1),build(mid+1,r,o<<1|1);
		d[o]=std::min(d[o<<1],d[o<<1|1]);
	}
}
int query(int l,int r,int o,const int&L,const int&R) {
	if(L<=l&&r<=R)return d[o];
	const int mid=l+r>>1;
	if(L<=mid&&mid<R)return std::min(query(l,mid,o<<1,L,R),query(mid+1,r,o<<1|1,L,R));
	if(L<=mid)return query(l,mid,o<<1,L,R);
	return query(mid+1,r,o<<1|1,L,R);
}
void modify(int l,int r,int o,const int&pos) {
	if(l==r)d[o]=9999999;
	else {
		const int mid=l+r>>1;
		if(pos<=mid)modify(l,mid,o<<1,pos);
		else modify(mid+1,r,o<<1|1,pos);
		d[o]=std::min(d[o<<1],d[o<<1|1]);
	}
}
int main() {
	for(scanf("%d",&T); T--;) {
		scanf("%d",&n);
		for(int i=1; i<=n; ++i)tot[i]=0;
		for(int i=1; i<=n; ++i)scanf("%d",a+i),++tot[a[i]];
		for(int i=1; i<=n; ++i)scanf("%d",b+i),--tot[b[i]];
		int ok=1;
		for(int i=1; i<=n&&ok; ++i)if(tot[i]) {
				puts("NO");
				ok=0;
			}
		if(!ok)continue;
		for(int i=1; i<=n; ++i)
			q[a[i]].push(i);
		for(int i=1; i<=n; ++i)pos[i]=q[b[i]].front(),q[b[i]].pop();
		build(1,n,1);
		for(int i=1; i<=n&&ok; ++i) {
			if(query(1,n,1,1,pos[i])!=b[i])ok=0;
			modify(1,n,1,pos[i]);
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}