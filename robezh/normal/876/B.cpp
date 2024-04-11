#include<cstdio>
#include<iostream>
using namespace std;

int num[100005];
int cnt[100005];
int remainder;


int main(){
	int n,k,m;
	bool good = false;
	scanf("%d%d%d", &n,&k,&m);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		cnt[num[i] % m] ++;
		if(cnt[num[i]%m] >= k){
			remainder = num[i] % m;
			good = true;
		}
	}
	if(!good) printf("No");
	else{
		printf("Yes\n");
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(cnt == k) break;
			if(num[i] % m == remainder){
				cnt++;
				printf("%d ", num[i]);
			}
		}
	}
	
	
}