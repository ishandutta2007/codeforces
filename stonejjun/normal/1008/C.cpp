#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;

int main() {
	int n, k,i, j,cnt=0;
	scanf("%d", &k);

	int stack[100000];
	for (i = 0; i < k; i++) {
		scanf("%d", &stack[i]);
	}

	sort(stack, stack + k);

	int copying[100000];
	for (i = 0; i < k; i++) {
		copying[i] = stack[i];
	}

	int changer = 0;
	int temp = 1;

	for (i = 0; i < k-1; i++) {
		if (stack[i] == stack[i + 1]) {
			temp++;
		}
		else {
			if (temp > changer) changer = temp;
			temp = 1;
		}
	}


	for (i = 0; i < k; i++) {
		int rotnum = i - changer >= 0 ? i - changer : k + i - changer;
		stack[rotnum] = copying[i];
	}

	for (i = 0; i < k; i++) {
		if (stack[i] > copying[i]) {
			cnt++;
		}
	}

	printf("%d\n", cnt);
}