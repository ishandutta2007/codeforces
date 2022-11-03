#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

const int MAXN = 1E5 + 10;

PLL a[MAXN];

int main(){
	int n;
	int x1, x2;
	scanf("%d", &n);
	scanf("%d%d", &x1, &x2);
	for (int i = 0; i < n; ++i){
		int k, b;
		scanf("%d%d", &k, &b);
		a[i].st = k * (ll)x1 + b;
		a[i].nd = k * (ll)x2 + b;
	}
	sort(a, a + n);
	ll up = a[0].nd;
	bool flag = false;
	for (int i = 0; i < n; ++i){
		if (up > a[i].nd){
			flag = true;
			break;
		}
		up = max(up, a[i].nd);
	}
	puts(flag ? "YES" : "NO");
	return 0;
}