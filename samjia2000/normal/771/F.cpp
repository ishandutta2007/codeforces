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

const int N = 200005;
const db eps = 1e-7;
const db MAX = 1000000;

int n;
struct point{
	db x,y;
	point(const db x_=0,const db y_=0){x=x_;y=y_;}
	void read(){x=get();y=get();}
}a[N],origin,O;
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}

db fabs(db x){return x<0?-x:x;}
db fmax(db x,db y){return x>y?x:y;}
db fmin(db x,db y){return x<y?x:y;}

bool isright(point a){return a.x==0?a.y>0:a.x>0;}

db cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}

bool cmp(point a,point b){
	if (isright(a)!=isright(b))return isright(a)>isright(b);
	return cross(origin,a,b)<0;
}

struct halfplane{
	point s,vec;
	halfplane(point a=point(0,0),point b=point(0,0)){s=a;vec=b;}
}hp[N*2],hull[N*2];
point h1[N*2],h2[N*2];
int m1,m2;
int m,k;
struct newpoint{
	db x,y;int id;
	newpoint(const db x_=0,const db y_=0,const int id_=0){x=x_;y=y_;id=id_;}
}L1[N*2],L2[N*2];
int k1,k2;

db cross(newpoint a,newpoint b,newpoint c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}

void add(point a,point b){hp[++m]=halfplane(a,b);}

bool cmp1(newpoint a,newpoint b){return fabs(a.x-b.x)>eps?a.x<b.x:a.y>b.y;}
bool cmp2(newpoint a,newpoint b){return fabs(a.x-b.x)>eps?a.x<b.x:a.y<b.y;}

db ans;

point getsec(db k1,db b1,db k2,db b2){
	db x=(b2-b1)/(k1-k2);
	db y=k1*x+b1;
	return point(x,y);
}

point getsec(point s1,point t1,point s2,point t2){
	db k1=(t1.y-s1.y)/(t1.x-s1.x),k2=(t2.y-s2.y)/(t2.x-s2.x);
	db b1=s1.y-s1.x*k1,b2=s2.y-s2.x*k2;
	if (fabs(k1-k2)<eps){
		if (s1.x>s2.x)return s1;
		return s2;
	}
	return getsec(k1,b1,k2,b2);
}

