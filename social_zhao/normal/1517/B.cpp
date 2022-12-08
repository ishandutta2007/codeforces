#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const ll MAXN = 111;

struct node {
	ll w[MAXN], st, id, ed;
	bool friend operator < (node x, node y) {
		return x.w[x.st] > y.w[y.st];
	}
}a[MAXN];

ll n, m;
ll mp[MAXN][MAXN];
ll x[MAXN], y[MAXN];

ll read() {
	ll X = 0, F = 1; char C = getchar();
	while(C < '0' || C > '9') {if(C == '-')F=-1; C = getchar();}
	while(C >= '0' && C <= '9') {X = X*10+C-'0'; C = getchar();}
	return X * F;
}

int main() {
	ll T = read();
	while(T--) {
		n = read(); m = read();
		priority_queue<node> q;
		for(ll i = 1; i <= n; ++i) {
			for(ll j = 1; j <= m; ++j)
				a[i].w[j] = read();
			sort(a[i].w + 1, a[i].w + m + 1);
			a[i].st = 1; a[i].id = i; a[i].ed = m;
			q.push(a[i]);
		}
		for(ll i = 1; i <= m; ++i) {
			node tmp = q.top();
			q.pop();
			for(int j = 1; j <= n; ++j) {
				if(j == tmp.id) mp[j][i] = tmp.w[tmp.st];
				else mp[j][i] = a[j].w[a[j].ed--];
			}
			++tmp.st;
			q.push(tmp);
		}
		for(ll i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j)
				printf("%lld ", mp[i][j]);
			puts("");
		}
	}
	return 0;
}