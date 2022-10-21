#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,k,x;
	int num[105];
	scanf("%d%d%d",&n,&k,&x);
	for(int i = 0; i < n; i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int sum = 0;
	for(int i = 0; i < n-k; i++){
		sum += num[i];
	}
	sum += k * x;
	printf("%d",sum);
}