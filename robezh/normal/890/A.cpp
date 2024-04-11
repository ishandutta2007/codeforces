#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int num[10];
int sum = 0;

bool good(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(i != j){
				for(int k = 0; k < 6; k++){
					if(k != i && k != j){
						if(2 * (num[i] + num[j] + num[k]) == sum){
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int main(){
	
	for(int i = 0; i < 6; i++) scanf("%d", &num[i]);
	for(int i = 0; i < 6; i++) sum += num[i];
	if(good()) printf("YES");
	else printf("NO");
}