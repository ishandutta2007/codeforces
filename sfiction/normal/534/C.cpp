#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int n;
ll A, s;
int a[MAXN];

int main(){
	scanf("%d%I64d", &n, &A);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		s += a[i];
	}

	for (int i = 0; i < n; ++i){
		int l = max(1ll, A - (s - a[i]));
		int r = min((ll)a[i], A - (n - 1));
		printf("%d%c", max(0, a[i] - (r - l + 1)), "\n "[i + 1 < n]);
	}
	return 0;
}