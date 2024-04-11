#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n,x;
	scanf("%d %d", &n, &x);
	int nums[105];
	for(int i = 0; i < n; i++) scanf("%d", &nums[i]);
	sort(nums, nums+n);
	int index = -1;
	int exist = false;
	bool allsmaller = true;
	for(int i = 0; i < n; i++){
		if(nums[i] == x){
			index = i;
			exist = true;
			allsmaller = false;
			break;
		}
		if(nums[i] > x){
			index = i;
			exist = false;
			allsmaller = false;
			break;
		}
	}
	if(allsmaller){
		printf("%d", x - n);
	}
	else if(!exist){
		printf("%d", x - index);
	}
	else{
		printf("%d", x - index + 1);
	}
}