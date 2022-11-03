#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E6 + 10, MAXM = 1E6, RANGE = 1E3;

struct VEC{
	int x, y, id;

	bool operator<(const VEC &r)const{
		return x != r.x ? x < r.x : y < r.y;
	}
}a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i + 1;
	}
	sort(a, a + n);
	for (int j, i = 0, r = RANGE; r <= MAXM; r += RANGE){
		for (j = i; j < n && a[j].x <= r; ++j)
			swap(a[j].x, a[j].y);
		sort(a + i, a + j);
		if (r / RANGE & 1)
			reverse(a + i, a + j);
		i = j;
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", a[i].id, i < n - 1 ? ' ' : '\n');
	return 0;
}