#include <bits/stdc++.h>
using namespace std;

int a, b[10], c, d, e;

int main(){
	for(int i = 0; i < 6; i++){
		scanf("%d", &a);
		b[a] ++;
	}
	for(int i = 1; i <= 9; i++){
		if(b[i] == 6){
			puts("Elephant");
			return 0;
		}
		else if(b[i] == 5){
			puts("Bear");
			return 0;
		}
		else if(0 < b[i] && b[i] <= 3){
			c++;
		}
		else if(b[i] == 4)  e = i;
	}
	if(!e){
		puts("Alien");
		return 0;
	}
	if(c == 1) puts("Elephant");
	else if(c == 2) puts("Bear");
}