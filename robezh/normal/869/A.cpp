#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

map<int,int> M;

int main(){
	int n;
	int a[2005];
	int b[2005];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		M[a[i]] = 1;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
		M[b[i]] = 1;
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(M.count(a[i] ^ b[j])){
				count++;
			}
		}
	}
	if(count%2) printf("Koyomi");
	else printf("Karen");
}