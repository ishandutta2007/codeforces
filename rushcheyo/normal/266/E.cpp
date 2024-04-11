#include <cstdio>
const int N=100005,mod=1000000007;
int n,m,pws[N][6],sum[N*4][6],cov[N*4],C[6][6];
void pushup(int u) {
	for (int i=0;i<=5;i++) sum[u][i]=(sum[u<<1][i]+sum[u<<1|1][i])%mod;
}
void make(int u,int l,int r,int v) {
	cov[u]=v; for (int i=0;i<=5;i++) sum[u][i]=1ll*(pws[r][i]-pws[l-1][i]+mod)*v%mod;
}
void build(int u,int l,int r) {
	cov[u]=-1;
	if (l==r) {
		scanf("%d",sum[u]);
		make(u,l,r,sum[u][0]);
		return;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void pushdown(int u,int l,int r,int mid) {
	if (cov[u]!=-1) {
		make(u<<1,l,mid,cov[u]);
		make(u<<1|1,mid+1,r,cov[u]);
		cov[u]=-1;
	}
}
int query(int u,int l,int r,int ql,int qr,int k) {
	if (l>=ql&&r<=qr) return sum[u][k];
	int mid=l+r>>1,sum=0;
	pushdown(u,l,r,mid);
	if (ql<=mid) sum=query(u<<1,l,mid,ql,qr,k);
	if (qr>mid) sum=(sum+query(u<<1|1,mid+1,r,ql,qr,k))%mod;
	return sum;
}
void modify(int u,int l,int r,int ql,int qr,int v) {
	if (l>=ql&&r<=qr) {make(u,l,r,v); return;}
	int mid=l+r>>1;
	pushdown(u,l,r,mid);
	if (ql<=mid) modify(u<<1,l,mid,ql,qr,v);
	if (qr>mid) modify(u<<1|1,mid+1,r,ql,qr,v);
	pushup(u);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		int w=1;
		for (int j=0;j<=5;j++) {
			pws[i][j]=(pws[i-1][j]+w)%mod;
			w=1ll*w*i%mod;
		}
	}
	for (int i=0;i<=5;i++)
		for (int j=C[i][0]=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	build(1,1,n);
	while (m--) {
		char op[5];
		int l,r,x;
		scanf("%s%d%d%d",op,&l,&r,&x);
		if (op[0]=='=') modify(1,1,n,l,r,x);
		else {
			int ans=0,w=1;
			for (int j=x;j>=0;j--) {
				ans=(ans+1ll*query(1,1,n,l,r,j)*C[x][j]%mod*w)%mod;
				w=w*(mod+1ll-l)%mod;
			}
			printf("%d\n",ans);
		}
	}
}