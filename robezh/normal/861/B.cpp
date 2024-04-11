#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int numoff;
	int n;
	int upper = 10000;
	int lower = -10000;
	int a,b;
	scanf("%d %d", &numoff, &n);
	if(numoff == 1){
		printf("1");
		return 0;
	}
	if(n == 0){
		printf("-1");
		return 0;
	}
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		if(b == 1) lower = max(lower, a);
		else{
			lower = max(lower, int(ceil((double)a / b)));
			upper = min(upper, int(floor((double)a / (b - 1) - 0.00001)));
		}
		//printf("upper = %d, lower = %d\n", upper, lower);
	}
	int ans = (numoff - 1) / lower + 1;
	bool good = true;
	for(int i = lower + 1; i <= upper; i++){
		if(ans != (numoff - 1) / i + 1){
			good = false;
			break;
		}
	}
	
	if(good){
		printf("%d", (numoff - 1) / lower + 1);
	}
	else{
		printf("-1");
	}
}