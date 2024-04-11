#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (c[k][0])
#define rs (c[k][1])
#define inf 0x3f3f3f3f
using namespace std;

const int N=100005,M=N<<2,mod=1e9+7;
inline void gmin(int &x,int y){if(x>y) x=y;}
inline void gmax(int &x,int y){if(x<y) x=y;}
inline void ch(int &x,int y){
	x+=y;
	if(x>=mod) x-=mod;
	if(x<0) x+=mod;
}

struct node{
	int cnt,l,r,li,ri;
}p[M],zero;
node operator + (node a,node b){return (node){a.cnt+b.cnt,(a.l+b.l)%mod,(a.r+b.r)%mod,(a.li+b.li)%mod,(a.ri+b.ri)%mod};}
int c[M][2],root[N],flag[M];
int n,cnt,si[N],a[N],b[N],L[N],R[N];
int sum[N],ans,tree,y;
vi g[N];
bool bad[N];
void make(int *s,int *a){
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		int t=a[i];
		while(t) s[i]+=sum[t],t-=t&-t;
		t=a[i];
		while(t<=n) sum[t]++,t+=t&-t;
	}reverse(a+1,a+n+1);
}
void build(int i,int l,int r,int &k){
	k=++cnt;
	if(l==r){p[k]=(node){1,L[g[i][l]],R[g[i][l]],(ll)L[g[i][l]]*l%mod,(ll)R[g[i][l]]*l%mod};return;}
	int mid=l+r>>1;
	build(i,l,mid,ls);build(i,mid+1,r,rs);
	p[k]=p[ls]+p[rs];
}
void add(int k,int t){
	flag[k]+=t;
	ch(p[k].li,((ll)p[k].l*t%mod+mod)%mod);
	ch(p[k].ri,((ll)p[k].r*t%mod+mod)%mod);
}
void pushdown(int k){
	if(!flag[k]) return;
	add(ls,flag[k]);add(rs,flag[k]);
	flag[k]=0;
}
node get(int k,int l,int r,int x,int y){
	if(x>y) return zero;
	if(x<=l&&r<=y) return p[k];
	pushdown(k);
	int mid=l+r>>1;
	node L=zero,R=zero;
	if(x<=mid) L=get(ls,l,mid,x,y);
	if(y>mid) R=get(rs,mid+1,r,x,y);
	return L+R;
}
void ch(int k,int l,int r,int x,node b){
	if(l==r){p[k]=b;return;}
	pushdown(k);
	int mid=l+r>>1;
	if(x<=mid) ch(ls,l,mid,x,b); else ch(rs,mid+1,r,x,b);
	p[k]=p[ls]+p[rs];
}
void ch2(int k,int l,int r,int x,int y,int b){
	if(x>y) return ;
	if(x<=l&&r<=y){add(k,b);return;}
	pushdown(k);
	int mid=l+r>>1;
	if(x<=mid) ch2(ls,l,mid,x,y,b);
	if(y>mid) ch2(rs,mid+1,r,x,y,b);
	p[k]=p[ls]+p[rs];
}
int calc(int x){
//	printf("%d %d\n",tree,y);
	int ans=0;
	node l=get(root[tree],0,si[tree]-1,0,y-1),r=get(root[tree],0,si[tree]-1,y+1,si[tree]-1);
	ch(ans,(ll)l.l*r.r%mod);
	ch(ans,((ll)(cnt-1)*l.l%mod-l.li)*R[x]%mod);
	ch(ans,((ll)(-cnt-1)*r.r%mod+r.ri)*L[x]%mod);
//	debug(r.ri);
	return ans;
}
void clr(int x){
	ch(root[tree],0,si[tree]-1,y,(node){0,0,0,0,0});
	ch2(root[tree],0,si[tree]-1,y+1,si[tree]-1,-1);
}
void rec(int x){
	ch(root[tree],0,si[tree]-1,y,(node){1,L[x],R[x],(ll)L[x]*cnt%mod,(ll)R[x]*cnt%mod});
	ch2(root[tree],0,si[tree]-1,y+1,si[tree]-1,1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int t=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+t+1,a[i])-b;
	for(int i=1;i<=n;i++) g[a[i]].pb(i);
	make(L,a);
	make(R,a);reverse(R+1,R+n+1);
	for(int i=1;i<=n;i++)
		if(g[i].size()){
			si[i]=g[i].size();
			build(i,0,si[i]-1,root[i]);
			int sl=0,sr=0;
			for(auto j:g[i]) ch(sr,R[j]);
			for(auto j:g[i])
				ch(sr,mod-R[j]),ch(ans,(ll)sr*sl%mod),ch(sl,L[j]);
		}
	int T;scanf("%d",&T);
	for(int o=1;o<=T;o++){
		int t,x;scanf("%d%d",&t,&x);
		tree=a[x],y=lower_bound(g[tree].begin(),g[tree].end(),x)-g[tree].begin();
//		if(o==39915) printf("%d\n",y);
		cnt=get(root[tree],0,si[tree]-1,0,y-1).cnt;
		if(t==1){
			if(bad[x]){printf("%d\n",ans);continue;}
			ch(ans,mod-calc(x));clr(x);
			bad[x]=1;
		}
		else{
			if(!bad[x]){printf("%d\n",ans);continue;}
			rec(x);ch(ans,calc(x));
			bad[x]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}