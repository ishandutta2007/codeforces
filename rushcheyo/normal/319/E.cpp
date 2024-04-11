#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>T[N*8];
int n,tot,fa[N],l[N],r[N],ml[N],mr[N],sx[N],lx,op[N],ql[N],qr[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int u,int l,int r,int p,int f){
	for(auto x:T[u]){
		ml[f]=min(ml[f],ml[x]);
		mr[f]=max(mr[f],mr[x]);
		fa[x]=f;
	}
	T[u].clear();
	if(l==r)return;
	int mid=l+r>>1;
	if(p<=mid)unite(u<<1,l,mid,p,f);
	else unite(u<<1|1,mid+1,r,p,f);
}
void cover(int u,int l,int r,int ql,int qr,int f){
	if(l>=ql&&r<=qr){
		T[u].push_back(f);
		return;
	}
	int mid=l+r>>1;
	if(ql<=mid)cover(u<<1,l,mid,ql,qr,f);
	if(qr>mid)cover(u<<1|1,mid+1,r,ql,qr,f);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",op+i,ql+i,qr+i);
		if(op[i]==1){
			sx[++lx]=ql[i];
			sx[++lx]=qr[i];
		}
	}
	sort(sx+1,sx+1+lx);
	lx=unique(sx+1,sx+1+lx)-sx-1;
	for(int i=1;i<=n;i++)
		if(op[i]==1){
			int x=lower_bound(sx+1,sx+1+lx,ql[i])-sx;
			int y=lower_bound(sx+1,sx+1+lx,qr[i])-sx;
			fa[++tot]=tot;
			l[tot]=ml[tot]=x,r[tot]=mr[tot]=y;
			unite(1,1,lx,x,tot);
			unite(1,1,lx,y,tot);
			if(mr[tot]-ml[tot]>=2)
				cover(1,1,lx,ml[tot]+1,mr[tot]-1,tot);
		}else{
			int x=find(ql[i]),y=find(qr[i]);
			puts(x==y||(ml[x]>=ml[y]&&mr[x]<=mr[y]&&(ml[x]!=ml[y]||mr[x]!=mr[y]||l[x]!=ml[x]||r[x]!=mr[x]))?"YES":"NO");
		}
	return 0;
}