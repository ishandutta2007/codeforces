#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,T,flag;
double a;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lf",&a);
		if(a*a/4<a){puts("N");continue;}
		double l=0.5*a,r=a;
		for(int i=1;i<=50;++i){
			double mid=0.5*(l+r);
			if(mid*(a-mid)<a) r=mid;
				else l=mid;
		}
		printf("Y %.10lf %.10lf\n",l,a-l);
	}
	return 0;
}