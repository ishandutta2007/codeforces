#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int high = 6E6, low = 0, mid;
	while (low < high){
		mid = low + high >> 1;
		int a = mid / 2, b = mid / 3, c = mid / 6;
		a -= c, b -= c;
		if (n - min(n, a) + m - min(m, b) <= c)
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d\n", low);
	return 0;
}