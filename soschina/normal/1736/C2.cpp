#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 2e5 + 2;

int n, q, a[N], b[N] = {1};

struct node{
	int id, x;
	node(int id, int x) : id(id), x(x){}
};
vector<node> qry[N];

long long s[N], ans[N];
int stk[N], pos[N], top;
long long sum[N];

int main(){
    scanf("%d", &n);
	a[0] = 1;
	for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        a[i] = max(1, i - a[i] + 1);
		b[i] = max(b[i - 1], a[i]);
		s[i] = s[i - 1] + b[i];
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; i++){
		int p, x;
		scanf("%d%d", &p, &x);
		x = max(b[p - 1], p - x + 1);
		qry[p].push_back(node(i, x));
		ans[i] = 1ll * n * (n + 3) / 2;
		ans[i] -= s[p - 1];
	}
	top++;
	stk[0] = n + 1;
	pos[0] = n + 1;
	sum[0] = 0;
	for(int i = n; i; i--){
		for(node nd : qry[i]){
			int p = lower_bound(stk, stk + top, nd.x, greater<int>()) - stk - 1;
			ans[nd.id] -= sum[p] + 1ll * (pos[p] - i) * nd.x;
		}
		while(a[i] >= stk[top - 1])
			top--;
		stk[top] = a[i];
		pos[top] = i;
		sum[top] = sum[top - 1] + 1ll * (pos[top - 1] - i) * a[i];
		top++;
	}
	for (int i = 1; i <= q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}