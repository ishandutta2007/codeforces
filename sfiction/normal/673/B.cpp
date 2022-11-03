#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int l = 1, r = n;
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		if (u > v)
			swap(u, v);
		l = max(l, u);
		r = min(r, v);
	}
	printf("%d\n", max(0, r - l));
	return 0;
}