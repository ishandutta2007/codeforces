#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

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

const int N = 1e5+5;

int n,m,k;
struct point{
	int x,y,z;
	point(const int x_=0,const int y_=0,const int z_=0){x=x_;y=y_;z=z_;}
	void read(){x=get();y=get();z=get();}
	friend bool operator <=(point a,point b){return a.x<=b.x&&a.y<=b.y&&a.z<=b.z;}
}a[N],Lim;
struct addition{
	int lx,rx,ly,ry;
	int ty,id;
	int z;
}ad[N*3];
int s;
int ans[N];

void add(point L,point R,point u,int id){
	L.x=min(L.x,u.x);
	L.y=min(L.y,u.y);
	L.z=min(L.z,u.z);
	R.x=max(R.x,u.x);
	R.y=max(R.y,u.y);
	R.z=max(R.z,u.z);
	s++;
	ad[s].ty=2;
	ad[s].lx=L.x,ad[s].rx=R.x,ad[s].ly=L.y,ad[s].ry=R.y;
	ad[s].id=-id;
	ad[s].z=L.z-1;
	s++;
	ad[s].ty=2;
	ad[s].lx=L.x,ad[s].rx=R.x,ad[s].ly=L.y,ad[s].ry=R.y;
	ad[s].id=id;
	ad[s].z=R.z;
}

struct POINT{
	int x,y;
	POINT(const int x_=0,const int y_=0){x=x_,y=y_;}
}num[N];
bool sig;
struct node{
	int x,y,l,r;
	int lx,rx,ly,ry;
	int cnt,v;
}tree[N];
int rt,tot;
int fa[N];

bool cmp(POINT a,POINT b){
	if (sig)return a.x<b.x;
	return a.y<b.y;
}

int build(int l,int r,bool sg){
	sig=sg;
	int mid=(l+r)/2;
	int now=++tot;
	nth_element(num+l,num+mid,num+r+1,cmp);
	tree[now].x=num[mid].x;
	tree[now].y=num[mid].y;
	if (l<mid)tree[now].l=build(l,mid-1,sg^1);
	if (mid<r)tree[now].r=build(mid+1,r,sg^1);
	tree[now].lx=tree[now].rx=tree[now].x;
	tree[now].ly=tree[now].ry=tree[now].y;
	if (tree[now].l){
		int x=tree[now].l;
		tree[now].lx=min(tree[now].lx,tree[x].lx);
		tree[now].rx=max(tree[now].rx,tree[x].rx);
		tree[now].ly=min(tree[now].ly,tree[x].ly);
		tree[now].ry=max(tree[now].ry,tree[x].ry);
	}
	if (tree[now].r){
		int x=tree[now].r;
		tree[now].lx=min(tree[now].lx,tree[x].lx);
		tree[now].rx=max(tree[now].rx,tree[x].rx);
		tree[now].ly=min(tree[now].ly,tree[x].ly);
		tree[now].ry=max(tree[now].ry,tree[x].ry);
	}
	return now;
}

bool cp(addition a,addition b){return a.z!=b.z?a.z<b.z:a.ty<b.ty;}

bool add(int now,int x,int y){
	if(tree[now].x==x&&tree[now].y==y){
		tree[now].cnt++;
		tree[now].v++;
		return 1;
	}
	if(x<tree[now].lx||x>tree[now].rx||y<tree[now].ly||y>tree[now].ry)return 0;
	if(tree[now].l&&add(tree[now].l,x,y)){tree[now].cnt++;return 1;}
	if(tree[now].r&&add(tree[now].r,x,y)){tree[now].cnt++;return 1;}
	return 0;
}

int query(int now,int lx,int rx,int ly,int ry){
	if (lx<=tree[now].lx&&tree[now].rx<=rx&&ly<=tree[now].ly&&tree[now].ry<=ry)return tree[now].cnt;
	if (rx<tree[now].lx||lx>tree[now].rx||ry<tree[now].ly||ly>tree[now].ry)return 0;
	int ret=0;
	if (lx<=tree[now].x&&tree[now].x<=rx&&ly<=tree[now].y&&tree[now].y<=ry)ret=tree[now].v;
	if (tree[now].l)ret=ret+query(tree[now].l,lx,rx,ly,ry);
	if (tree[now].r)ret=ret+query(tree[now].r,lx,rx,ly,ry);
	return ret;
}

int main(){
//	freopen("data.in","r",stdin);
	Lim.read();
	n=get();m=get();k=get();
	point R=point(0,0,0),L=point(1e9,1e9,1e9);
	fo(i,1,n){
		point u;
		u.read();
		L.x=min(L.x,u.x);
		L.y=min(L.y,u.y);
		L.z=min(L.z,u.z);
		R.x=max(R.x,u.x);
		R.y=max(R.y,u.y);
		R.z=max(R.z,u.z);
	}
	fo(i,1,m){
		point u;
		u.read();
		a[i]=u;
		if(L<=u&&u<=R)return printf("INCORRECT\n"),0;
	}
	printf("CORRECT\n");
	fo(i,1,k){
		point p;
		p.read();
		if(L<=p&&p<=R)ans[i]=-1;
		else{
			add(L,R,p,i);
		}
	}
	fo(i,1,m){
		num[i]=POINT(a[i].x,a[i].y);
		s++;
		ad[s].lx=a[i].x,ad[s].ly=a[i].y;
		ad[s].z=a[i].z;
		ad[s].ty=1;
	}
	sig=1;
	rt=build(1,m,1);
	sort(ad+1,ad+1+s,cp);
	fo(i,1,s)
	if(ad[i].ty==1){
		add(rt,ad[i].lx,ad[i].ly);
	}
	else{
		int id=ad[i].id;
		if(id<0)ans[-id]=ans[-id]-query(rt,ad[i].lx,ad[i].rx,ad[i].ly,ad[i].ry);
		else ans[id]=ans[id]+query(rt,ad[i].lx,ad[i].rx,ad[i].ly,ad[i].ry);
	}
	fo(i,1,k)
	if (ans[i]<0)printf("OPEN\n");
	else if (ans[i]==0)printf("UNKNOWN\n");
		else printf("CLOSED\n");
	return 0;
}