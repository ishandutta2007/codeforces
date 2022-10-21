#include<cstdio>
#include<iostream>
using namespace std;

int n;
int nums[105];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d", &nums[i]);
	}
	if(n%2 && nums[0] %2 && nums[n-1] % 2) printf("Yes");
	else printf("No");
	
	return 0;
}