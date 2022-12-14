#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (!m)
		printf("%d\n", 1);
	else
		printf("%d\n", min(m, n - m));
	return 0; 
}