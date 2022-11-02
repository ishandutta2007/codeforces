#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define M 100100
#define eps 1e-5
struct pnt{
	double x, y;
	pnt(){};
	pnt(double x, double y):x(x), y(y){};
	pnt operator+(pnt a){return pnt(x+a.x, y+a.y);}
	pnt operator-(pnt a){return pnt(x-a.x, y-a.y);}
	pnt operator *(double a) { return pnt(x*a, y*a); }
	pnt operator /(double a) { return pnt(x/a, y/a); }
	double operator ^(pnt a) { return x*a.y-y*a.x; }
	double operator &(pnt a) { return x*a.x+y*a.y; }
}a[M], b[M], O=pnt(0,0), C;
int n, m;

double dist(pnt a, pnt b){return a-b&a-b;}

bool inside(pnt a, pnt b, pnt c) {
	//if pnt a is on the segment between pnt b and pnt c, return 1.
	double A=a-b&c-b;
	double B=c-b&c-b;
	double C=a-b^c-b;
	if (fabs(C)>eps) return 0;
	if (A>-eps && A<B+eps) return 1;
	return 0;
}

int inside_convex_poly(pnt *b, pnt q) {
	int cnt=0;
	for (int i=0; i<m; i++) {
		if (inside(q, b[i], b[i+1])) return 2;
		if ((b[i]-q^b[i+1]-q)>eps) cnt++;
	}
	if (cnt==m || !cnt) return 1;
	return 0;
}


pnt sym(pnt a, pnt b, pnt c) {  //AB   C  
	double tp=(c-a&b-a)/(b-a&b-a);
	pnt p=a*(1-tp)+b*tp;    //AB   C  
	return p;
	return p*2-c;
}

void find_min_dis(pnt q){
	C=pnt(0,0);
	pnt p;
	double dis=1e13;
	for(int i=0; i<m; i++){
		pnt s=b[i], e=b[i+1];
		double a=dist(s,e), b=dist(s,q), c=dist(e,q);
		if(a+b<c){
			if(b<dis){
				dis=b;
				C=s;
			}
		}else if(a+c<b){
			if(c<dis){
				dis=c;
				C=e;
			}
		}else{
			p=sym(s, e, q);
			double v=dist(p, q);
			if(v<dis){
				dis=v;
				C=p;
			}
		}
	}
}

int main(){
	//freopen("1.in", "r", stdin);
	int i;
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)scanf("%lf %lf", &a[i].x, &a[i].y), O=O+a[i];
		O=O/n;
	}
	{
		scanf("%d", &m);
		for(i=0; i<m; i++)scanf("%lf %lf", &b[i].x, &b[i].y);
		b[m]=b[0];
	}

	///printf("O = %.3lf, %.3lf\n", O.x, O.y);

	{
		if(inside_convex_poly(b, O)){
			C=O;
		}else 	find_min_dis(O);
	}
	///printf("C = %.3lf %.3lf\n", C.x, C.y);
	{
		double ans=0;
		for(i=0; i<n; i++){
			ans += dist(C, a[i]);
		}
		printf("%.8lf\n", ans);
	}
	return 0;
}