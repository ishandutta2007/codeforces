#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int time[105];

int main(){
	int n,t;
	int ans = -1;
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n; i++){
		scanf("%d",&time[i]);
	}
	for(int i = 0; i < n; i++){
		t -= (86400 - time[i]);
		if(t <= 0){
			ans = i+1;
			break;
		}
	}
	//if(t == 0) ans ++;
	printf("%d", ans);
}