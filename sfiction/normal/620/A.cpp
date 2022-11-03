#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", max(abs(a - c), abs(b - d)));
	return 0;
}