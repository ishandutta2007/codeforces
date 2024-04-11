#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1001;

int n, a[N], id[N], u[N * N], v[N * N], m;

bool cmp(int x, int y){
	return a[x] != a[y] ? a[x] < a[y] : x < y;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i), id[i] = i;
	sort(id + 1, id + 1 + n, cmp);
	for(int i = 1; i <= n; i++)
		a[id[i]] = i;
	for(int i = n; i > 1; i--){
		for(int j = a[i] + 1; j <= i; j++){
			++m;
			u[m] = id[j], v[m] = i;
			a[id[j]]--, id[j - 1] = id[j];
		}
	}
	printf("%d", m);
	for(int i = 1; i <= m; i++)
		printf("\n%d %d", u[i], v[i]);
	return 0;
}