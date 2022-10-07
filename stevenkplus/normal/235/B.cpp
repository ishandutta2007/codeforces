#include <cstdio>

using namespace std;

int N;
int main() {
	scanf("%d", &N);
	double bonus = 0;
	double sum = 0;
	for(int i = 0; i < N; ++i) {
		double next;
		scanf("%lf", &next);
		sum += next * (1 + bonus);
		bonus = (bonus + 2) * next;
	}
	printf("%.10f\n", sum);
	return 0;
}