#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	int a, b, k;
	cin >> a >> b >> k;

	if (a == 0) {
		if (k == 0) {
			printf("Yes\n");
			for (int i = 1; i <= a + b; i ++) printf("1"); printf("\n");
			for (int i = 1; i <= a + b; i ++) printf("1"); printf("\n");
		} else {
			printf("No\n");
		}
		return 0;
	}	
	if (b == 1) {
		if (k == 0) {
			printf("Yes\n");
			for (int i = 1; i <= b; i ++) printf("1");
			for (int i = 1; i <= a; i ++) printf("0");
			printf("\n");

			for (int i = 1; i <= b; i ++) printf("1");
			for (int i = 1; i <= a; i ++) printf("0");
			printf("\n");
		} else {
			printf("No\n");
		}
		return 0;
	}
	if (k >= a + b - 1) {
		return !printf("No\n");
	}

	printf("Yes\n");
	for (int i = 1; i <= b; i ++) printf("1");
	for (int i = 1; i <= a; i ++) printf("0");
	printf("\n");
		
	if (k == 0) {
		for (int i = 1; i <= b; i ++) printf("1");
		for (int i = 1; i <= a; i ++) printf("0");
		printf("\n");
		return 0;
	}


	b --;
	vector<int> nums(a+b+1,0);
	if (k >= b) {
		int dt = k - b;
		int pos = b + dt + 1;
		nums[pos] = 1;
		for (int i = b; i >= 2; i --) nums[i] = 1;
		printf("1"); for (int i = 1; i <= a + b; i ++) printf("%d", nums[i]);
		printf("\n");
	} else {
		for (int i = 1; i <= b - k; i ++) nums[i] = 1;
		for (int i = 1, pos = b + 1; i <= k; i ++) {
			nums[pos --] = 1;
		}
		printf("1"); for (int i = 1; i <= a + b; i ++) printf("%d", nums[i]);
		printf("\n");		
	}
}