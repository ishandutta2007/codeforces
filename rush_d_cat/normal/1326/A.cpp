#include <bits/stdc++.h>
using namespace std;
//558
int T,n;
int main() {
	scanf("%d",&T);
	while(T --) {
		scanf("%d",&n);
		if(n==1) {
			printf("-1\n");
		} else {
			for(int i=1;i<n;i++)printf("5");
			printf("8\n");
		}
	}
}