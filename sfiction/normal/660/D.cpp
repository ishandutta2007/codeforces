#include <cstdio>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 2E3 + 10;

int x[MAXN], y[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0;
	map<PII, int> lst;
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &x[i], &y[i]);
		for (int j = 0; j < i; ++j){
			ans += lst[PII(x[i] - x[j], y[i] - y[j])]++;
			ans += lst[PII(x[j] - x[i], y[j] - y[i])]++;
		}
	}
	printf("%I64d\n", ans >> 2);
	return 0;
}