#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,q;
int st[300010][19],pos[300010][19];
int p[300010],a[300010],logt[300010];
bool bhf;
struct node{
	int l,r;
}b[3000010];
int cnt;
int dfs(int l,int r,int w){
	// cerr<<l<<" "<<r<<" "<<w<<"\n";
	if(l>r) return 0;
	if(l==r){
		if(a[l]==0) b[++cnt]=node{0,w};
		if(a[l]>=w) bhf=1;
		return a[l];
	}
	int k=logt[r-l+1];
	int mid=-1;
	if(st[l][k]>st[r-(1<<k)+1][k]) mid=pos[l][k];
	else mid=pos[r-(1<<k)+1][k];
	// cerr<<"mid:"<<mid<<"\n";
	int mx=0;
	if(a[mid]){
		mx=max(mx,dfs(l,mid-1,min(w,a[mid])));
		mx=max(mx,dfs(mid+1,r,min(w,a[mid])));
		if(a[mid]>w||mx>a[mid]) bhf=1;
	}
	else{
		mx=max(mx,dfs(l,mid-1,w));mx=max(mx,dfs(mid+1,r,w));
		b[++cnt]=node{mx,w};
		if(mx>w) bhf=1;
	}
	return max(mx,a[mid]);
}
int va[600010];
int que[300010],S[300010];
struct sgmt1{
	int mn[4000010],tag[4000010],po[4000010];
	void pushup(int p){
		if(mn[p<<1]<mn[p<<1|1]){
			mn[p]=mn[p<<1],po[p]=po[p<<1];
		}
		else mn[p]=mn[p<<1|1],po[p]=po[p<<1|1];
	}
	void pushdown(int p){
		if(tag[p]){
			mn[p<<1]+=tag[p];mn[p<<1|1]+=tag[p];
			tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
			tag[p]=0;
		}
	}
	void build(int p,int l,int r){
		mn[p]=tag[p]=0;
		if(l==r){
			po[p]=l;return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);
		pushup(p);
	}
	void update(int p,int l,int r,int L,int R,int k){
		if(l>=L&&r<=R){
			mn[p]+=k;tag[p]+=k;return ;
		}
		int mid=l+r>>1;pushdown(p);
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
}T1;
struct sgmt2{
	bool fug[4000010];
	void build(int p,int l,int r){
		fug[p]=0;if(l==r) return ;
		int mid=l+r>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	}
	void modify(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R){
			fug[p]=1;return ;
		}
		int mid=l+r>>1;
		if(L<=mid) modify(p<<1,l,mid,L,R);
		if(R>mid) modify(p<<1|1,mid+1,r,L,R);
		// return ;
	}
	int query(int p,int l,int r,int pos){
		if(fug[p]) return 1;
		if(l==r) return 0;
		int mid=l+r>>1;
		if(pos<=mid) return query(p<<1,l,mid,pos);
		else return query(p<<1|1,mid+1,r,pos);
	}
}T2;
int main(){
	T=read();
	for(int oo=1;oo<=T;++oo){
		bhf=0;
		n=read(),q=read();
		for(int i=2;i<=n;++i) logt[i]=logt[i>>1]+1;
		for(int i=1;i<=n;++i) p[i]=read(),st[i][0]=p[i],pos[i][0]=i;
		for(int i=1;i<=n;++i) a[i]=read();
		for(int j=1;j<=18;++j){
			for(int i=1;i+(1<<j)-1<=n;++i){
				if(st[i][j-1]>st[i+(1<<j-1)][j-1]){
					st[i][j]=st[i][j-1];pos[i][j]=pos[i][j-1];
				}
				else st[i][j]=st[i+(1<<j-1)][j-1],pos[i][j]=pos[i+(1<<j-1)][j-1];
			}
		}cnt=0;
		dfs(1,n,1e9);
		int c=0;
		for(int i=1;i<=n;++i) if(a[i]) va[++c]=a[i];va[++c]=0;
		for(int i=1;i<cnt;++i) S[i]=va[++c]=read();
		for(int i=1;i<=q;++i) que[i]=va[++c]=read();
		// if(oo==263&&T==5000){
			// for(int i=1;i<cnt;++i) printf("%d ",S[i]);
			// for(int i=1;i<=q;++i) printf("%d\n",que[i]);
			// printf("%d %d\n",n,q);
			// for(int i=1;i<=n;++i) printf("%d ",p[i]);printf("\n");
			// for(int i=77;i<=n;++i) printf("%d ",a[i]);printf("\n");
			// cerr<<n<<" "<<q<<"\n";
		// }
		sort(va+1,va+c+1);
		int lsc=c;
		c=unique(va+1,va+c+1)-va-1;
		// for(int i=1;i<=c;++i) cerr<<va[i]<<" ";cerr<<"\n";
		if(c!=lsc) bhf=1;
		T1.build(1,1,c);T2.build(1,1,c);
		for(int i=1;i<cnt;++i) S[i]=lower_bound(va+1,va+c+1,S[i])-va;
		sort(S+1,S+cnt);
		for(int i=1;i<=cnt;++i){
			// cerr<<b[i].l<<" "<<b[i].r<<"\n";
			b[i].l=lower_bound(va+1,va+c+1,b[i].l)-va;
			b[i].r=min(c,(int)(lower_bound(va+1,va+c+1,b[i].r)-va));
		}
		sort(b+1,b+cnt+1,[&](node x,node y){
			return x.r<y.r;
		});
		int it1=1,it2=1;
		int L=0,R=c;
		for(int i=1;i<=c;++i){
			while(it1<=cnt&&b[it1].r==i){
				// cerr<<b[it1].l<<" "<<b[it1].r<<"\n";
				T1.update(1,1,c,1,b[it1].l,-1);
				++it1;
			}
			while(it2<cnt&&S[it2]==i){
				// cerr<<i<<"\n";
				T1.update(1,1,c,1,i,1);
				++it2;
			}
			if(T1.mn[1]<-1) bhf=1;
			else if(T1.mn[1]==-1){
				R=min(R,i);L=max(L,T1.po[1]);
				// cerr<<"pos:"<<T1.po[1]<<" "<<i<<"\n";
				// T2.modify(1,1,c,T1.po[1],i);
			}
		}
		// cerr<<bhf<<'\n';
		// cerr<<L<<" "<<R<<"\n";
		// if(T<5000) 
		for(int i=1;i<=q;++i){
			if(bhf) printf("NO\n");
			else{que[i]=lower_bound(va+1,va+c+1,que[i])-va;
				if(que[i]>=L&&que[i]<=R) printf("YES\n");else printf("NO\n");
				// printf(T2.query(1,1,c,que[i])?"NO\n":"YES\n");
			}
		}
	}
}