#include<cstdio>
#include<iostream>
using namespace std;

double getres(double a, double b){
	while(a - b >= 0){
		a -= b;
	}
	return a;
}

int main(){
	double a1,a2,a3;
	double b1,b2;
	int h,m,s;
	int t1,t2;
	double dif = 0;
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	dif = min(t1,t2);
	b1 = 0; b2 = max(t1,t2) - dif;
	a1 = getres(((double)s / 5 - dif + 12), 12);
	a2 = getres(((double)m / 5 + 0.1 - dif + 12), 12);
	a3 = getres((h + 0.5 - dif + 12), 12);
	//printf("%lf %lf %lf %lf %lf", a1,a2,a3,b1,b2);
	if(a1 <= b2 && a2 <= b2 && a3 <= b2 || a1 >= b2 && a2 >= b2 && a3 >= b2) printf("YES");
	else printf("NO");
}