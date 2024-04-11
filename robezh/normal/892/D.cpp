#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n;
int num[23];
int sted[23];
map<int, int> M;


int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
		sted[i] = num[i];
	}
	sort(sted, sted + n);
	for(int i = 1; i <= n; i++){
		M[sted[i % n]] = sted[i-1];
	}
	for(int i = 0; i < n; i++){
		printf("%d ", M[num[i]]);
	}
}