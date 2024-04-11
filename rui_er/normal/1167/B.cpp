//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int a[7] = {-1, 4, 8, 15, 16, 23, 42}, multiple[5];

int main() {
	for(int i=1;i<=4;i++) {
		printf("? %d %d\n", i, i+1);
		fflush(stdout);
		scanf("%d", &multiple[i]);
	}
	do {
		bool _ = true;
		for(int i=1;i<=4;i++) {
			if(a[i] * a[i+1] != multiple[i]) {
				_ = false;
				break;
			}
		}
		if(_) {
			printf("! ");
			for(int i=1;i<=6;i++) printf("%d ", a[i]);
			puts("");
			break;
		}
	}while(next_permutation(a+1, a+7));
	return 0;
}