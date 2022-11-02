#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>
//#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x).size()
#define bit(x) (1 << (x))
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define cnti(x) __builtin_pop_count(x)
#define cntl(x) __builtin_pop_countll(x)

typedef unsigned int LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;

template <class T, class U>
inline void chkmax(T &a, U b) {
	if (a < b) a = b;
}

template <class T, class U>
inline void chkmin(T &a, U b) {
	if (a > b) a = b;
}

LL a[222];

LL modP(LL x) {
	LL m = (1LL<<31) - 1;
	LL res = 1;
	while (m) {
		if (m % 2) res = res * x;
		m /= 2;
		x = x * x;
	}
	return res;
}

int ord(int x) {
	int cnt = 0;
	while (x % 2 == 0) x /= 2, cnt++;
	return cnt;
}
		
int main() {

	
	int n, q, p;
	scanf("%d%d%d", &n, &p, &q);
	LL res = 0;
	a[0] = 1;
	int cnt = 0;
	LL cur = 1;
	for (int i = 1; i < min(133, n + 1); i++) {
		cnt += ord(n - i + 1) - ord(i);
		int x = (n - i + 1) / (1<<ord(n - i + 1));
		int y = i / (1<<ord(i));
// 		cout<<cnt<<' '<<x<<' '<<y<<endl;
		cur = cur * x * modP(y);
// 		cout<<cur<<' '<<modP(y)<<endl;
		if (cnt > 31) a[i] = 0;
		else a[i] = cur * (1LL<<cnt);
// 		cout<<i<<' '<<a[i]<<endl;
	}
	for (int i = 1; i <= q; i++) {
		int t = min(n - 1, p);
		LL ans = 1;
		LL pos = 1;
		for (int  j = 1; j <= t; j++) {
			pos = pos * i;
			ans = (ans + pos * a[j]);
		}
// 		cout<<i<<' '<<ans<<endl;
		ans = ans * i;
		res ^= ans;
	}
	cout<<res<<endl;
	return 0;
}