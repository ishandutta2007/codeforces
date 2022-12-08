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
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;

const int N=200005,M=100005,mod=1e9+7;
inline void gmin(int &x,int y){if(x>y) x=y;}
inline void gmax(int &x,int y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}

pii ans;
int n,K,d,a[N],use[N],p[N<<2],flag[N<<2];
int s1[N],s2[N],t1,t2;
map<int,int> last;

void add(int k,int b){p[k]+=b;flag[k]+=b;}
void pushdown(int k){
	if(!flag[k]) return;
	add(ls,flag[k]);add(rs,flag[k]);
	flag[k]=0;
}
void change(int l,int r,int x,int y,int k,int b){
	if(x<=l&&r<=y){add(k,b);return;}
	pushdown(k);
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,x,y,ls,b);
	if(y>mid) change(mid+1,r,x,y,rs,b);
	p[k]=min(p[ls],p[rs]);
}
int get(int l,int r,int x,int y,int k){
	if(p[k]>K) return -1;
	if(l==r) return l;
	pushdown(k);
	int mid=l+r>>1;
	if(x<=l&&r<=y){
		if(p[ls]<=K) return get(l,mid,x,y,ls);
		return get(mid+1,r,x,y,rs);
	}
	if(x<=mid){
		int t=get(l,mid,x,y,ls);
		if(~t) return t;
	}
	if(y>mid) return get(mid+1,r,x,y,rs);
}

void solve(int l,int r){
	int minx=inf;
	for(int i=l;i<=r;i++) gmin(minx,a[i]);
	for(int i=l;i<=r;i++) a[i]=(a[i]-minx)/d;
	last.clear();
	use[l-1]=l-1;
	for(int i=l;i<=r;i++){
		use[i]=max(last[a[i]],use[i-1]);
		last[a[i]]=i;
	}
	t1=t2=1;
	s1[1]=l-1;s2[1]=l-1;
	for(int i=l;i<=r;i++){
		while(t1>1&&a[s1[t1]]>a[i])
			change(1,n,s1[t1-1]+1,s1[t1],1,a[s1[t1]]-a[i]),t1--;
		s1[++t1]=i;
		while(t2>1&&a[s2[t2]]<a[i])
			change(1,n,s2[t2-1]+1,s2[t2],1,a[i]-a[s2[t2]]),t2--;
		s2[++t2]=i;
		if(i>l) change(1,n,l,i-1,1,-1);
		int tmp=get(1,n,use[i]+1,i,1);
		ans=min(ans,mp(tmp-i,tmp));
	}
}

int main(){
	ans=mp(1,0);
	scanf("%d%d%d",&n,&K,&d);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(!d){
		int last=1;
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1]) ans=min(ans,mp(last-i+1,last)),last=i;
		ans=min(ans,mp(last-n,last));
	}
	else{
		int last=1;
		for(int i=2;i<=n;i++)
			if((a[i]-a[i-1])%d!=0) solve(last,i-1),last=i;
		solve(last,n);
	}
	printf("%d %d\n",ans.SS,ans.SS-ans.FF);
	return 0;
}