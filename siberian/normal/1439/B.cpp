#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
 
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
const int N = 100100;
vector<int> g[N];
int n, m, k, P;
int q[N];
int topQ;
int deg[N];
bool on[N];
 
bool isPrime(int x) {
	if (x < 2) return false;
	for (int y = 2; y * y <= x; y++) {
		if (x % y == 0)
			return false;
	}
	return true;
}
 
ll table[30 * N + 5555];
ll A, B;
 
inline int getHash(int v, int u) {
	return (v * A + u + B) % P;
}
 
void addEdge(int v, int u) {
	int h = getHash(v, u);
	while(table[h] != -1) {
		h++;
		if (h == P) h = 0;
	}
	table[h] = (ll)v * N + u;
}
bool getEdge(int v, int u) {
	int h = getHash(v, u);
	ll Z = (ll)v * N + u;
	while(table[h] != -1) {
		if (table[h] == Z) return true;
		h++;
		if (h == P) h = 0;
	}
	return false;
}
 
bool checkClique(vector<int> w) {
	int sz = (int)w.size();
	for (int i = 0; i < sz; i++)
		for (int j = i + 1; j < sz; j++) {
			if (!getEdge(w[i], w[j]))
				return false;
		}
	return true;
}
 
void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		g[i].clear();
		deg[i] = 0;
		on[i] = 1;
	}
	topQ = 0;
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	if ((ll)k * (k - 1) / 2 > m) {
		printf("-1\n");
		return;
	}
	P = 20 * m + 3;
	while(!isPrime(P)) P++;
	for (int i = 0; i < P; i++)
		table[i] = -1;
	for (int v = 0; v < n; v++) {
		sort(all(g[v]));
		deg[v] = (int)g[v].size();
		if (deg[v] < k) q[topQ++] = v;
		for (int u : g[v])
			if (v < u)
				addEdge(v, u);
	}
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		on[v] = false;
		for (int u : g[v]) {
			deg[u]--;
			if (deg[u] == k - 1)
				q[topQ++] = u;
		}
		if (deg[v] != k - 1) continue;
		vector<int> z;
		for (int u : g[v])
			if (on[u])
				z.push_back(u);
		assert((int)z.size() == k - 1);
		if (!checkClique(z)) {
			continue;
		}
		printf("2\n%d", v + 1);
		for (int x : z)
			printf(" %d", x + 1);
		printf("\n");
		return;
	}
	if (topQ == n) {
		printf("-1\n");
		return;
	}
	printf("1 %d\n", n - topQ);
	for (int i = 0; i < n; i++)
		if (on[i])
			printf("%d ", i + 1);
	printf("\n");
}
 
int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	A = 10 + myRand(10000);
	B = myRand((ll)1e7);
 
	int t;
	scanf("%d", &t);
	while(t--) solve();
 
	return 0;
}