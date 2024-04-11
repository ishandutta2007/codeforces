/* by Natsu Kinmoe */
/* 2020/06/27 */
#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=0;i<(n);i++)
#define pool(i,n) for(int i=(n)-1;i>=0;i--)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define tnoc(i,n) for(int i=(n);i>=1;i--)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define cric(i,a,b) for(int i=(b);i>=(a);i--)
#define sub(i,a) for(int i=a;i;i=((i-1)&(a)))
#define subs(i,a) for(int i=a;i>=0;i=(!i?-1:((i-1)&(a))))
#define subt(i,a) for(int i=((a-1)&a);i;i=((i-1)&(a)))
#define subst(i,a) for(int i=((a-1)&a);i>=0;i=(!i?-1:((i-1)&(a))))
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define parse(i,s) for(int i=0;s[i];i++)

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mak make_pair

#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define ws WSrAkIoi2333wSraKIoIWSraKiOi
#define left left_jTjTJtJtIoiiOiioIAuaU66666jtIOIau
#define hash whYusEthiSnamE_caNyoUusEothERnaMesliKeHSH

#define Mask(a) (1ll<<(a))
#define Maskx(a,x) ((a)<<(x))
#define Full(a) ((1ll<<(a))-1)
#define Bit(a,x) (((a)>>(x))&1)
#define all(a) (a).begin(),(a).end()
#define SZ(a) ((int)((a).size()))

typedef long long ll;
typedef long double lf;

const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const lf inF=11451419198101145141919810.1145141919810;
const lf pi=acosl(-1);
/* Source code starts here */

const int jt=998244353,rg=3,Maxn=1<<18,maxn=18;
int n;
ll m;
int p[Maxn];
int x[Maxn],y[Maxn];
int hd[Maxn];
int jc[Maxn],fjc[Maxn];

int inline ksmii(int a,int b){
	if(b<0)return ksmii(a,b+jt-1);if(!b)return 1;
	int x=ksmii(a,b>>1);x=1ll*x*x%jt;
	if(b&1)x=1ll*x*a%jt;return x;
}

void init(){
	loop(i,Maxn)hd[i]=((hd[i>>1]>>1)|((i&1)<<(maxn-1)));
	jc[0]=1;cont(i,Maxn-1)jc[i]=1ll*jc[i-1]*i%jt;
	fjc[Maxn-1]=ksmii(jc[Maxn-1],-1);tnoc(i,Maxn-1)fjc[i-1]=1ll*fjc[i]*i%jt;
}

void fft(int a[],int inv){
	loop(i,Maxn)if(i<hd[i])swap(a[i],a[hd[i]]);
	range(i,1,Maxn-1,i){
		int omega=ksmii(rg,inv*(jt-1)/(i<<1));
		range(j,0,Maxn-1,i<<1){
			int omg=1;
			loop(k,i){
				int x=a[j+k],y=1ll*omg*a[j+k+i]%jt;
				a[j+k]=(x+y)%jt;
				a[j+k+i]=(x+jt-y)%jt;
				omg=1ll*omg*omega%jt;
			}
		}
	}
	if(inv==-1){
		int fn=ksmii(Maxn,-1);
		loop(i,Maxn)a[i]=1ll*a[i]*fn%jt;
	}
}

int main(){
	init();
	scanf("%d%lld",&n,&m);
	loop(i,n+1)scanf("%d",p+i);
	loop(i,n+1)x[i]=1ll*p[i]*jc[i]%jt;
	loop(i,n+1)y[i]=fjc[n-i];
	fft(x,1);fft(y,1);
	loop(i,Maxn)x[i]=1ll*x[i]*y[i]%jt;fft(x,-1);
	loop(i,n+1)x[i]=x[i+n],x[i+n]=0,x[i]=1ll*x[i]*fjc[i]%jt;
	loop(i,n+1)if(i&1)x[i]=jt-x[i];
	loop(i,n+1)x[i]=1ll*x[i]*ksmii(i+1,-m%(jt-1))%jt*jc[i]%jt;
	fft(x,1);loop(i,Maxn)x[i]=1ll*x[i]*y[i]%jt;fft(x,-1);
	loop(i,n+1)x[i]=x[i+n],x[i+n]=0,x[i]=1ll*x[i]*fjc[i]%jt;
	loop(i,n+1)if(i&1)x[i]=(jt-x[i])%jt;
	loop(i,n+1)printf("%d%c",x[i]," \n"[i==n]);
	return 0;
}