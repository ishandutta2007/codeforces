#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	int minP = 100000000;
	scanf("%d", &n);
	int upper_bound = (int)sqrt(n-1) + 1;
	upper_bound *= upper_bound;
	for(int i = n; i <= upper_bound; i++){
		int divider = (int)sqrt(i);
		while(i % divider != 0){
			divider --;
		}
		minP = min(minP, 2 * (divider + i / divider));
	}
	printf("%d", minP);
}