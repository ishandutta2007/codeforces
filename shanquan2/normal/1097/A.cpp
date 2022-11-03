#include<bits/stdc++.h>
using namespace std;

char b[5],a[5];
int main(){
	scanf("%s",b);
	for(int i=0;i<5;i++){
		scanf("%s",a);
		if(a[0]==b[0]||a[1]==b[1]){printf("YES\n");return 0;}
	}
	printf("NO\n");
	return 0;
}