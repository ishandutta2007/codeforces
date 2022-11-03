#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int v1, v2;
	int d, t;
	scanf("%d%d", &v1, &v2);
	scanf("%d%d", &t, &d);
	int s = v1 + v2;
	t -= 2;
	while (t--){
		if (v1 > v2)
			swap(v1, v2);
		s += v1 += d;
	}
	printf("%d\n", s);
	return 0;
}