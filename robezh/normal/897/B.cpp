#include<cstdio>
#include<iostream>
using namespace std;

int k,p;

long long get_res(int a){
	int tmp = a;
	int cnt = 0;
	while(tmp > 0){cnt++; tmp /= 10;}
	long long res = a; tmp = a;
	while(tmp > 0){
		res *= 10;
		res += tmp%10;
		tmp /= 10;
	}
	return res;
}

int main(){
	scanf("%d%d", &k, &p);
	long long res = 0;
	for(int i = 1; i <= k; i++){
		res += get_res(i);
		res %= p;
	}
	cout << res;
}