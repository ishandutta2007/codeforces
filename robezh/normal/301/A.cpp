#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int n;
int num[205];
int sum = 0;

int main(){
	scanf("%d", &n);
	int posCnt = 0;
	int lar = 10000000;
	for(int i = 0; i < 2 * n - 1; i++){
		scanf("%d", &num[i]);
		if(num[i] > 0) posCnt++, sum += num[i], lar = min(lar, num[i]);
		else sum += -num[i], lar = min(lar, -num[i]);
	}
	int res = 0;
	if(posCnt % 2 == 0 && n % 2 == 0) res = sum - 2 * lar;
	else res = sum;
	cout << res;
}