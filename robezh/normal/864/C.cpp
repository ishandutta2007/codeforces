#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int a,b,f,k;
	scanf("%d%d%d%d", &a, &b, &f, &k);
	if((k >= 3) && (b < f || b < max(2*f, 2*(a-f)))){
		printf("-1");
		return 0;
	}
	else if(k == 1 && (b < f || b < a - f)){
		printf("-1");
		return 0;
	}
	else if(k == 2 && (b < f || b < 2 * (a - f))){
		printf("-1");
		return 0;
	}
	int gas = b;
	int gascnt = 0;
	for(int round = 0; round < k; round++){
		//printf("round %d : gas = %d, gascnt = %d\n", round, gas, gascnt);
		if(round == k - 1){
			if(gas < a) gascnt++;
		}
		else if(round % 2 == 0){
			if(gas < 2 * a - f){
				gascnt++;
				gas = b - a + f;
			}
			else{
				gas -= a;
			}
		}
		else{
			if(gas < a + f){
				gascnt++;
				gas = b - f;
			}
			else{
				gas -= a;
			}
		}
	}
	printf("%d", gascnt);
}