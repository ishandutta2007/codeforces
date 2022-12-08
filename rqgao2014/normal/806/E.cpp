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
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=1000005,M=100005,mod=1e9+7,bnd=500000;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n;
struct BIT{
	int c[N];
	inline void ch(int x,int y){while(x<=bnd*2+1) c[x]+=y,x+=x&-x;}
	inline void ch(int l,int r,int k){ch(l+bnd+1,k);ch(r+bnd+2,-k);}
	inline int get(int x){
		x+=bnd+1;
		int ans=0;
		while(x)ans+=c[x],x-=x&-x;
		return ans;
	}
}p2;
struct SGT{
	int p[N<<2];
	int flag[N<<2];
	void build(int l,int r,int k){
		if(l==r){p[k]=-l;return;}
		int mid=l+r>>1;
		build(l,mid,ls);build(mid+1,r,rs);
		p[k]=max(p[ls],p[rs]);
	}
	void add(int k,int b){
		p[k]+=b;flag[k]+=b;
	}
	void push(int k){
		if(!flag[k]) return ;
		add(ls,flag[k]);add(rs,flag[k]);
		flag[k]=0;
	}
	void ch(int l,int r,int x,int y,int k,int b){
		if(x<=l&&r<=y){add(k,b);return;}
		push(k);
		int mid=l+r>>1;
		if(x<=mid) ch(l,mid,x,y,ls,b);
		if(y>mid) ch(mid+1,r,x,y,rs,b);
		p[k]=max(p[ls],p[rs]);
	}
	int get(int l,int r,int x,int y,int k){
		if(x<=l&&r<=y) return p[k];
		push(k);
		int mid=l+r>>1,ans=-inf;
		if(x<=mid) gmax(ans,get(l,mid,x,y,ls));
		if(y>mid) gmax(ans,get(mid+1,r,x,y,rs));
		return ans;
	}
	int qry(int l,int r,int x,int y,int k,int b){
		if(p[k]<b) return bnd+1;
		if(l==r) return r;
		push(k);int mid=l+r>>1;
		if(x<=l&&r<=y){
			if(p[ls]>=b) return qry(l,mid,x,y,ls,b);
			return qry(mid+1,r,x,y,rs,b);
		}
		if(x<=mid){
			int t=qry(l,mid,x,y,ls,b);
			if(t<=bnd) return t;
		}
		return qry(mid+1,r,x,y,rs,b);
	}
	void ch(int l,int r,int x){ch(-bnd,bnd,l,r,1,x);}
	int get(int l,int r){return get(-bnd,bnd,l,r,1);}
	int qry(int l,int r,int t){return qry(-bnd,bnd,l,r,1,t);}
}p1;

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	p1.build(-bnd,bnd,1);
	int l=0;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		p1.ch(x,bnd,1);
		if(x<l){
			int t=p1.get(l-1,l-1);
			if(t+l-1>-l)
				l--,p2.ch(l,l,l),p2.ch(l+1,p1.qry(l+1,bnd,t)-1,-1);
		}
		else if(x>l)
			p2.ch(x,p1.qry(x,bnd,p1.get(x-1,x-1)+x-p2.get(x-1))-1,1);
		printf("%d\n",p2.get(bnd));
	}
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}