#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
struct rzz{
	int key,id;
	inline rzz(int a=0,int b=0){
		key=a;id=b;
	}
};
const int MAXN=210000;
multiset<rzz>dout,din,uout,uin;
struct yd{
	int t,s,f,id;
}a[MAXN];
inline bool operator <(const rzz &a,const rzz &b){return a.key<b.key;}
LL t;int f;int now;
int n,m;
LL res[MAXN];
inline void gountil(LL lim){
	while(!(din.empty()&dout.empty()&uout.empty()&uin.empty()))
	if(uin.size()+uout.size()>=din.size()+dout.size()){
		int goal=m+1;
		if(!uout.empty())goal=min(goal,uout.begin()->key);
		if(!uin.empty())goal=min(goal,uin.begin()->key);
		if(goal-f+t>lim){
			f+=lim-t;
			return;
		}
		t+=goal-f;
		f=goal;
		while(!uin.empty()&&(uin.begin()->key)==f){
			res[a[uin.begin()->id].id]=t;
			uin.erase(uin.begin());
		}
		while(!uout.empty()&&(uout.begin()->key)==f){
			if(a[uout.begin()->id].f>f)
			uin.insert(rzz(a[uout.begin()->id].f,uout.begin()->id));
			else din.insert(rzz(a[uout.begin()->id].f,uout.begin()->id));
			uout.erase(uout.begin());
		}
	}
	else{
		int goal=0;
		if(!dout.empty())goal=max(goal,(--dout.end())->key);
		if(!din.empty())goal=max(goal,(--din.end())->key);
		if(f-goal+t>lim){
			f-=lim-t;
			return;
		}
		t+=f-goal;
		f=goal;
		while(!din.empty()&&((--din.end())->key)==f){
			res[a[(--din.end())->id].id]=t;
			din.erase((--din.end()));
		}
		while(!dout.empty()&&((--dout.end())->key)==f){
			if(a[(--dout.end())->id].f>f)
			uin.insert(rzz(a[(--dout.end())->id].f,(--dout.end())->id));
			else din.insert(rzz(a[(--dout.end())->id].f,(--dout.end())->id));
			dout.erase((--dout.end()));
		}
	}
}
inline bool cmp_t(const yd &a,const yd &b){return a.t<b.t;}
int main(){
	scanf("%d%d",&n,&m);f=1;
	rep(i,1,n){scanf("%d%d%d",&a[i].t,&a[i].s,&a[i].f);a[i].id=i;}
	sort(a+1,a+1+n,cmp_t);
	rep(i,1,n){
		t=a[i].t;
		if(a[i].s<f)dout.insert(rzz(a[i].s,i));
		else if(a[i].s>f)uout.insert(rzz(a[i].s,i));
		else if(a[i].f>f)uin.insert(rzz(a[i].f,i));
		else if(a[i].f<f)din.insert(rzz(a[i].f,i));
		if(i<n)gountil(a[i+1].t);
		else gountil((LL)1e18);
	}
	rep(i,1,n)printf("%I64d\n",res[i]);
	return 0;
}