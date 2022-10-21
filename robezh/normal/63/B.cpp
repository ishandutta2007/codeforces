#include<cstdio>
#include<iostream>
using namespace std;

int n,k;
int num[105];

bool check(){
	for(int i = 0; i < n; i++){
		if(num[i] != k) return false;
	}
	return true;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]);
	int cnt = 0;
	while(!check()){
		for(int i = 0; i < n; i++){
			if((i == n-1 || num[i] != num[i+1]) && num[i] < k){
				num[i] ++;
			}
		}
		cnt ++;
		//cout << cnt;
	}
	cout << cnt;
}