void gethull(){
	k=0;
	db lef=-MAX-O.x,rig=MAX-O.x;
	db L=-1e9,R=1e9;
	fo(i,1,m)
	if (fabs(hp[i].vec.x)<eps){
		if(hp[i].vec.y>eps)lef=fmax(lef,hp[i].s.x);
		else rig=fmin(rig,hp[i].s.x);
	}
	k1=k2=0;
	fo(i,1,m)
	if (hp[i].vec.x>eps){
		db k=hp[i].vec.y/hp[i].vec.x;
		db b=hp[i].s.y-k*hp[i].s.x;
		L1[++k1]=newpoint(k,-b,i);
	}
	sort(L1+1,L1+1+k1,cmp1);
	int tp=1;
	fo(i,2,k1){
		if (fabs(L1[i].x-L1[i-1].x)<eps)continue;
		newpoint u=L1[i];
		while(tp>1&&cross(L1[tp-1],u,L1[tp])<eps)tp--;
		L1[++tp]=u;
	}
	k1=tp;
	fo(i,1,m)
	if (hp[i].vec.x<-eps){
		db k=hp[i].vec.y/hp[i].vec.x;
		db b=hp[i].s.y-k*hp[i].s.x;
		L2[++k2]=newpoint(k,-b,i);
	}
	sort(L2+1,L2+1+k2,cmp2);
	tp=1;
	fo(i,2,k2){
		if (fabs(L2[i].x-L2[i-1].x)<eps)continue;
		newpoint u=L2[i];
		while(tp>1&&cross(L2[tp-1],L2[tp],u)<eps)tp--;
		L2[++tp]=u;
	}
	k2=tp;
	
	ans=0;
	
	m1=m2=0;
	bool bz=0;
	fd(i,k1,1){
		int x=L1[i].id;
		point u;
		if (i==k1){
			db k=L1[i].x,b=-L1[i].y;
			u.y=k*L+b;
			u.x=L;
		}
		else{
			db k1=L1[i].x,b1=-L1[i].y,k2=L1[i+1].x,b2=-L1[i+1].y;
			u=getsec(k1,b1,k2,b2);
		}
		h1[++m1]=u;
		if (bz)break;
	}
	if (!bz){
		++m1;
		db k=L1[1].x,b=-L1[1].y;
		h1[m1].y=k*R+b;
		h1[m1].x=R;
	}
	
	
	bz=0;	
	fo(i,1,k2){
		int x=L2[i].id;
		point u;
		if (i==1){
			db k=L2[i].x,b=-L2[i].y;
			u.y=k*L+b;
			u.x=L;
		}
		else{
			db k1=L2[i].x,b1=-L2[i].y,k2=L2[i-1].x,b2=-L2[i-1].y;
			u=getsec(k1,b1,k2,b2);
		}
		h2[++m2]=u;
		if (bz)break;
	}
	
	if (!bz){
		++m2;
		db k=L2[k2].x,b=-L2[k2].y;
		h2[m2].y=k*R+b;
		h2[m2].x=R;
	}
	
	int m_=1;
	fo(i,2,m1)
	if (!(fabs(h1[i].x-h1[i-1].x)<1e-6&&fabs(h1[i].y-h1[i-1].y)<1e-6))h1[++m_]=h1[i];
	m1=m_;
	m_=1;
	fo(i,2,m2)
	if (!(fabs(h2[i].x-h2[i-1].x)<1e-6&&fabs(h2[i].y-h2[i-1].y)<1e-6))h2[++m_]=h2[i];
	m2=m_;
	//fo(i,1,m1)printf("A%d=(%.9lf,%.9lf)\n",i,h1[i].x,h1[i].y);
	//fo(i,1,m2)printf("B%d=(%.9lf,%.9lf)\n",i,h2[i].x,h2[i].y);
	
	int he1=1,he2=1;
	if (h2[1].y>h1[1].y){
		while(getsec(h1[he1],h1[he1+1],h2[he2],h2[he2+1]).x>=fmin(h1[he1+1].x,h2[he2+1].x)-eps){
			if (h1[he1+1].x<h2[he2+1].x)he1++;
			else he2++;
		}
		point u=getsec(h1[he1],h1[he1+1],h2[he2],h2[he2+1]);
		h1[he1]=h2[he2]=u;
	}
	int ta1=m1,ta2=m2;
	if (h2[m2].y>h1[m1].y){
		while(getsec(h1[ta1-1],h1[ta1],h2[ta2-1],h2[ta2]).x<=fmax(h1[ta1-1].x,h2[ta2-1].x)+eps){
			if (h1[ta1-1].x>h2[ta2-1].x)ta1--;
			else ta2--;
		}
		point u=getsec(h1[ta1-1],h1[ta1],h2[ta2-1],h2[ta2]);
		h1[ta1]=h2[ta2]=u;
	}
	if (h1[he1].x<lef-eps){
		fo(i,he1,ta1)
		if (h1[i+1].x>lef){
			db k=(h1[i+1].y-h1[i].y)/(h1[i+1].x-h1[i].x);
			h1[i].y=h1[i].y+k*(lef-h1[i].x);
			h1[i].x=lef;
			he1=i;
			break;
		}
		fo(i,he2,ta2)
		if (h2[i+1].x>lef){
			db k=(h2[i+1].y-h2[i].y)/(h2[i+1].x-h2[i].x);
			h2[i].y=h2[i].y+k*(lef-h2[i].x);
			h2[i].x=lef;
			he2=i;
			break;
		}
	}
	if (h1[ta1].x>rig+eps){
		fd(i,ta1,he1)
		if (h1[i-1].x<rig){
			db k=(h1[i].y-h1[i-1].y)/(h1[i].x-h1[i-1].x);
			h1[i].y=h1[i].y+k*(rig-h1[i].x);
			h1[i].x=rig;
			ta1=i;
			break;
		}
		fd(i,ta2,he2)
		if (h2[i-1].x<rig){
			db k=(h2[i].y-h2[i-1].y)/(h2[i].x-h2[i-1].x);
			h2[i].y=h2[i].y+k*(rig-h2[i].x);
			h2[i].x=rig;
			ta2=i;
			break;
		}
	}
	fo(i,he1,ta1-1)ans=ans+cross(origin,h1[i],h1[i+1]);
	fo(i,he2,ta2-1)ans=ans+cross(origin,h2[i+1],h2[i]);
	ans=ans+cross(origin,h2[he2],h1[he1]);
	ans=ans+cross(origin,h1[ta1],h2[ta2]);
//	fo(i,he1,ta1)printf("%.9lf %.9lf\n",h1[i].x+O.x,h1[i].y+O.y);
	//fd(i,ta2,he2)printf("%.9lf %.9lf\n",h2[i].x+O.x,h2[i].y+O.y);
	ans/=2;
}

db solve(){
	n=get();
	n--;
	origin.read();
	O=origin;
	fo(i,1,n){
		a[i].read();
		a[i]=a[i]-origin;
	}
	origin=point(0,0);
	sort(a+1,a+1+n,cmp);
	//printf("%d\n",cmp(a[1],a[2]));
	fo(i,1,n)
	if (fabs(cross(origin,a[i],a[i%n+1]))<eps)return 0;
	m=0;
	fo(i,1,n)
	if (cross(origin,a[i],a[i%n+1])<-eps)add(a[i],a[i%n+1]-a[i]);
	else add(a[i%n+1],a[i]-a[i%n+1]);
	int w=1;
	fo(i,1,n){
		w=max(w,i+1);
		while(cross(origin,a[i],a[(w-1)%n+1])<-eps)w++;
		if((w-1)%n+1!=i){
			if (cross(origin,a[i],a[(w-1)%n+1])<-eps)add(a[i],a[(w-1)%n+1]-a[i]);
			else add(a[(w-1)%n+1],a[i]-a[(w-1)%n+1]);
			if (fabs(cross(origin,a[i],a[(w-1)%n+1]))<eps)return 0;
		}
	}
	add(point(MAX,MAX)-O,point(0,-MAX*2));
	add(point(MAX,-MAX)-O,point(-MAX*2,0));
	add(point(-MAX,-MAX)-O,point(0,MAX*2));
	add(point(-MAX,MAX)-O,point(MAX*2,0));
	gethull();
	ans=fabs(ans);
	return ans;
}

int main(){
	for(int T=get();T;T--)printf("%.9lf\n",solve());
	return 0;
}