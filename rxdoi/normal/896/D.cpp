#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

int A[N],B[N],C[N];
int n,p,l,r,ans,m,t,x,y;
vector<pii> V;

void exgcd(int a,int b,ll &x,ll &y){
	if (!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll tmp=x;x=y;y=tmp-a/b*y;
}
int inv(int a){
	ll x,y;
	exgcd(a,p,x,y);
	return (0ll+x+p)%p;
}

struct num{
	int val;
	Vi c;
	num(){}
	num(int x){
		c.resize(m);
		For(i,0,m){
			while (x%V[i].fi==0) x/=V[i].fi,c[i]++;
		}
		val=x;
	}
	int value(){
		int res=val;
		For(i,0,m) For(j,0,c[i]) res=1ll*res*V[i].fi%p;
		return res;
	}
} T[N],tmp;

num operator * (const num &A,const num &B){
	static num C;
	C.val=1ll*A.val*B.val%p;
	C.c.resize(m);
	For(i,0,m) C.c[i]=A.c[i]+B.c[i];
	return C;
}
num operator / (const num &A,const num &B){
	static num C;
	C.val=1ll*A.val*inv(B.val)%p;
	C.c.resize(m);
	For(i,0,m) C.c[i]=A.c[i]-B.c[i];
	return C;
}

void work(int n,int m){
	for (;x<n;x++) tmp=tmp*T[x+1]/T[x+1-y];
	for (;y<m;y++) tmp=tmp*T[x-y]/T[y+1];
}
void Init(){
	int x=p;
	for (int i=2;1ll*i*i<=x;i++)
		if (x%i==0){
			pii tmp=mp(i,0);
			while (x%i==0) x/=i,tmp.se++;
			V.pb(tmp);
		}
	if (x>1) V.pb(mp(x,1));
	m=V.size();
	For(i,1,n+1) T[i]=num(i);
}

int main(){
	n=IN(),p=IN(),l=IN(),r=IN();
	Init();
	
	A[0]=1;
	tmp=1;
	x=n,y=0;
	For(c,1,n+1){
		work(n,c);
		A[c]=tmp.value();
	}
	
	for (t=0;t<=n&&t<(t+l+1)/2;t++);
	B[t]=1;
	tmp=1;
	x=t;y=(t+l+1)/2;
	For(c,t+1,n+1){
		work(c,(c+l+1)/2);
		B[c]=tmp.value();
	}
	
	for (t=0;t<=n&&t<(t+r)/2+1;t++);
	C[t]=1;
	tmp=1;
	x=t;y=(t+r)/2+1;
	For(c,t+1,n+1){
		work(c,(c+r)/2+1);
		C[c]=tmp.value();
	}
	
	For(c,0,n+1){
		ans=(ans+1ll*A[c]*(0ll+B[c]-C[c]+p))%p;
	}
	printf("%d\n",ans);
}