#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define max_N 50005
typedef long long ll;

inline ll gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	ll x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

ll k;

int n,m,P,S[max_N];

struct mat{
	int a[2][2];
	mat(int i=0){
		a[0][0]=a[1][1]=i;
		a[0][1]=a[1][0]=0;	
	}
	friend mat operator*(const mat&x,const mat&y){
		mat res;
		for(int i=0;i<2;++i)for(int j=0;j<2;++j){
			res.a[i][j]=(1ll*x.a[i][0]*y.a[0][j]+1ll*x.a[i][1]*y.a[1][j])%P;
		}
		return res;
	}
}T[max_N<<2],Sn,ans;

inline mat qpow(mat x,ll k){
	mat res(1);
	for(;k;x=x*x,k>>=1)if(k&1)res=res*x;
	return res;
}

#define lch x<<1,l,mid
#define rch x<<1|1,mid+1,r

void build(int x,int l,int r){
	if(l==r){
		T[x].a[0][0]=0,T[x].a[1][0]=1;
		T[x].a[0][1]=S[(l+n-2)%n];
		T[x].a[1][1]=S[(l+n-1)%n];
		return;
	}
	int mid=(l+r)>>1;
	build(lch),build(rch);
	T[x]=T[x<<1]*T[x<<1|1];
}

mat query(int x,int l,int r,int ll,int rr){
	if(l==ll&&r==rr)return T[x];
	int mid=(l+r)>>1;
	if(rr<=mid)return query(lch,ll,rr);
	if(ll>mid) return query(rch,ll,rr);
	return query(lch,ll,mid)*query(rch,mid+1,rr);
}

inline void calc(ll a,ll b){
	if(a>b)return;
	if(a/n==b/n)ans=ans*query(1,0,n-1,a%n,b%n);
	else{
		ans=ans*query(1,0,n-1,a%n,n-1);
		ans=ans*qpow(T[1],b/n-a/n-1);
		ans=ans*query(1,0,n-1,0,b%n);
	}
}

map<ll,int>s;

vector<ll>q;

ll cur;

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("st.out","w",stdout);
	k=gint(),P=gint();
	if(P==1)return puts("0"),0;
	n=gint();
	for(int i=0;i<n;++i)S[i]=gint()%P;
	if(k<2)return printf("%d\n",k%P),0;
	build(1,0,n-1);
	m=gint();
	for(int i=1;i<=m;++i){
		ll j=gint();
		int v=gint()%P;
		if(j+1<=k)q.push_back(j+1);
		if(j+2<=k)q.push_back(j+2);
		s[j]=v;
	}
	q.push_back(k);
	sort(q.begin(),q.end());
	q.erase(unique(q.begin(),q.end()),q.end());
	cur=1;
	ans=mat(1);
	for(int i=0,L=q.size();i<L;++i){
		calc(cur+1,q[i]-1);
		mat tmp;
		tmp.a[0][0]=0,tmp.a[1][0]=1;
		tmp.a[0][1]=s.count(q[i]-2)?s[q[i]-2]:S[(q[i]+n-2)%n];
		tmp.a[1][1]=s.count(q[i]-1)?s[q[i]-1]:S[(q[i]+n-1)%n];
		ans=ans*tmp;
		cur=q[i];
	}
	printf("%d\n",ans.a[1][1]);
	return 0;
}