#include<bits/stdc++.h>

using namespace std;

double pw(double a, int b){
	double ret = 1;
	while(b){
		if(b&1)ret*=a;
		a*=a;
		b>>=1;
	}
	return ret;
}

int main(){
	double a, b; cin >> a >> b;
	double st = 1.0/a;
	double ans = 0;
	double ls = 0;
	for(int i = 1; i <= a; ++i){
		double x = pw(st*i,b);
		ans+=i*(x-ls);
		ls = x;
	}
	printf("%.6f\n", ans);
}