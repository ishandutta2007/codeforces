#include<cstdio>
#include<iostream>
using namespace std;

int n,m;
int rem[1005][1005];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n-2; i++){
		for(int j = 1; j <= n-2; j++){
			rem[i][j] = 9;
		}
	}
	int om = m;
	while(m--){
		int a,b;
		scanf("%d%d", &a, &b);
		for(int i = a; i >= max(1,a-2); i--){
			for(int j = b; j >= max(1,b-2); j--){
				rem[i][j] --;
				if(rem[i][j] == 0) return !printf("%d", om - m);
			}
		}
	}
	return !printf("-1");
}