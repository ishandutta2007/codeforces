#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

class SNM {
private:
	vector<int> p;

public:
	SNM(int n) {
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	int findset(int x) {
		return x == p[x] ? x : p[x] = findset(p[x]);
	}

	void link(int a, int b) {
		a = findset(a);
		b = findset(b);

		if (b & 1) p[a] = b;
		else p[b] = a;
	}
};

int n, x[1010], y[1010];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d %d", &x[i], &y[i]);
	SNM snm(n);
	forn(i, n) forn(j, i)
		if (x[i] == x[j] || y[i] == y[j]) snm.link(i, j);

    set<int> ss;
    forn(i, n) ss.insert(snm.findset(i));

    printf("%d\n", (int)ss.size() - 1);

    return 0;
}