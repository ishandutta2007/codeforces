#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a = min(a, b + c);
	b = min(b, a + c);
	c = min(c, a + b);
	printf("%d\n", a + c + b);
	return 0;
}