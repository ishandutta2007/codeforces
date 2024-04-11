#include<cstdio>
#include<iostream>
using namespace std;

const double EPS = 1e-11/2;

int n;
double num[200020];

double get_posi(double k){
	double res = -100000;
	double sum = 0;
	for(int i = 0; i < n; i++){
		sum += (num[i]-k);
		res = max(sum, res);
		if(sum < 0) sum = 0;
	}
	return res;
}

double get_neg(double k){
	double res = 100000;
	double sum = 0;
	for(int i = 0; i < n; i++){
		sum += (num[i]-k);
		res = min(sum, res);
		if(sum > 0) sum = 0;
	}
	return res;
}

double binary_search(){
	double l = -10000, r = 10000;
	while(r - l > EPS){
		double mid = (l + r) / 2;
		if(get_posi(mid) + get_neg(mid) < 0){
			r = mid;
		}else{
			l = mid;
		}
	}
	return get_posi(l);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf", &num[i]);
	}
	printf("%.8lf", binary_search());
}