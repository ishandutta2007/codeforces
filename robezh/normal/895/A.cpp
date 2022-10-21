#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int abs(int x){
	return x >= 0 ? x : -x;
}

int n;
int ang[400];

int minDiff(int k){
	int res = 400000;
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += ang[(k+i)%n];
		res = min(res, abs(ans-180));
	}
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ang[i]);
	}
	int res = 40000;
	for(int i = 0; i < n; i++){
		res = min(2 * minDiff(i), res);
	}
	
	cout << res;
}