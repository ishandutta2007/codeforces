#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int num[100005];

int main(){
	int n;
	int k;
	scanf("%d%d", &n,&k);
	int sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		sum += num[i];
	}
	if(sum + n - 1 == k) printf("YES");
	else printf("NO");
}