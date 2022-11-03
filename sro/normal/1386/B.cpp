/* by Natsu Kinmoe */
/* 2020/07/24 */
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

int s,p,g,n,m;

struct Point{
	lf x,y;
	Point(){}
	Point(lf x,lf y):x(x),y(y){}
}t,b[1<<17];

int main(){
	scanf("%d%d%d%d",&s,&p,&g,&n);
	t=Point((lf)1.0*s/(s+p+g),(lf)1.0*p/(s+p+g));
	int chs=0,lns=0,siz=0;
	map<lf,int> ss;
	while(n--){
		char mode;scanf(" %c",&mode);
		if(mode=='A'){
			int s,p,g;scanf("%d%d%d",&s,&p,&g);
			b[++m]=Point((lf)1.0*s/(s+p+g),(lf)1.0*p/(s+p+g));
			if(fabs(b[m].x-t.x)<1e-10&&fabs(b[m].y-t.y)<1e-10)chs++;
			else{
				lf jj=atan2l(b[m].y-t.y,b[m].x-t.x);
				lf kk=atan2l(t.y-b[m].y,t.x-b[m].x);
				auto x=ss.lower_bound(kk-1e-10);
				if(x!=ss.end()&&fabs(x->first-kk)<1e-10)lns+=x->second;
				auto y=ss.lower_bound(jj-1e-10);
				if(y!=ss.end()&&fabs(y->first-jj)<1e-10)y->second++;
				else ss[jj]=1;
			}
			siz++;
		}else{
			int m;scanf("%d",&m);
			if(fabs(b[m].x-t.x)<1e-10&&fabs(b[m].y-t.y)<1e-10)chs--;
			else{
				lf jj=atan2l(b[m].y-t.y,b[m].x-t.x);
				lf kk=atan2l(t.y-b[m].y,t.x-b[m].x);
				auto x=ss.lower_bound(kk-1e-10);
				if(x!=ss.end()&&fabs(x->first-kk)<1e-10)lns-=x->second;
				auto y=ss.lower_bound(jj-1e-10);
				y->second--;
				if(!y->second)ss.erase(y);
			}
			siz--;
		}
		if(chs)puts("1");
		else if(lns)puts("2");
		else{
			if(!ss.size()||siz<3){
				puts("0");
				continue;
			}
			auto bk=ss.end();bk--;
			lf xju=ss.begin()->first+2*pi-bk->first;
			auto x=ss.lower_bound(0);
			if(x==ss.begin()){
				puts("0");
				continue;
			}
			auto y=x;y--;
			lf yju=x->first-y->first;
			if(xju>pi-1e-10||yju>pi-1e-10){
				puts("0");
				continue;
			}
			puts("3");
		}
	}
	return 0;
}