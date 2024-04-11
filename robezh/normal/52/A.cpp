#include<cstdio>
#include<iostream>
using namespace std;

int num[3];

int main(){
	int n;
	int tmp;
	for(int i = 1; i <= 3; i++) num[i] = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		num[tmp]++;
	}
	cout << n - max(num[1], max(num[2], num[3])) << endl;
}