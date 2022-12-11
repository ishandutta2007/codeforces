#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 1e5+5;
const db eps =1e-10;

int n;
LL T;
struct quest{
	db a,b,p;
}a[N];
db M;

bool cmp(quest a,quest b){return fabs(a.p-b.p)<eps?a.a>b.a:a.p<b.p;}

quest sta[N];
LL st[N];
db f[N];
int top;

struct matrix{
	db a[3][3];
	db* operator [](int x){return a[x];}
	void init(){fo(i,0,2)a[i][0]=a[i][1]=a[i][2]=0;}
	void init(quest x){
		a[0][0]=a[1][1]=1;
		a[0][2]=x.p;
		a[1][0]=M;a[1][2]=x.p*x.a;
		a[2][2]=db(1)-x.p;
	}
}mix[100],miy[100];
struct vct{
	db a[3];
	db & operator [](int x){return a[x];}
	void init(){a[0]=a[1]=a[2]=0;}
}nowx,nowy,tmpx,tmpy;
matrix operator *(matrix a,matrix b){
	matrix c;
	fo(i,0,2)
		fo(j,0,2)
		c[i][j]=(a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j]);
	return c;
}

vct operator *(vct a,matrix b){
	vct c;
	c[0]=a[0]*b[0][0]+a[1]*b[1][0]+a[2]*b[2][0];
	c[1]=a[0]*b[0][1]+a[1]*b[1][1]+a[2]*b[2][1];
	c[2]=a[0]*b[0][2]+a[1]*b[1][2]+a[2]*b[2][2];
	return c;
}

LL getst(quest x,quest y,LL st,db f0){
	st--;
	mix[0].init(x);
	miy[0].init(y);
	nowx.init(),nowy.init();
	nowx[0]=M*st,nowx[1]=1,nowx[2]=f0;
	nowy[0]=M*st,nowy[1]=1,nowy[2]=f0;
	fo(i,1,34)mix[i]=mix[i-1]*mix[i-1],miy[i]=mix[i-1]*miy[i-1];
	fd(i,34,0){
		tmpx=nowx*mix[i];
		tmpy=nowy*miy[i];
		if (tmpx[2]>tmpy[2])st+=(1ll<<i),nowx=tmpx,nowy=nowy*mix[i];
	}
	return st+1;
}

db calc(quest x,db f0,LL st,LL ed){
	mix[0].init(x);
	fo(i,1,34)mix[i]=mix[i-1]*mix[i-1];
	nowx.init();
	nowx[0]=M*st,nowx[1]=1,nowx[2]=f0;
	fd(i,34,0)
	if (st+(1ll<<i)<=ed){
		st+=(1ll<<i);
		nowx=nowx*mix[i];
	}
	return nowx[2];
}

int main(){
	M=0;
	scanf("%d%I64d",&n,&T);
	fo(i,1,n){
		scanf("%lf%lf%lf",&a[i].a,&a[i].b,&a[i].p);
		M=max(M,a[i].p*a[i].b);
	}
	sort(a+1,a+1+n,cmp);
	fo(i,1,n){
		while(top&&getst(sta[top],a[i],st[top],f[top])<=st[top])top--;
		sta[++top]=a[i];
		if (top>1){
			st[top]=getst(sta[top-1],sta[top],st[top-1],f[top-1]);
			f[top]=calc(sta[top-1],f[top-1],st[top-1]-1,st[top]-1);
		}
		else st[top]=1,f[top]=0;
	}
	db ans=0;
	fd(i,top,1)if (st[i]<=T){ans=calc(sta[i],f[i],st[i]-1,T);break;}
	printf("%.9lf\n",double(ans));
	return 0;
}