/* by Natsu Kinmoe */
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

const int jt=998244353;
int jc[1<<19],fjc[1<<19];
int n,k;

int inline ksmii(int a,int b){
	if(!b) return 1;
	int x=ksmii(a,b>>1);
	x=1ll*x*x%jt;
	if(b&1) x=1ll*x*a%jt;
	return x;
}

int inline binom(int a,int b){
	if(a<b) return 0;
	return 1ll*jc[a]*fjc[b]%jt*fjc[a-b]%jt;
}

int main(){
	scanf("%d%d",&n,&k);
	if(n<k) return 0&puts("0");
	jc[0]=1;
	cont(i,n) jc[i]=1ll*jc[i-1]*i%jt;
	fjc[n]=ksmii(jc[n],jt-2);
	tnoc(i,n) fjc[i-1]=1ll*fjc[i]*i%jt;
	int res=0;
	cont(i,n) res=(res+binom(n/i-1,k-1))%jt;
	printf("%d\n",res);
	return 0;
}