#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E5 + 10, MAXW = 1E9 + 10;

PII a[MAXN];
int u[MAXN], v[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int t, i = 0; i < m; ++i){
		scanf("%d%d", &a[i].st, &t);
		a[i].st = a[i].st << 1 | !t;
		a[i].nd = i;
	}
	sort(a, a + m);

	bool flag = true;
	int r0 = 1, l = 0, r = 3;
	for (int i = 0; i < m; ++i){
		if (a[i].st & 1){
			if (++l >= r - 1)
				l = 1, ++r;
			if (r > r0){
				flag = false;
				break;
			}
			u[a[i].nd] = l;
			v[a[i].nd] = r;
		}
		else{
			u[a[i].nd] = r0;
			v[a[i].nd] = ++r0;
		}
	}
	if (flag){
		for (int i = 0; i < m; ++i)
			printf("%d %d\n", u[i], v[i]);
	}
	else
		puts("-1");
	return 0;
}