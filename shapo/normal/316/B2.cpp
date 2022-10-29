#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair

#define maxn 2014

int len[maxn];
int n, k;
int par[maxn], son[maxn];
bool bad[maxn];
bool can_go[maxn];

int main() {
	/*while (*/scanf("%d%d", &n, &k);// == 2) {
	memset(par, -1, sizeof(int) * (n + 1));
	memset(son, -1, sizeof(int) * (n + 1));
	memset(bad, false, sizeof(bool) * (n + 1));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", par + i);
		if (par[i])
			son[par[i]] = i;
	}
	int cur = k, lenk = 0;
	while (son[cur] != -1) {
		cur = son[cur];
		bad[cur] = true;
	}
	cur = k;
	while (cur != 0) {
		++lenk;
		bad[cur] = true;
		//printf("cur = %d\n", cur);
		cur = par[cur];
	}
	//printf("lenk = %d\n", lenk);
	vector < int > possible;
	for (int i = 1; i <= n; ++i) {
		if (!bad[i] && son[i] == -1) {
			int curl = 0;
			cur = i;
			while (cur != 0) {
				++curl;
				cur = par[cur];
			}
			possible.pb(curl);
		}
	}
	memset(can_go, false, sizeof(bool) * (n + 1));
	can_go[0] = true;
	for (auto x : possible) {
		for (int j = n; j >= x; --j)
			can_go[j] = can_go[j] || can_go[j - x];
	}
	for (int i = 0; i <= n; ++i)
		if (can_go[i])
			printf("%d\n", i + lenk);
	/*printf("\n");
	}*/
	return 0;
}