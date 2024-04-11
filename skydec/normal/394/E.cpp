#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
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
typedef long double db;
#define eps 1e-7
#define MAXN 110000
struct po{
	db x,y;
	inline po(db a=0,db b=0){x=a;y=b;}
}a[MAXN];
struct func{
	db a,b,c;
	inline func(po u=po(0,0),po v=po(0,0)){
		db x1,y1,x2,y2;x1=u.x;y1=u.y;x2=v.x;y2=v.y;
		b=-(x1-x2);a=y1-y2;c=-(a*x1+b*y1);
	}
	inline bool cross(func v,po &res){
		db d,e,f;d=v.a;e=v.b;f=v.c;
		if(fabs(b*d-a*e)<eps)exit(0);
		res.y=(a*f-c*d)/(b*d-a*e);
		res.x=(b*f-c*e)/(a*e-b*d);
		return 1;
	}
	inline db y(db x){if(fabs(b)<eps)exit(0);return (-c-a*x)/b;}
	inline db x(db y){if(fabs(a)<eps)exit(0);return (-c-b*y)/a;}
}b[MAXN][3];
int tmp[MAXN];int n,m;
int zb[MAXN];
db B,C,D;db ANS=1e17;
inline void Min(db &x,db y){if(y<x)x=y;}
inline db f(db a,db bb,db c,db x){
	return a*x*x+bb*x+c;
}
inline db Ask(db a,db b,db c,db l,db r){
	// ask Min{f(x)=ax^2+bx+c}   x[l,r] 
	db dcz=(-b)/(2.*a);
	if(dcz<=r&&dcz>=l)return f(a,b,c,dcz);
	db R=f(a,b,c,l);
	Min(R,f(a,b,c,r));
	return R;
}
inline db belong(db l,db r,func fx){
	// that y is on f(x),Min{x^2+y^2+Bx+Cy+D}   x[l,r] 
	if(fabs(fx.b)<eps)exit(0);
	db V=-fx.a/fx.b;db W=-fx.c/fx.b;
	return Ask(V*V+1,2*V*W+B+C*V,D+W*W+C*W,l,r);
}
inline db pq(db l,db r,db papa){
	// that y=papa, Min{x^2+y^2+Bx+Cy+D}  x[l,r] 
	return Ask(1,B,papa*papa+papa*C+D,l,r);
}
int main(){
	scanf("%d",&m);
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		D+=x*1.*x+y*1.*y;C-=2.*y;B-=2.*x;
	}
	scanf("%d",&n);
	rep(i,1,n){int x,y;scanf("%d%d",&x,&y);a[i]=po(x,y);tmp[i]=x;}
	sort(tmp+1,tmp+1+n);
	int N=unique(tmp+1,tmp+1+n)-tmp-1;
	rep(i,1,n){
		a[i].x=lower_bound(tmp+1,tmp+1+N,(int)(a[i].x))-tmp;
	}
	rep(i,1,n){
		func uccu=func(po(tmp[(int)a[i].x],a[i].y),po(tmp[(int)a[i%n+1].x],a[i%n+1].y));
		int px,qx;px=(int)(a[i].x);qx=(int)(a[i%n+1].x);
		if(px>qx)swap(px,qx);
		rep(j,px,qx-1)b[j][++zb[j]]=uccu;
	}
	B/=m;C/=m;D/=m;func uccu=func(po(1,-C/2.),po(2,-C/2.));db papa=-C/2.;
	rep(i,1,N-1){
		db l=tmp[i];db r=tmp[i+1];
		if(b[i][1].y(l)>=b[i][2].y(l)&&b[i][1].y(r)>=b[i][2].y(r))swap(b[i][1],b[i][2]);
		po lu,ru,ld,rd;
		func L=func(po(l,1),po(l,2));
		func R=func(po(r,1),po(r,2));
		L.cross(b[i][2],lu);
		L.cross(b[i][1],ld);
		R.cross(b[i][2],ru);
		R.cross(b[i][1],rd);
		if(papa>=lu.y&&papa>=ru.y){
			//(1)
			Min(ANS,belong(l,r,b[i][2]));
		}
		else
		if(papa<=ld.y&&papa<=rd.y){
			//(2)
			Min(ANS,belong(l,r,b[i][1]));
		}
		else
		if(papa<=lu.y&&papa>=ld.y&&papa<=ru.y&&papa>=rd.y){
			//(3) 
			Min(ANS,pq(l,r,papa));
		}
		else
		if(papa>=ld.y&&papa>=rd.y){
			//(4)
			po jb;jb.y=papa;jb.x=b[i][2].x(jb.y);
			if(lu.y<=ru.y){
				Min(ANS,belong(l,jb.x,b[i][2]));
				Min(ANS,pq(jb.x,r,papa));
			}
			else{
				Min(ANS,belong(jb.x,r,b[i][2]));
				Min(ANS,pq(l,jb.x,papa));
			}
		}
		else
		if(papa<=lu.y&&papa<=ru.y){
			//(5)
			po jb;jb.y=papa;jb.x=b[i][1].x(jb.y);
			if(ld.y>=rd.y){
				Min(ANS,belong(l,jb.x,b[i][1]));
				Min(ANS,pq(jb.x,r,papa));
			}
			else{
				Min(ANS,belong(jb.x,r,b[i][1]));
				Min(ANS,pq(l,jb.x,papa));
			}
		}
		else{
			//(6) 
			po jub,jdb;jub.y=jdb.y=papa;
			jub.x=b[i][2].x(papa);
			jdb.x=b[i][1].x(papa);
			if(lu.y<=ru.y){
				Min(ANS,belong(l,jub.x,b[i][2]));
				Min(ANS,pq(jub.x,jdb.x,papa));
				Min(ANS,belong(jdb.x,r,b[i][1]));
			}
			else{
				Min(ANS,belong(l,jdb.x,b[i][1]));
				Min(ANS,pq(jdb.x,jub.x,papa));
				Min(ANS,belong(jub.x,r,b[i][2]));
			}
		}
	}
	printf("%.5lf\n",(double)ANS*m);
	return 0;
}