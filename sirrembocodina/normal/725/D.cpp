#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
 
using namespace std;
 
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;
const int K = 330;

pair<long long, long long> a[300100];
multiset<long long> s;

int main() {
	int n;
	cin >> n;
	--n;
	long long A, tmp;
	cin >> A >> tmp;
	forn (i, n) {
		cin >> a[i].fs >> a[i].sc;
		a[i].sc += 1 - a[i].fs;
		a[i].fs *= -1;
	}
	sort(a, a + n);
	forn (i, n) {
		a[i].fs *= -1;
//		cout << a[i].fs << " " << a[i].sc << endl;
	}
//	cout << endl;
	int ans = 2000000000, cur = 0;
	a[n] = make_pair(0, 0);
	forn (i, n + 1) {
//		cout << a[i].fs << " " << A << endl;
		while (!s.empty() && a[i].fs <= A - (*s.begin())) {
//			cout << (*s.begin()) << " ";
			--cur;
			A -= *s.begin();
			s.erase(s.begin());
		}
//		cout << endl;
		if (a[i].fs <= A) {
			ans = min(ans, cur);
		}
		s.insert(a[i].sc);
		++cur;
	}
	cout << ans + 1 << endl;
    return 0;
}