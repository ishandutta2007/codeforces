#include <cstdio>

typedef long long ll;

const int MAXN = 1E6 + 10;

int n;
char s[MAXN];
int up[MAXN], down[MAXN];
ll sa[MAXN], sb[MAXN];
int a[MAXN], b[MAXN];
ll ans[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'U'){
			up[i] = up[i - 1] + 1;
			sa[i] = sa[i - 1] + i;
			a[up[i]] = i;
		}
		else
			up[i] = up[i - 1], sa[i] = sa[i - 1];
	for (int i = n; i > 0; --i)
		if (s[i] == 'D'){
			down[i] = down[i + 1] + 1;
			sb[i] = sb[i + 1] + i;
			b[down[i]] = i;
		}
		else
			down[i] = down[i + 1], sb[i] = sb[i + 1];

	for (int i = 1; i <= n; ++i){
		if (s[i] == 'U'){
			if (up[i] - 1 >= down[i])
				ans[i] = (sb[i] - (sa[i - 1] - sa[a[up[i] - down[i] - 1]])) * 2 + (n - i + 1);
			else
				ans[i] = ((sb[i] - sb[b[down[i] - up[i]]]) - sa[i]) * 2 + i;
		}
		else{
			if (down[i] - 1 >= up[i])
				ans[i] = ((sb[i + 1] - sb[b[down[i] - up[i] - 1]]) - sa[i]) * 2 + i;
			else
				ans[i] = (sb[i] - (sa[i] - sa[a[up[i] - down[i]]])) * 2 + (n - i + 1);
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld%c", ans[i], "\n "[i < n]);

	return 0;
}