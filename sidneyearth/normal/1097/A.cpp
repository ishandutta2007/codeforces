#include <bits/stdc++.h>
using namespace std;
int main(){
	char a, b, c, d;
	scanf(" %c%c", &a, &b);
	for(int i = 0; i < 5; i++){
		scanf(" %c%c", &c, &d);
		if(a == c || b == d){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}