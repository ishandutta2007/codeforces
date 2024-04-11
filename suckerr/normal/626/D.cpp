#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 2e3 + 7;
const int SIZE = 5e3 + 7;

int n, ball[N];
int diff[SIZE], sum[SIZE];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ball[i]);
	}

	sort(ball, ball + n);

	double answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			diff[ball[j] - ball[i]]++;
		}
	}

	int span = ball[n - 1] - ball[0];
	for (int i = span; i >= 0; i--) {
		sum[i] = diff[i] + sum[i + 1];
	}

	for (int a = 1; a <= span; a++) {
		for (int b = 1; a + b < span; b++) {
			answer += 1. * diff[a] * diff[b] * sum[a + b + 1];
		}
	}

	double cn2 = n * (n - 1) / 2;
	printf("%.10f\n", answer / cn2 / cn2 / cn2);
	return 0;
}