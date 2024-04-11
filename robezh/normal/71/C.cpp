#include<cstdio>
#include<iostream>
using namespace std;

int n;
int num[100050];

bool check(int k){
	for(int s = 0; s < k ; s++){
		bool flag = true;
		for(int i = s; i < n; i += k){
			if(num[i] == 0){
				flag = false;
				break;
			}
		}
		if(flag){
			//printf("s,k = %d, %d\n",s,k);
			 return true;
		}
	}
	return false;
}

int main(){
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]);
	for(int i = 1; i <= n; i++){
		if(n % i == 0 && n / i >= 3 && check(i)){
			return !printf("YES");
		}
	}
	return !printf("NO");
}