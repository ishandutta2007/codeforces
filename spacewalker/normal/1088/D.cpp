#include <bits/stdc++.h>

using namespace std;

int query(int c, int d) {
	printf("? %d %d\n", c, d);
	fflush(stdout);
	int res; scanf("%d", &res);
	if (res == -2) exit(0);
	return res;
	/*
	int x = 3 ^ c, y = 1 ^ d;
	if (x > y) return 1;
	else if (x == y) return 0;
	else if (x < y) return -1;
	else return -2;
	*/
}

int main() {
	int a = 0, b = 0;
	int kIndex = 30;
	while (kIndex > 0) {
		int fquery = query(a, b);
		for (int i = kIndex - 1; i >= -1; --i) {
			int squery = (i >= 0 ? query(a ^ (1 << i), b ^ (1 << i)) : 0);
			if (squery != fquery || i == -1) { 
				/* 
				the two numbers differ at bit i
				assign the value at bit i
				then check the values at bits kIndex - 1 ... i + 1
				*/
				if (i >= 0) { // assign the value at bit i
					(fquery == 1 ? a : b) ^= (1 << i);
				}
				// check values in between
				for (int x = kIndex - 1; x > i; --x) {
					int equery = query(a ^ (1 << x), b);
					int val = (equery == 1 ? 0 : (1 << x));
					a ^= val; b ^= val;
				}
				// move to the next block of bits
				kIndex = i;
				break;
			}
		}
	}
	printf("! %d %d\n", a, b);
	fflush(stdout);
}