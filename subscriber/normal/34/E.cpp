#include <iostream>
#include <algorithm>

using namespace std;

struct T{double x; long double v,m;int id;} q[1000];

bool m1(T A,T B){
	return A.x<B.x;
}

bool m2(T A,T B){
	return A.id<B.id;
}

long double t,tt,o,v1,v2;
int n;

long double wh(){
	double r=1000000000;
	for (int i=1;i<n;i++){
		if (q[i-1].v-q[i].v<=0)continue;
		double e=(q[i].x-q[i-1].x)/(q[i-1].v-q[i].v);
		if (e>=0)r=min(r,e);
	}
	return r;
}

int main(){
	cin >> n >> t;
	for (int i=0;i<n;i++)cin >> q[i].x >> q[i].v >> q[i].m;
	for (int i=0;i<n;i++)q[i].id=i;
	sort(q,q+n,&m1);
	tt=0;
	while(tt+1e-9<t){
		o=wh();
		if (o+tt<=t){
			for (int i=0;i<n;i++)q[i].x+=q[i].v*o;
			for (int i=1;i<n;i++)if (q[i].x-q[i-1].x<1e-8){
				v1=((q[i-1].m-q[i].m)*q[i-1].v+2*q[i].m*q[i].v)/(q[i-1].m+q[i].m);
				v2=((q[i].m-q[i-1].m)*q[i].v+2*q[i-1].m*q[i-1].v)/(q[i-1].m+q[i].m);
				q[i-1].v=v1;
				q[i].v=v2;
			}
		}else for (int i=0;i<n;i++)q[i].x+=q[i].v*(t-tt);
		tt+=o;
	}
	sort(q,q+n,&m2);
	cout.precision(7);
	for (int i=0;i<n;i++)cout << fixed << q[i].x << endl;
	return 0;
}