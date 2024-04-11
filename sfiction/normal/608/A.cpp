#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E2 + 10, MAXS = 1E3 + 10;

int a[MAXS];

int main(){
	int n, S;
	scanf("%d%d", &n, &S);
	for (int f, t, i = 0; i < n; ++i){
		scanf("%d%d", &f, &t);
		a[f] = max(a[f], t);
	}
	a[S + 1] = -1;
	for (int i = S; i >= 0; --i)
		a[i] = max(a[i], a[i + 1] + 1);
	printf("%d\n", a[0]);
	return 0;
}