#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=2005,P=1e9+7;
int n,m,R,fac[N],inv[N],ifac[N];
struct data{
	int x,y,B,cnt;
	bitset<N>b;
}A[N];
void addx(int&k1,int k2){
	(k1+=k2)>=P&&(k1-=P);
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int calc(int x){return (x%P+P)%P;}
signed main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	rd(n),rd(m),rd(R);
	rep(i,1,n){
		rd(A[i].x),rd(A[i].y),rd(A[i].B);
	}
	rep(i,1,n){
		rep(j,i,n){
			if(max(abs(A[i].x-A[j].x),abs(A[i].y-A[j].y))<=R){
				A[i].b.set(j);
				A[j].b.set(i);
			}
		}
	}
	rep(i,1,n)A[i].cnt=A[i].b.count();
	auto fun=[&](int x)->LL{
		return C(x,m);
	};
	int ans=0;
	rep(i,1,n){
		rep(j,1,n){
			int k1=A[i].cnt;
			int k2=A[j].cnt;
			int k3=(A[i].b&A[j].b).count();
			k1-=k3,k2-=k3;
			int k4=n-k1-k2-k3;
			D("i=%d j=%d onlyA=%d onlyB=%d allhave=%d allnot=%d\n",i,j,k1,k2,k3,k4);
			addx(ans,1LL*A[i].B*A[j].B%P*calc(fun(n)-fun(n-k1-k3)-fun(n-k2-k3)+fun(k4))%P);
		}
	}
	ans=(ans%P+P)%P;
	printf("%lld\n",ans);
	return 0;
}