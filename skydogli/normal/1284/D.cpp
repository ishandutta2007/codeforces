#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
const int maxn = 5e6+10;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}
struct node{
	int al,ar,bl,br;
}p[maxn];
int f[maxn],g[maxn];
int k,m,n;
int w[maxn],tot=0;
int cmp1(int x,int y){
	return p[x].bl<p[y].bl;
}
int cmp2(int x,int y){
	return p[x].br<p[y].br;
}

int sum[maxn<<2],a[maxn<<2];
void pushdown(int k,int l,int r){
	if(a[k]){
		a[k<<1]=a[k<<1|1]=1;
		sum[k<<1]=sum[k<<1|1]=1;
		a[k]=0;
	}
	return;
}

inline void add(int k,int l,int r,int ls,int rs){
	if(ls<=l && r<=rs){sum[k]=a[k]=1;return;}
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if(mid>=ls)add(k<<1,l,mid,ls,rs);
	if(mid+1<=rs)add(k<<1|1,mid+1,r,ls,rs);
	sum[k]=sum[k<<1]|sum[k<<1|1];
	return;
}

int query(int k,int l,int r,int ls,int rs){
	if(ls<=l && r<=rs)return sum[k];
	pushdown(k,l,r);
	int mid=(l+r)>>1,ans=0;
	if(mid>=ls)ans|=query(k<<1,l,mid,ls,rs);
	if(mid+1<=rs)ans|=query(k<<1|1,mid+1,r,ls,rs);
	return ans;
}

int main(){
	n=read();
	for(register int i=1;i<=n;i++){
		p[i].al=read();p[i].ar=read();p[i].bl=read();p[i].br=read();
		f[i]=g[i]=i;
		w[++tot]=p[i].al;w[++tot]=p[i].ar;
		w[++tot]=p[i].bl;w[++tot]=p[i].br;
	}
	sort(w+1,w+tot+1);
	tot=unique(w+1,w+tot+1)-w-1;
	for(register int i=1;i<=n;i++){
		p[i].al=lower_bound(w+1,w+tot+1,p[i].al)-w;
		p[i].ar=lower_bound(w+1,w+tot+1,p[i].ar)-w;
		p[i].bl=lower_bound(w+1,w+tot+1,p[i].bl)-w;
		p[i].br=lower_bound(w+1,w+tot+1,p[i].br)-w;
	}
	sort(f+1,f+n+1,cmp2);
	sort(g+1,g+n+1,cmp1);
	int pos=1;
	for(register int u=1;u<=n;u++){
		int i=g[u];
		while(pos<=n&&p[f[pos]].br<p[i].bl){add(1,1,tot,p[f[pos]].al,p[f[pos]].ar);pos++;}
		if(query(1,1,tot,p[i].al,p[i].ar)) {puts("NO");return 0;}
	}
	memset(sum,0,sizeof(sum));
	memset(a,0,sizeof(a));
	for(register int i=1;i<=n;i++){
		swap(p[i].al,p[i].bl);
		swap(p[i].ar,p[i].br);
		f[i]=g[i]=i;
	}
	sort(f+1,f+n+1,cmp2);
	sort(g+1,g+n+1,cmp1);
	pos=1;
	for(register int u=1;u<=n;u++){
		int i=g[u];
		while(pos<=n&&p[f[pos]].br<p[i].bl){add(1,1,tot,p[f[pos]].al,p[f[pos]].ar);pos++;}
		if(query(1,1,tot,p[i].al,p[i].ar)) {puts("NO");return 0;}
	}
	puts("YES");
	return 0;
}