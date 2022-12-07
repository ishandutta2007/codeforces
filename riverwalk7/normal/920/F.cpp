#include<bits/stdc++.h>
#define MX 1000000
#define ll long long 
using namespace std;
ll ans[MX+10],f[1200010],a[300010],n,m;
bool tag[12000010];
void build(int ro,int l,int r){
	if (l==r) {
		f[ro]=a[l];
		tag[ro]=(ans[f[ro]]==f[ro]);
		return ;
	}
	int mid=(l+r)>>1;
	build(ro<<1,l,mid);
	build(ro<<1|1,mid+1,r);
	f[ro]=f[ro<<1]+f[ro<<1|1];
	tag[ro]=tag[ro<<1]&&tag[ro<<1|1];
}
void modify(int ro,int l,int r,int l1,int r1){
	if (tag[ro]) return;
	if (l==r) {
		f[ro]=ans[f[ro]];
		tag[ro]=(f[ro]==ans[f[ro]]);
		return ;
	}
	int mid=(l+r)>>1;
	if (l==l1&&r==r1){
		modify(ro<<1,l,mid,l1,mid);
		modify(ro<<1|1,mid+1,r,mid+1,r1);
		tag[ro]=tag[ro<<1]&&tag[ro<<1|1];
		f[ro]=f[ro<<1]+f[ro<<1|1];
		return ;
	}
	if (mid<l1) modify(ro<<1|1,mid+1,r,l1,r1);
	else if (mid>=r1) modify(ro<<1,l,mid,l1,r1);
	else {
		modify(ro<<1,l,mid,l1,mid);
		modify(ro<<1|1,mid+1,r,mid+1,r1);
	}
	tag[ro]=tag[ro<<1]&&tag[ro<<1|1];
	f[ro]=f[ro<<1]+f[ro<<1|1];
}
ll query(int ro,int l,int r,int l1,int r1){
	if (l==l1&&r==r1) return f[ro];
	int mid=(l+r)>>1;
	if (mid<l1) return query(ro<<1|1,mid+1,r,l1,r1);
	else if (mid>=r1) return query(ro<<1,l,mid,l1,r1);
	else return query(ro<<1,l,mid,l1,mid)+query(ro<<1|1,mid+1,r,mid+1,r1);
	
}
int main(){
	for (int i=1;i<=MX;i++) for (int j=1;j<=MX/i;j++) ans[j*i]++;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	build(1,1,n);
	for (int i=1;i<=m;i++) {
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if (t==1) modify(1,1,n,l,r);
		else printf("%I64d\n",query(1,1,n,l,r));
	}
}