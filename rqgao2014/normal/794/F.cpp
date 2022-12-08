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
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=500005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,q,a[N],flag[N];
ll p[N][10];
int trans[N][10];
void upt(int k){
	for(int i=0;i<10;i++)
		p[k][i]=p[ls][i]+p[rs][i];
}
void build(int l,int r,int k){
	for(int i=0;i<10;i++) trans[k][i]=i;
	if(l==r){
		int t=a[l],now=1;
		while(t){
			int dig=t%10;
			p[k][dig]+=now;t/=10;now*=10;
		}
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
	upt(k);
}
void add(int k,int s,int t){
	p[k][t]+=p[k][s];p[k][s]=0;
	for(int i=0;i<10;i++) 
		if(trans[k][i]==s) trans[k][i]=t;
	flag[k]=1;
}
int pos[10][10],si[10];
ll tmp[10];
void make(int k,int *to){
	clr(si,0);clr(tmp,0);
	for(int i=0;i<10;i++){
		int t=trans[k][i];
		pos[t][si[t]++]=i;
	}
	for(int i=0;i<10;i++)
		tmp[to[i]]+=p[k][i];
	cpy(p[k],tmp);
	for(int i=0;i<10;i++)
		for(int j=0;j<si[i];j++) trans[k][pos[i][j]]=to[i];
	flag[k]=1;
}
void push(int k){
	if(!flag[k]) return;
	make(ls,trans[k]);
	make(rs,trans[k]);
	for(int i=0;i<10;i++) trans[k][i]=i;
	flag[k]=0;
}
void change(int l,int r,int x,int y,int k,int s,int t){
	if(x<=l&&r<=y){add(k,s,t);return;}
	push(k);
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,x,y,ls,s,t);
	if(y>mid) change(mid+1,r,x,y,rs,s,t);
	upt(k);
}
ll get(int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){
		ll sum=0;
		for(int i=0;i<10;i++)
			sum+=(ll)p[k][i]*i;
		return sum;
	}
	push(k);
	int mid=l+r>>1;ll ans=0;
	if(x<=mid) ans+=get(l,mid,x,y,ls);
	if(y>mid) ans+=get(mid+1,r,x,y,rs);
	return ans;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n,1);
	for(int _=1;_<=q;_++){
		int t,l,r,x,y;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			scanf("%d%d",&x,&y);
			if(x==y) continue;
			change(1,n,l,r,1,x,y);
		}
		else printf("%lld\n",get(1,n,l,r,1));
	}
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}