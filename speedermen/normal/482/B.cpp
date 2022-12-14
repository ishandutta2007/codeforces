#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;
 
const bool db = false;
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define inf 1000000007
#define nmax 100010
#define mmax 150010
#define eps 1e-9

struct TEvent {
	int x, op, val;
} ev[2 * nmax];

int n, m, t[2 * nmax];
int l[nmax], r[nmax], q[nmax];
int bit[30];
bool ok = true;

int get(int l, int r) {
	l += n - 1; r += n - 1;
	int ans = (1 << 30) - 1;
	while(l <= r) {
		if(l & 1) ans &= t[l++];
		if(~r & 1) ans &= t[r--];
		l >>= 1; r >>= 1;
	}
	return ans;
}

bool cmp(const TEvent & a, const TEvent & b) {
	if(a.x != b.x)
		return a.x < b.x;
	if(a.op != b.op)
		return a.op < b.op;
	return a.val < b.val;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	//ios :: sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &q[i]);
		ev[2 * i - 2].x = l[i]; ev[2 * i - 2].op = 0; ev[2 * i - 2].val = q[i];
		ev[2 * i - 1].x = r[i]; ev[2 * i - 1].op = 1; ev[2 * i - 1].val = q[i];
	}
	sort(ev, ev + 2 * m, cmp);
	for(int i = 0; i < n; ++i)
		t[i + n] = (1 << 30) - 1;
	for(int i = 0, j; i < 2 * m; ) {
		j = i;
		while(ev[j].x == ev[i].x && ev[j].op == 0) {
			for(int k = 0; k < 30; ++k)
				bit[k] += (ev[j].val >> k) & 1;
			++j;
		}
		int cur = 0;
		for(int k = 0; k < 30; ++k)
			if(bit[k])
				cur |= 1 << k;
		t[ev[i].x + n - 1] = cur;
		while(ev[j].x == ev[i].x && ev[j].op == 1) {
			for(int k = 0; k < 30; ++k)
				bit[k] -= (ev[j].val >> k) & 1;
			++j;
		}
		i = j;
	}
	for(int i = n - 1; i > 0; --i)
		t[i] = t[i + i] & t[i + i + 1];
	for(int i = 1; i <= m; ++i)
		if(get(l[i], r[i]) != q[i])
			ok = false;
	if(ok) {
		cout << "YES" << endl;
		for(int i = 0; i < n; ++i)
			cout << t[i + n] << " ";
	} else
		cout << "NO" << endl;
	getchar(); getchar();
	return 0;
}