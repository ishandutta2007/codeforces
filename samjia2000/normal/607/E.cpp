#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 50005;
const db eps = 1e-9;
const db pi = acos(-1);

int n,m;
struct point{
	db x,y;
	point(const db x_=0,db y_=0){x=x_;y=y_;}
}st;
point Md[N];
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
point operator *(point a,db c){return point(a.x*c,a.y*c);}
point operator /(point a,db c){return point(a.x/c,a.y/c);}
db cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
db cross(point a,point b){return a.x*b.y-a.y*b.x;}
db operator *(point a,point b){return a.x*b.x+a.y*b.y;}
db getdis(point a){return sqrt(a.x*a.x+a.y*a.y);}
point getsec(db k1,db b1,db k2,db b2){
	db x=(b2-b1)/(k1-k2);
	db y=k1*x+b1;
	return point(x,y);
}
point multi(point a,point b){return (a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
struct line{
	db k,b;
	db v,dis,dv;
}l[N];
pair<int,int>pt[N];
bool bz[N];
int k;
struct keypoint{
	point u;
	int id,ty;
}key[N*2];

bool cmp(keypoint a,keypoint b){
	if (a.ty!=b.ty)return a.ty<b.ty;
	return cross(a.u,b.u)>0;
}

int gettype(point u){
	if(fabs(u.y)<eps)return u.x>0?1:2;
	return u.y>0?1:2;
}

int bittree[N*2];
int to[N*2];

struct QUERY{
	int l,r,v,nxt;
}qry[N*4];
int h[N*2],et;

void addquery(int x,int l,int r,int v){qry[++et].l=l;qry[et].r=r;qry[et].v=v;qry[et].nxt=h[x];h[x]=et;}

void add(int x){for(;x<=k;x+=x&-x)bittree[x]++;}

int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bittree[x];return ret;}

LL calc(db R){
	k=0;
	fo(i,1,n){
		db v=l[i].v;
		db dis=l[i].dis;
		bz[i]=0;
		if (dis>=R*R)continue;
		bz[i]=1;
		if (fabs(l[i].k)<eps){
			db y=l[i].b;
			db x0=sqrt(R*R-y*y),x1=-x0;
			key[++k].u=point(x0,y);key[k].id=i;
			key[++k].u=point(x1,y);key[k].id=i;
			continue;
		}
		point M=Md[i];
		db len=R*R-dis;
		point direction=point(1,l[i].k)*sqrt(len/v);
		key[++k].u=M+direction;key[k].id=i;
		key[++k].u=M-direction;key[k].id=i;
	}
	fo(i,1,k)key[i].ty=gettype(key[i].u);
	sort(key+1,key+1+k,cmp);
	fo(i,1,n)pt[i]=make_pair(0,0);
	fo(i,1,k)
	if (pt[key[i].id].fi)pt[key[i].id].se=i;
	else pt[key[i].id].fi=i;
	fo(i,1,n)
	if (bz[i])to[pt[i].fi]=pt[i].se,to[pt[i].se]=pt[i].fi;
	LL ret=0;
	et=0;
	fo(i,1,k)h[i]=bittree[i]=0;
	fo(i,1,n)
	if (bz[i]){
		if (pt[i].fi>1){
			addquery(pt[i].se,1,pt[i].fi-1,1);
			addquery(pt[i].fi-1,1,pt[i].fi-1,-1);
		}
		if (pt[i].se<k){
			addquery(pt[i].se,pt[i].se+1,k,1);
			addquery(pt[i].fi-1,pt[i].se+1,k,-1);
		}
	}
	fo(i,1,k){
		add(to[i]);
		for(int p=h[i];p;p=qry[p].nxt)
		ret=ret+(query(qry[p].r)-query(qry[p].l-1))*qry[p].v;
	}
	ret/=2;
	return ret;
}

int be[N*2];
db ans;
int cnt;
struct node{
	int suf,pre;
}a[N*2];

void del(int w){
	int x=a[w].pre,y=a[w].suf;
	a[x].suf=y;
	a[y].pre=x;
}

void getans(db lim){
	calc(lim);
	fo(i,0,k)a[i].suf=i+1;
	fo(i,1,k+1)a[i].pre=i-1;
	int cnt=m;
	ans=0;
	fo(i,1,k)
	if(to[i]<i){
		int id=key[i].id;
		for(int x=a[i].pre;x!=to[i];x=a[x].pre){
			if (key[x].id!=id)cnt--,ans=ans+getdis(getsec(l[id].k,l[id].b,l[key[x].id].k,l[key[x].id].b));
		}
		del(i);
		del(to[i]);
	}
	ans=ans+lim*cnt;
	printf("%.9lf\n",ans);
}

int main(){
	n=get();
	st.x=get(),st.y=get();
	st.x/=1000,st.y/=1000;
	m=get();
	fo(i,1,n){
		l[i].k=get();l[i].b=get();
		l[i].k/=1000,l[i].b/=1000;
		l[i].b=l[i].b+l[i].k*st.x-st.y;
		l[i].v=l[i].k*l[i].k+1;
		l[i].dis=l[i].b*l[i].b/l[i].v;
		l[i].dv=sqrt(l[i].dis/l[i].v);
		point M=point(-l[i].k,1)*l[i].dv;
		if (fabs(l[i].k*M.x+l[i].b-M.y)>eps)M=M*(-1);
		Md[i]=M;
	}
	db l=0,r=1e13,ans=0;
	while((r-l)/l>eps){
		db mid=(l+r)/2;
		if (calc(mid)>=m)r=mid-eps;
		else l=mid+eps,ans=mid;
	}
	getans(ans);
	return 0;
}