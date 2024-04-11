#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <ctime>
#include <stack>
#include <cassert>
#include <list>
//#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    clock_t start = clock();
#else
	
    //freopen("taxi.in", "r", stdin);
    //freopen("taxi.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}
int x[3333];
int y[3333];
int dist[3000][3000];
pi pairs[3000 * 3000 / 2];
bool cmp(const pi& a, const pi&b) {
	return dist[a.first][a.second] > dist[b.first][b.second];
}

const int size = 3000/32 + 1;

struct mybitset {
	unsigned a[size];
	void set(int b) {
		a[b / 32] |= (1U<<(b & 31));
	}
};

bool any(mybitset& a, mybitset& b){
	for(int i = 0; i < size; ++i) {
		if(a.a[i] & b.a[i])
			return true;
	}
	return false;
}

mybitset bs[3000];


void solve() {
	memset(bs, 0, sizeof bs);
	
	for(int i = 0; i < 3000; ++i) {
		for(int j = 0; j < size; ++j) {
			assert(!bs[i].a[j]);
		}
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			//i > j
			dist[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			pairs[cnt++] = pi(i, j);
		}
	}
	sort(pairs, pairs + cnt, cmp);
	
	for(int i = 0; i < cnt; ++i) {
		int a = (pairs[i].first);
		int b = (pairs[i].second);
		if(any(bs[a], bs[b])) {
			cout.precision(12);
			cout << fixed;
			cout << sqrt(1.0 * dist[pairs[i].first][pairs[i].second]) / 2;
			return;
		}
		bs[a].set(b);
		bs[b].set(a);
	}
	
	assert(false);
}