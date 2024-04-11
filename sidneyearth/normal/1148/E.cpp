#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 2000100;
int x[maxn], y[maxn], z[maxn], c, b[maxn];
pair<int, int> p[maxn];
void Do(int u, int v, int w){
	++c;
	x[c] = u;
	y[c] = v;
	z[c] = w;
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	for(int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	sort(p + 1, p + 1 + n);
	sort(b + 1, b + 1 + n);

	for(int i = 1; i <= n; ++i)
		p[i].first = b[i] - p[i].first;

	long long sum = 0;
	for(int i = 1; i <= n; ++i){
		sum += p[i].first;
		if(sum < 0){
			printf("NO\n");
			return 0;
		}
	}
	if(sum > 0){
		printf("NO\n");
		return 0;
	}

	for(int i = 1, j = 1; i <= n && j <= n; ){
		while(i <= n && p[i].first >= 0) ++i;
		while(j <= n && p[j].first <= 0) ++j;
		if(i > n || j > n) break;
		int d = min(-p[i].first, p[j].first);
		p[i].first += d;
		p[j].first -= d;
		Do(p[j].second, p[i].second, d);
	}

	for(int i = 1; i <= n; ++i)
		if(p[i].first){
			printf("NO\n");
			return 0;
		}

	printf("YES\n%d\n", c);
	for(int i = 1; i <= c; ++i)
		printf("%d %d %d\n", x[i], y[i], z[i]);

	return 0;
}