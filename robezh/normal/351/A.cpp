#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int n,n2;
double num[4005];

int main(){
	double upsum = 0, sum = 0;
	int cnt0 = 0;
	scanf("%d", &n);
	n2 = 2 * n;
	for(int i = 0; i < n2; i++){
		scanf("%lf", &num[i]);
		num[i] -= (int)num[i];
		sum += num[i];
		upsum += ceil(num[i]);
		if(num[i] == 0) cnt0 ++;
	}
	//for(int i = 0; i < n2; i++) printf("%.3f ", num[i]);
	double ans = 1000000000000;
	for(int i = n - cnt0; i <= n; i++){
		ans = min(ans, abs(upsum - i - sum));
	}
	printf("%.3lf", ans);
	
}