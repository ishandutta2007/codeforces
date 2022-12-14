#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int B, K;
int A;
int cnt = 0;

int main(){
	scanf("%d%d", &B, &K);
	for(int i=0; i<K; i++){
		scanf("%d", &A);
		if(A%2==1 && B%2==1)	cnt++;
		else if(i==K-1 && A%2==1)	cnt++;
	}
	if(cnt%2==0){
		printf("even");
	}else{
		printf("odd");
	}
	return 0;
}