#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 2e5+10;
int n,Q,k[N],t[N],a[N],b[N];
int top,q[N*100],cnt,root[N],v[N*100],lson[N*100],rson[N*100];
inline void insert(int &u,int l,int r,int ql,int k){
	if (!u) u=q[top--];v[u]+=k;
	if (l==r){
		if (!v[u]) q[++top]=u,lson[u]=rson[u]=u=0;
		return;
	}
	int mid=l+r>>1;
	if (ql<=mid) insert(lson[u],l,mid,ql,k);
		else insert(rson[u],mid+1,r,ql,k);
	if (!v[u]) q[++top]=u,lson[u]=rson[u]=u=0;
}
inline void Insert(int x,int y,int k){for (;x<=n;x+=x&-x) insert(root[x],1,n,y,k);}
inline int query(int u,int l,int r,int ql,int qr){
	if (!u) return 0;
	if (l>=ql&&r<=qr) return v[u];
	int mid=l+r>>1;
	if (qr<=mid) return query(lson[u],l,mid,ql,qr);
	else if (ql>mid) return query(rson[u],mid+1,r,ql,qr);
	else return query(lson[u],l,mid,ql,qr)+query(rson[u],mid+1,r,ql,qr);
}
inline int Query(int l,int r,int ql,int qr){
	int sum=0;l--;
	for (;r;r-=r&-r) sum+=query(root[r],1,n,ql,qr);
	for (;l;l-=l&-l) sum-=query(root[l],1,n,ql,qr);
	return sum;
}
int main(){
	n=read(),Q=read();
	For(i,1,n*100) q[++top]=i;
	For(i,1,n) k[i]=read(),a[k[i]]=i;
	For(i,1,n) t[i]=read(),b[t[i]]=i;
	For(i,1,n) Insert(a[i],b[i],1);
	For(i,1,Q){
		int opt=read();
		if (opt==1){
			int l1=read(),r1=read(),l2=read(),r2=read();
			printf("%d\n",Query(l1,r1,l2,r2));
		} else {
			int x=read(),y=read();
			Insert(a[t[x]],b[t[x]],-1),Insert(a[t[y]],b[t[y]],-1);
			b[t[x]]=y,b[t[y]]=x,swap(t[x],t[y]);
			Insert(a[t[x]],b[t[x]],1),Insert(a[t[y]],b[t[y]],1);
		} 
	}
}