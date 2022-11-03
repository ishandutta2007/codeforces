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

int n,m,q;
int u[1<<18],v[1<<18];

struct DSU_2ft_kc9h{
	int fa[1<<18],pre[1<<18];
	void init(){
		memset(fa,-1,sizeof(fa));
	}
	vector<pair<pair<int,int>,pair<int,int> > > kc;
	pair<int,int> root(int a){
		int col=0;
		while(fa[a]>=0){
			col^=pre[a];
			a=fa[a];
		}
		return mak(a,col);
	}
	bool conn(int a,int b){
		pair<int,int> x=root(a),y=root(b);
		if(x.first==y.first){
			if(x.second==y.second)return 0;
			return 1;
		}
		if(fa[x.first]>fa[y.first])swap(x,y);
		kc.pub(mak(mak(x.first,y.first),mak(fa[x.first],fa[y.first])));
		fa[x.first]+=fa[y.first];fa[y.first]=x.first;
		pre[y.first]=x.second^y.second^1;
		return 1;
	}
	void back(){
		fa[kc.back().first.first]=kc.back().second.first;
		fa[kc.back().first.second]=kc.back().second.second;
		kc.pob();
	}
}dsu;

int bnd[1<<18];

void backtostate(int state){
	while(dsu.kc.size()>state)dsu.back();
}

void fendge(int l1,int l2,int r1,int r2){
	if(l1>l2)return;
	int lm=(l1+l2)>>1;
	int res=-1;
	int state=dsu.kc.size();
	circ(i,l1,lm-1)if(!dsu.conn(u[i],v[i])){
		res=r2;
		break;
	}
	int state2=dsu.kc.size();
	if(!~res){
		res=r1;
		cric(i,r1,r2)if(i!=m+1&&!dsu.conn(u[i],v[i])){
			res=i;
			break;
		}
	}
	bnd[lm]=res;
	if(bnd[lm]==m+1){
		circ(i,lm+1,l2)bnd[i]=m+1;
	}else{
		backtostate(state2);
		if(!dsu.conn(u[lm],v[lm])){
			circ(i,lm+1,l2)bnd[i]=m+1;
		}else{
			fendge(lm+1,l2,res,r2);
		}
	}
	backtostate(state);
	circ(i,res+1,r2)dsu.conn(u[i],v[i]);
	fendge(l1,lm-1,r1,res);
	backtostate(state);
}

int main(){
	dsu.init();
	scanf("%d%d%d",&n,&m,&q);
	cont(i,m)scanf("%d%d",u+i,v+i);
	fendge(1,m,1,m+1);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		if(r>=bnd[l])puts("NO");
		else puts("YES");
	}
	return 0;
}