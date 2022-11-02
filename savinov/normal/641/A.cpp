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

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi b(n);
    forn (i, n)
    {
		char c; cin >> c;
		if (c == '>') b[i] = 1;
		else b[i] = -1;
	}
	forn (i, n) {
		int x;
		cin >> x;
		b[i] *= x;
	}
	vi used(n);
	int pos = 0;
	while (pos >= 0 && pos < n && !used[pos]) {
	    //cout << pos << " " << b[pos] << endl;
		used[pos] = 1;
		pos += b[pos];
	}
	if (pos >= 0 && pos < n) cout << "INFINITE";
	else cout << "FINITE";
    return 0;
}