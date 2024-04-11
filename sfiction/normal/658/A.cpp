#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50 + 5;

int a[MAXN], t[MAXN];

int main(){
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &t[i]);

	int s1 = 0, s2 = 0;
	int tot1 = 0, tot2 = 0;
	for (int i = 0; i < n; ++i){
		s1 += t[i];
		tot1 += max(0, a[i] - s1 * c);
		s2 += t[n - i - 1];
		tot2 += max(0, a[n - i - 1] - s2 * c);
	}
	puts(tot1 > tot2 ? "Limak" : tot1 < tot2 ? "Radewoosh" : "Tie");
	return 0;
}