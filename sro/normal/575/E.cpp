/* by Natsu Kinmoe, on 2020/07/25 */
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

struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
	inline point operator-(const point &pt)const{return point(x-pt.x,y-pt.y);}
	inline ll operator%(const point &pt)const{return 1ll*x*pt.y-1ll*y*pt.x;}
	inline bool operator<(const point &p)const{return x==p.x?y<p.y:x<p.x;}
	inline lf size()const{return sqrtl(1ll*x*x+1ll*y*y);}
};

const int M=100000;
int n;
int x[1<<17],y[1<<17],v[1<<17];
vector<point> ps,tb;

void inline apt(int X,int Y,int id){
	if(abs(X-x[id])+abs(Y-y[id])<=v[id]&&X>=0&&X<=M&&Y>=0&&Y<=M)ps.pub(point(X,Y));
}

int main(){
	scanf("%d",&n);
	cont(i,n){
		scanf("%d%d%d",x+i,y+i,v+i);
		apt(0,0,i);apt(0,M,i);apt(M,0,i);apt(M,M,i);
		apt(x[i]+v[i],y[i],i);apt(x[i]-v[i],y[i],i);apt(x[i],y[i]+v[i],i);apt(x[i],y[i]-v[i],i);
		apt(0,y[i]+v[i]-x[i],i);apt(0,y[i]-v[i]+x[i],i);apt(x[i]+v[i]-y[i],0,i);apt(x[i]-v[i]+y[i],0,i);
		apt(M,y[i]+v[i]-M+x[i],i);apt(M,y[i]-v[i]+M-x[i],i);apt(x[i]+v[i]-M+y[i],M,i);apt(x[i]-v[i]+M-y[i],M,i);
	}
	sort(all(ps));
	loop(i,ps.size()){
		while(tb.size()>1&&(tb[tb.size()-2]-tb.back())%(ps[i]-tb.back())<=0)tb.pob();
		tb.pub(ps[i]);
	}
	int tbs=tb.size();
	reverse(all(ps));
	loop(i,ps.size()){
		while(tb.size()>tbs&&(tb[tb.size()-2]-tb.back())%(ps[i]-tb.back())<=0)tb.pob();
		tb.pub(ps[i]);
	}
	tb.pob();
	lf md=-1;
	point pa,pb,pc;
	for(int i=0,j=tb.size()-1,k=tb.size()-2;i<tb.size();k=j,j=i++){
		lf d=(tb[i]-tb[j]).size()*(tb[j]-tb[k]).size()*(tb[k]-tb[i]).size()/((tb[i]-tb[j])%(tb[j]-tb[k]));
		if(d>md){
			md=d;
			pa=tb[i];pb=tb[j];pc=tb[k];
		}
	}
	printf("%d %d\n",pa.x,pa.y);
	printf("%d %d\n",pb.x,pb.y);
	printf("%d %d\n",pc.x,pc.y);
	return 0;
}