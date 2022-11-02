#include <bits/stdc++.h>
using namespace std;
#define N 100005

char a[N];

int main(){
	int i, j, len;
	scanf("%s", a);
	len = strlen(a) - 1;
	for(i = 0; i < len; i++){
		if(a[i] == '0') break;
		else printf("1");
	}
	if(i < len) printf("%s", a + i + 1);
}