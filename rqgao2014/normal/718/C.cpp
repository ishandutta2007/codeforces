#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime cerr<<"time:"<<(ll)clock()*1000/CLOCKS_PER_SEC<<endl
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int mod=1e9+7,N=100005;
struct matrix{
	int x,y;
	int a[2][2];
	void build(int p,int q){x=p,y=q;}
	void upt(int c,int d,int e,int f){
		a[0][0]=c;a[0][1]=d;
		a[1][0]=e;a[1][1]=f;
	}
	void clear(){upt(1,0,0,1);}
}one;
int n,m,a[N];
matrix p[N<<3],flag[N<<3];
inline matrix operator * (const matrix &a,const matrix &b){
	matrix tmp;
	memset(tmp.a,0,sizeof(tmp.a));
	tmp.x=a.x;tmp.y=b.y;
	for(int i=0;i<a.x;i++)
		for(int j=0;j<a.y;j++)
			for(int k=0;k<b.y;k++){
				(tmp.a[i][k]+=(ll)a.a[i][j]*b.a[j][k]%mod)%=mod;
			}
	return tmp;
}
inline void operator *= (matrix &a,const matrix &b){
	a=a*b;
}
inline matrix operator + (matrix a,const matrix &b){
	for(int i=0;i<a.x;i++)
		for(int j=0;j<a.y;j++)
			a.a[i][j]=(b.a[i][j]+a.a[i][j])%mod;
	return a;
}
inline matrix exp(matrix x,int y){
	matrix ans;ans.build(2,2);ans.clear();
	while(y){
		if(y&1) ans=ans*x;
		x=x*x;y>>=1;
	}
	return ans;
}

inline void build(int l,int r,int k){
	flag[k].build(2,2);flag[k].clear();
	p[k].build(2,1);
	if(l==r){
		matrix t=exp(one,a[l]);
		p[k].a[0][0]=t.a[0][1];p[k].a[1][0]=t.a[1][1];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
	p[k]=p[ls]+p[rs];
}
inline void pushdown(int l,int r,int k){
	flag[ls]*=flag[k];
	flag[rs]*=flag[k];
	p[ls]=flag[k]*p[ls];
	p[rs]=flag[k]*p[rs];
	flag[k].clear();
}
inline void change(int l,int r,int x,int y,int k,const matrix b){
	if(l==x&&y==r){
		flag[k]=flag[k]*b;p[k]=b*p[k];
		return;
	}
	pushdown(l,r,k);
	int mid=l+r>>1;
	matrix tmp;tmp.build(2,1);tmp.upt(0,0,0,0);
	if(x<=mid) change(l,mid,x,min(y,mid),ls,b);
	if(y>mid) change(mid+1,r,max(mid+1,x),y,rs,b);
	p[k]=p[ls]+p[rs];
}
inline matrix get(int l,int r,int x,int y,int k){
	pushdown(l,r,k);
	if(l==x&&y==r) return p[k];
	int mid=l+r>>1;
	matrix tmp;tmp.build(2,1);tmp.upt(0,0,0,0);
	if(x<=mid) tmp=tmp+get(l,mid,x,min(y,mid),ls);
	if(y>mid) tmp=tmp+get(mid+1,r,max(mid+1,x),y,rs);
	return tmp;
}

int main(){
//#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
//#endif
	one.x=one.y=2;
	one.upt(0,1,1,1);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n,1);
	while(m--){
		int typ,l,r,k;
		scanf("%d%d%d",&typ,&l,&r);
		if(typ==1) scanf("%d",&k),change(1,n,l,r,1,exp(one,k));
		else printf("%d\n",get(1,n,l,r,1).a[0][0]);
	}
	return 0;
}