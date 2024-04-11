#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100100;

int main() {
	int N;
	cin >> N;
	double e = 1;
	double sum = 0;
	for(int i = 0; i < N; ++i) {
		double p;
		cin >> p;
		sum += e * p;
		e = 1 + (e + 1) * p;
	}
	printf("%.11f\n", sum);
}