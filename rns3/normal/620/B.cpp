#include <bits/stdc++.h>
using namespace std;
#define M 100100
int ABS(int u) {return u < 0 ? -u : u;}

int a, b;
int answer;
int x[M], y[M];
//int c[M] = {4, 5, 2, 3, 3, 2, 5, 4, 1, 2};
int c[M] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int calc(int a) {
	int s = 0;
	while (a) {
		s += c[a%10];
		a /= 10;
	}
	return s;
}

int main() {
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
        answer += calc(i);
	}
	printf("%d\n", answer);
	return 0;
}