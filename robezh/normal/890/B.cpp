#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int num[200500];
map<int, int> M;

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	int tmp = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	for(int i = n-1; i >= 0; i--){
		if(!M.count(num[i])){
			ans = num[i];
			M[num[i]] = 1;
		}
	}
	printf("%d",ans);
}