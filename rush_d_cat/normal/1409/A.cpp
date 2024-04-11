#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--){
		int x,y; scanf("%d%d",&x,&y);
		if(x==y)printf("0\n");
		else printf("%d\n", (abs(x-y)+9)/10);
	}
}