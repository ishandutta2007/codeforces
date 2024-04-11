#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n, i, a[1111], tot=0;
	
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		scanf("%d", a+i); 
		if (a[i]==0) tot++;
	}
	
	if (n==1) {
		if (a[0]) puts("YES");
		else puts("NO");
	} else {
		if (tot==1) puts("YES");
		else puts("NO");
	}
	
	return 0; 
}