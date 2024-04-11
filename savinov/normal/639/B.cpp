#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

void NO(){
	puts("-1");
	exit(0);
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n, d, h;
    cin >> n >> d >> h;
    if (d == 1 && n > 2) 
		NO();
    if (h < d / 2 + d % 2) {
		NO();
	}
	vi p;
	vpi e;
	forn (i, d + 1) 
		p.pb((i + 1) % n);
	if (d == n - 1) {
		swap(p.back(), p[h]);
	}
	else
		p[h] = 0;
	vi used(n, 0);
	
	for (int x: p) used[x] = 1;
	forn (i, p.size() - 1) {
		cout << p[i] + 1 << " " << p[i + 1] + 1 << "\n";
	}
	//cout << "!" << "\n";
	forn (i, n)
		if (!used[i])
			cout << i + 1 << " " << p[1] + 1 << "\n";
    return 0;
}