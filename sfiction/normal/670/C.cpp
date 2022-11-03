#include <cstdio>
#include <map>

using namespace std;

const int MAXM = 2E5 + 10;

map<int, int> lst;

int b[MAXM], c[MAXM];

int get(int x){
	return lst.find(x) == lst.end() ? 0 : lst[x];
}

int main(){
	int n, m;
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		if (lst.find(t) == lst.end())
			lst[t] = 1;
		else
			++lst[t];
	}
	scanf("%d", &m);
	for (int t, i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	int ans = 0, A, B;
	for (int t, i = 1; i <= m; ++i){
		scanf("%d", &c[i]);
		int u = get(b[i]), v = get(c[i]);
		if (ans == 0 || A < u || A == u && B < v){
			ans = i;
			A = u, B = v;
		}
	}
	printf("%d\n", ans);
	return 0;
}