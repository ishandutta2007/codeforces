#include<cstdio>
#include<iostream>
using namespace std;

const int INF = 1000000000;

int n;
int num[1000050];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]);
	int killed = 0;
	int power = 0;
	for(int i = n-1; i >= 0; i--){
		if(power > 0) killed ++;
		power --;
		power = max(power, num[i]);
	}
	
	cout << n - killed;
}