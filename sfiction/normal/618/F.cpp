#include <cstdio>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E6 + 10;

int n;
ll a[MAXN], b[MAXN];

pair<PII, PII> solve(ll a[], ll b[]){
	static int c[MAXN], res[MAXN];
	int r;
	for (int i = 0; i < n; ++i)
		res[i] = -1;
	c[0] = r = 0;
	res[0] = 0;
	for (int i = 1; i <= n; ++i){
		for (; a[i] > b[r]; ++r);
		c[i] = r;
		if (~res[b[r] - a[i]]){
			int j = res[b[r] - a[i]];
			return make_pair(PII(j + 1, i + 1), PII(c[j] + 1, c[i] + 1));
		}
		else
			res[b[r] - a[i]] = i;
	}
}

int main(){
	scanf("%d", &n);
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		a[i] = a[i - 1] + t;
	}
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		b[i] = b[i - 1] + t;
	}
	pair<PII, PII> c;
	if (a[n] <= b[n])
		c = solve(a, b);
	else{
		c = solve(b, a);
		swap(c.st, c.nd);
	}
	printf("%d\n", c.st.nd - c.st.st);
	for (int i = c.st.st; i < c.st.nd; ++i)
		printf("%d%c", i, "\n "[i < c.st.nd - 1]);
	printf("%d\n", c.nd.nd - c.nd.st);
	for (int i = c.nd.st; i < c.nd.nd; ++i)
		printf("%d%c", i, "\n "[i < c.nd.nd - 1]);
	return 0;
}