#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	if (a < b)
		puts("-1");
	else
		printf("%.16lf\n", (a + b) / 2.0 / ((a + b) / (2 * b)));
	return 0;
}