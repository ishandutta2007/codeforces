/* by Natsu Kinmoe */
/* 2020/07/20 */
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

int n;
vector<int> nei[1555];
int siz[1555];
int res[1555];

struct Point{
	int x,y,id;
	bool operator<(const Point &p)const{return x==p.x?y<p.y:x<p.x;}
}p[1555];

void predfs(int now,int lst){
	siz[now]=1;
	foreach(i,nei[now])if(*i!=lst){
		predfs(*i,now);
		siz[now]+=siz[*i];
	}
}

void dfs(int now,int lst,int l,int r){
	sort(p+l,p+r+1);
	Point &op=p[l];res[op.id]=now;l++;
	sort(p+l,p+r+1,[&](const Point &a,const Point &b){
		return 1ll*(b.x-op.x)*(a.y-op.y)-1ll*(a.x-op.x)*(b.y-op.y)<0;
	});
	foreach(i,nei[now])if(*i!=lst)dfs(*i,now,l,l+siz[*i]-1),l+=siz[*i];
}

int main(){
	scanf("%d",&n);
	loop(i,n-1){
		int u,v;scanf("%d%d",&u,&v);
		nei[u].pub(v);nei[v].pub(u);
	}
	cont(i,n)scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	predfs(1,0);
	dfs(1,0,1,n);
	cont(i,n)printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}