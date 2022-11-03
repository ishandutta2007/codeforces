#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),ed=(v).end();it!=ed;it++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define all(a) a.begin(),a.end()
#define pub push_back
#define INF 0x3f3f3f3f3f3f3f3fll
template<typename _T>
inline _T chmax(_T &a,_T b){return a<b?(a=b):a;}

struct point{
	ll x,y;
	ll ang;
	point(){}
	point(ll x,ll y):x(x),y(y){ang=atan2l(y,x);}
	inline point operator-(const point &pt)const{return point(x-pt.x,y-pt.y);}
	inline ll operator*(const point &pt)const{return x*pt.x+y*pt.y;}//dot
	inline ll operator%(const point &pt)const{return x*pt.y-y*pt.x;}//det
};
inline bool xsmaller(const point &x,const point &y){
	return x.x==y.x?x.y<y.y:x.x<y.x;
}

int n;
point p[300005],stk[300005];
int top;
int ed[300005];
int mode[300005],id[300005];
bool O[300005];
ll ans[300005];
vector<point> seg[1200005];

void ins(int l,int r,int x,int now=1,int nl=1,int nr=n){
	if(nl>=l&&nr<=r){
		seg[now].pub(p[x]);
		return;
	}
	int m=(nl+nr)>>1;
	if(l<=m){
		ins(l,r,x,now<<1,nl,m);
	}
	if(r>m){
		ins(l,r,x,now<<1|1,m+1,nr);
	}
}

void getmax(int now){
	int l=1,r=top;
	while(r-l>2){
		int m1=l+(r-l)/3,m2=l+(r-l)*2/3;
		if(p[now]*stk[m1]<p[now]*stk[m2]){
			l=m1;
		}else{
			r=m2;
		}
	}
	circ(i,l,r){
		chmax(ans[now],p[now]*stk[i]);
	}
}

void getans(int now=1,int nl=1,int nr=n){
	if(nl<nr){
		int m=(nl+nr)>>1;
		getans(now<<1,nl,m);
		getans(now<<1|1,m+1,nr);
	}
	sort(all(seg[now]),xsmaller);
	top=0;
	foreach(i,seg[now]){
		while(top>1&&(stk[top]-stk[top-1])%(*i-stk[top])>=0){
			top--;
		}
		stk[++top]=*i;
	}
	circ(i,nl,nr){
		if(mode[i]==3&&!O[i]){
			getmax(i);
		}
	}
}

int main(){
	scanf("%d",&n);
	int cnt=0;
	cont(i,n){
		scanf("%d",mode+i);
		if(mode[i]==1){
			scanf("%lld%lld",&p[i].x,&p[i].y);
			ed[i]=n;
			cnt++;
		}else if(mode[i]==2){
			int id;
			scanf("%d",&id);
			ed[id]=i;
			cnt--;
		}else{
			scanf("%d",id+i);
			p[i]=point(id[i],1);
			if(!cnt){
				O[i]=1;
			}
			ans[i]=-INF;
		}
	}
	cont(i,n){
		if(mode[i]==1&&i+1<=ed[i]){
			ins(i,ed[i],i);
		}
	}
	getans();
	cont(i,n){
		if(mode[i]==3){
			if(O[i]){
				puts("EMPTY SET");
			}else{
				printf("%lld\n",ans[i]);
			}
		}
	}
	return 0;
}