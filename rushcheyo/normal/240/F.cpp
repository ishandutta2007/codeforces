#include <cstdio>
const int N=100005;
int n,m,size[26][N*4],tmp[26],cover[26][N*4];
char s[N];
void build(int u,int l,int r) {
	for (int i=0;i<26;i++) cover[i][u]=-1;
	if (l==r) {size[s[l]-'a'][u]=1;return;}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	for (int i=0;i<26;i++) size[i][u]=size[i][u<<1]+size[i][u<<1|1];
}
void pushd(int t,int u,int l,int r,int mid) {
	if (cover[t][u]!=-1) {
		cover[t][u<<1]=cover[t][u<<1|1]=cover[t][u];
		size[t][u<<1]=(mid-l+1)*cover[t][u],size[t][u<<1|1]=(r-mid)*cover[t][u];
		cover[t][u]=-1;
	}
}
int query(int t,int u,int l,int r,int ql,int qr) {
	if (l>=ql&&r<=qr) return size[t][u];
	int mid=l+r>>1,ret=0;
	pushd(t,u,l,r,mid);
	if (ql<=mid) ret=query(t,u<<1,l,mid,ql,qr);
	if (qr>mid) ret+=query(t,u<<1|1,mid+1,r,ql,qr);
	return ret;
}
void update(int t,int u,int l,int r,int ql,int qr,int x) {
	if (l>=ql&&r<=qr) {
		cover[t][u]=x;
		size[t][u]=(r-l+1)*x;
		return;
	}
	int mid=l+r>>1;
	pushd(t,u,l,r,mid);
	if (ql<=mid) update(t,u<<1,l,mid,ql,qr,x);
	if (qr>mid) update(t,u<<1|1,mid+1,r,ql,qr,x);
	size[t][u]=size[t][u<<1]+size[t][u<<1|1];
}
void dfs(int u,int l,int r) {
	if (l==r) {
		int i;
		for (i=0;i<26;i++) if (size[i][u]) break;
		putchar(i+'a');
		return;
	}
	int mid=l+r>>1;
	for (int i=0;i<26;i++) pushd(i,u,l,r,mid);
	dfs(u<<1,l,mid);
	dfs(u<<1|1,mid+1,r);
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	build(1,1,n);
	for (int l,r;m--;) {
		scanf("%d%d",&l,&r);
		int ret=0;
		for (int i=0;i<26;i++) {
			tmp[i]=query(i,1,1,n,l,r);
			if (tmp[i]&1) ret++;
		}
		if (ret>1) continue;
		else {
			for (int i=0;i<26;i++) update(i,1,1,n,l,r,0);
			for (int i=0;i<26;i++) {
				if (tmp[i]==0) continue;
				update(i,1,1,n,l,l+tmp[i]/2-1,1),l+=tmp[i]/2;
				update(i,1,1,n,r-tmp[i]/2+1,r,1),r-=tmp[i]/2;
				if (tmp[i]&1) update(i,1,1,n,l+r>>1,l+r>>1,1);
			}
		}
	}
	dfs(1,1,n);
	puts("");
}