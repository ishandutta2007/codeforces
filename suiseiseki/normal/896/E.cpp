#include <cmath>
#include <cstdio>
#include <cstring>
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=500000;
struct Node{
	int l,r,opt,x;
}q[Maxn+5];
int n,m;
int ans[Maxn+5];
int fa[Maxn+5],rt[Maxn+5];
int cnt[Maxn+5],d[Maxn+5];
int L[Maxn+5],R[Maxn+5],lsh[Maxn+5];
int tot;
int a[Maxn+5];
int bl;
int mx,tag,l,r,tmp,ql,qr,x;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(rt[y]){
		fa[rt[x]]=rt[y];
	}
	else{
		rt[y]=rt[x];	
		lsh[rt[y]]=y;
	}
	cnt[y]+=cnt[x];
	rt[x]=cnt[x]=0;
}
void build(){
	mx=tag=tot=0;
	memset(rt,0,sizeof rt);
	memset(cnt,0,sizeof cnt);
	for(int i=l;i<=r;++i){
		mx=max(mx,a[i]);
		if(rt[a[i]]){
			fa[i]=rt[a[i]];
		}
		else{
			rt[a[i]]=fa[i]=i;
			lsh[i]=a[i];
		}
		cnt[a[i]]++;
	}
}
void modify(){
	if((x<<1)<=mx-tag){
		for(int j=tag+1;j<=tag+x;++j){
			if(rt[j]){
				merge(j,j+x);
			}
		}
		tag+=x;
	}
	else{
		for(int j=mx;j>tag+x;--j){
			if(rt[j]){
				merge(j,j-x);
			}
		}
		if(tag+x<mx){
			mx=tag+x;
		}
	}
}
void rebuild(){
	for(int j=l;j<=r;++j){
		a[j]=lsh[find(j)];
		rt[a[j]]=cnt[a[j]]=0;
		a[j]-=tag;
	}
	for(int j=l-10;j<=r+10;++j){
		lsh[j]=0;
	}
	tag=mx=tot=0;
	tmp=min(qr,r);
	for(int j=max(ql,l);j<=tmp;++j){
		a[j]=a[j]>x?a[j]-x:a[j];
	}
	for(int j=l;j<=r;++j){
		mx=max(mx,a[j]);
		if(rt[a[j]]){
			fa[j]=rt[a[j]];
		}
		else{
			rt[a[j]]=fa[j]=j;
			lsh[j]=a[j];
		}
		cnt[a[j]]++;
	}
}
void get(int i){
	if(x+tag>Maxn){
		return;
	}
	if(ql<=l&&r<=qr){
		ans[i]+=cnt[x+tag];
	}
	else{
		tmp=min(r,qr);
		for(int j=max(l,ql);j<=tmp;++j){
			if(lsh[find(j)]==tag+x){
				ans[i]++;
			}
		}
	}
}
int main(){
	read(n);
	read(m);
	bl=sqrt(n-1)+1;
    for(int i=1;i<=n;++i){
    	read(a[i]);
	}
	for(int i=1;i<=m;++i){
		read(q[i].opt),read(q[i].l),read(q[i].r),read(q[i].x);
	}
	int pos=1;
	L[1]=1;
	while(L[pos]+bl<n){
		R[pos]=L[pos]+bl-1;
		pos++;
		L[pos]=R[pos-1]+1;
	}
	R[pos]=n;
	for(int k=1;k<=pos;k++){
		l=L[k],r=R[k];
		build();
		for(int i=1;i<=m;i++){
			ql=q[i].l,qr=q[i].r,x=q[i].x;
			if(r<ql||qr<l){
				continue;
			}
			if(q[i].opt==1){
				if(ql<=l&&r<=qr){
					modify();
				}
				else{
					rebuild();
				}
			}
			else{
				get(i);
			}
		}
	}
	for(int i=1;i<=m;++i){
		if(q[i].opt==2){
			printf("%d\n",ans[i]);
		}
	}
    return 0;
}