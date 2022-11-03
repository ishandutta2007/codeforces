#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 5E2 + 10;

int n, m;
map<int, int> a;
int ans[MAXN];

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	scanf("%d", &n);
	m = n * n;
	for (int t, i = 0; i < m; ++i)
		scanf("%d", &t), ++a[t];
	for (int i = 0; i < n; ++i){
		ans[i] = (--a.end())->first;
		if (!--a[ans[i]])
			a.erase(ans[i]);
		for (int j = 0; j < i; ++j){
			int t = gcd(ans[i], ans[j]);
			if (!(a[t] -= 2))
				a.erase(t);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", ans[i], "\n "[i < n - 1]);
	return 0;
}