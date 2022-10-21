#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int slices[55];
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d", &slices[i]);
	}
	int a = 0, b = 0;
	for(int i = n - 1; i >= 0; i--){
		if(a >= b){
			b += slices[i];
		}
		else{
			a +=slices[i];
		}
	}
	printf("%d %d",min(a,b), max(a,b));
	
	return 0;
	
}