#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;
	int tmp;
	int nums[105];
	int a=0 ,b=0;
	bool fair = true;
	scanf("%d",&n);
	for(int i = 0; i < 105; i++){
		nums[i] = 0;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		nums[tmp] ++;
	}
	for(int i = 0; i < 105; i++){
		if(nums[i] != 0){
			//printf("nums[%d] != 0\n", i);
			if(a == 0) a = i;
			else if(b == 0) b = i;
			else fair = false;
		}
	}
	if(nums[a] != nums[b]) fair = false;
	if(fair) printf("YES\n%d %d",a,b);
	else printf("NO");
	
	
}