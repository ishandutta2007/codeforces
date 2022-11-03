/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 551E
 */
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 5E5, MAXB = 800;

int n, m, len;
int left[MAXB], right[MAXB];
ll origin[MAXN];
vector<pair<ll, int> > order;
ll add[MAXB];

void update(int u, int l, int r, ll x){
	if (left[u] == l && right[u] == r)
		add[u] += x;
	else{
		for (int i = l; i < r; ++i)
			origin[i] += x;
		for (int i = left[u]; i < right[u]; ++i)
			order[i] = make_pair(origin[i], i);
		sort(order.begin() + left[u], order.begin() + right[u]);
	}
}

int findleft(int u, ll x){
	vector<pair<ll, int> >::iterator l = order.begin() + left[u], r = order.begin() + right[u];
	vector<pair<ll, int> >::iterator temp = lower_bound(l, r, make_pair(x, -1));
	if (temp < r && temp->first == x)
		return temp->second;
	else
		return n;
}

int findright(int u, ll x){
	vector<pair<ll, int> >::iterator l = order.begin() + left[u], r = order.begin() + right[u];
	vector<pair<ll, int> >::iterator temp = upper_bound(l, r, make_pair(x, n)) - 1;
	if (l <= temp &&  temp->first == x)
		return temp->second;
	else
		return -1;
}

int main(){
	int Q;

	scanf("%d%d", &n, &Q);
	len = sqrt(n + 0.5);
	m = (n - 1) / len + 1;
	for (int i=0;i<m;++i){
		left[i] = i * len;
		right[i] = left[i] + len;
	}
	right[m - 1] = n;

	order = vector<pair<ll, int> >(n);
	for (int i=0;i<n;++i){
		scanf("%I64d", &origin[i]);
		order[i] = make_pair(origin[i], i);
	}
	for (int i=0;i<m;++i)
		sort(order.begin() + left[i], order.begin() + right[i]);
	memset(add, 0, sizeof(add));

	while (Q--){
		int com;
		scanf("%d", &com);

		if (com == 1){
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			--l, --r;
			int pl = l / len, pr = r / len;

			if (pl == pr)
				update(pl, l, r + 1, x);
			else{
				update(pl, l, right[pl], x);
				update(pr, left[pr], r + 1, x);
				for (int i = pl + 1; i < pr; ++i)
					update(i, left[i], right[i], x);
			}
		}
		else{
			int x;
			scanf("%d", &x);

			int ansleft = n, ansright = -1;
			for (int i = 0; i < m; ++i){
				ansleft = min(ansleft, findleft(i, x - add[i]));
				ansright = max(ansright, findright(i, x - add[i]));
			}

			if (ansleft == n)
				puts("-1");
			else
				printf("%d\n", ansright - ansleft);
		}
	}

	return 0;
}