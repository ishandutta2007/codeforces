#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;

const int N=300005,M=N*12,inf=1e9,mod=1e9+7;
void gmin(int &x,int y){if(x>y) x=y;}
void gmax(int &x,int y){if(x<y) x=y;}
void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
struct node{int l,r,num;}b[N];
int n,m,a[N],ans[N];
struct sgt{
	int flag[N<<2];
	inline void pushdown(int k){
		if(flag[k]>=inf) return;
		gmin(flag[ls],flag[k]);
		gmin(flag[rs],flag[k]);
		flag[k]=inf;
	}
	inline void change(int l,int r,int x,int y,int k,int b){
		if(l>=x&&r<=y){
			gmin(flag[k],b);
			return;
		}
		pushdown(k);
		int mid=l+r>>1;
		if(x<=mid) change(l,mid,x,y,ls,b);
		if(y>mid) change(mid+1,r,x,y,rs,b);
	}
	inline int get(int l,int r,int x,int k){
		if(l==r) return flag[k];
		pushdown(k);
		int mid=l+r>>1;
		if(x<=mid) return get(l,mid,x,ls);
		return get(mid+1,r,x,rs);
	}
	inline void build(int l,int r,int k){
		flag[k]=inf;
		if(l==r) return;
		int mid=l+r>>1;
		build(l,mid,ls);build(mid+1,r,rs);
	}
	void clear(){build(1,n,1);}
	inline void ch(int x,int y,int b){change(1,n,x,y,1,b);}
	inline int get(int x){return get(1,n,x,1);}
}q;
struct sgt2{
	int p[M],c[M][2],cnt,root[N];
	inline int get(int k,int l,int r,int x,int y){
		if(!k) return 0;
		if(l>=x&&r<=y) return p[k];
		int mid=l+r>>1,ans=0;
		if(x<=mid) gmax(ans,get(c[k][0],l,mid,x,y));
		if(y>mid) gmax(ans,get(c[k][1],mid+1,r,x,y));
		return ans;
	}
	inline void change(int &k,int l,int r,int x,int b){
		++cnt;p[cnt]=max(p[k],b);
		c[cnt][0]=c[k][0];c[cnt][1]=c[k][1];k=cnt;
		if(l==r) return;
		int mid=l+r>>1;
		if(x<=mid) change(c[k][0],l,mid,x,b);
		else change(c[k][1],mid+1,r,x,b);
	}
	void clear(){
		memset(c,0,sizeof(c));
		memset(p,0,sizeof(p));
		cnt=0;
	}
}p;

bool cmp(node a,node b){return a.r<b.r;}
void solve(){
	sort(b+1,b+m+1,cmp);
	int k=1;
	q.clear();p.clear();
	for(int i=1;i<=n;i++){
		int c=i-1,last=inf<<1;
		while(c){
			int j=p.get(p.root[c],0,inf,a[i],((ll)a[i]+last)>>1);
			if(!j) break;
			q.ch(1,j,a[j]-a[i]);
			if(a[j]==a[i]) break;
			c=j-1;last=a[j];
		}
		p.root[i]=p.root[i-1];
		p.change(p.root[i],0,inf,a[i],i);
		while(k<=m&&b[k].r==i) gmin(ans[b[k].num],q.get(b[k].l)),k++;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
		b[i].num=i;ans[i]=inf;
	}
	solve();
	reverse(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		b[i].l=n+1-b[i].l;b[i].r=n+1-b[i].r;
		swap(b[i].l,b[i].r);
	}
	solve();
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}