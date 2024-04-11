#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef pair <LL, int> pli;

typedef tree <pli, null_type, less <pli>, rb_tree_tag, tree_order_statistics_node_update> SET;

SET S;
#define N 202020

int n, a[N];
LL t, s[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %I64d", &n, &t);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
	LL cnt = 0;
	S.insert(make_pair(s[n], n));
	for (int i = n - 1; i >= 0; i --) {
		cnt += S.order_of_key(make_pair(s[i] + t, -1));
		S.insert(make_pair(s[i], i));
	}
	printf("%I64d", cnt);

	return 0;
}