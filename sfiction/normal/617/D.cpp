#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int solve(int x[], int y[]){
	if (x[0] == x[1] && x[1] == x[2])
		return 1;
	else if (x[0] == x[1] && (y[0] - y[2]) * (long long)(y[1] - y[2]) >= 0
			|| x[1] == x[2] && (y[1] - y[0]) * (long long)(y[2] - y[0]) >= 0
			|| x[2] == x[0] && (y[2] - y[1]) * (long long)(y[0] - y[1]) >= 0)
		return 2;
	else
		return 3;
}

int main(){
	int x[3], y[3];
	for (int i = 0; i < 3; ++i)
		scanf("%d%d", &x[i], &y[i]);
	printf("%d\n", min(solve(x, y), solve(y, x)));
	return 0;
}