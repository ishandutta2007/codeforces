#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E5 + 10;

int n;
int a[MAXN];
int fa[MAXN];

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	vector<int> b;
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		int u = find(i), v = find(a[i]);
		if (u != v)
			fa[u] = v;
		else
			b.push_back(i);
	}
	int l = -1;
	for (int i = 0; i < b.size(); ++i)
		if (a[b[i]] == b[i]){
			l = i;
			break;
		}

	if (l == -1){
		a[b[0]] = b[0];
		printf("%d\n", b.size());
	}
	else{
		swap(b[0], b[l]);
		printf("%d\n", b.size() - 1);		
	}
	for (int i = 1; i < b.size(); ++i)
		a[b[i]] = b[0];
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i], "\n "[i < n]);
	return 0;
}