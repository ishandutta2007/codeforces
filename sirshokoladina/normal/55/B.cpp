#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

long long op (long long a, long long b, char d) {
	if (d == '+')
		return a + b;
	return a * b;
}

long long solve (vector<long long> a, vector<char> c) {
	if (a.size() == 1) {
		return a[0];
	}
	char d = c[c.size() - 1];
	c.pop_back();
	long long mn = 1000000000ll * 1000000000ll;
	forn (i, a.size())
		forn (j, i) {
			vector<long long> b;
			forn (k, a.size())
				if (k != i && k != j)
					b.pb(a[k]);
		        b.pb(op(a[i], a[j], d));
                	mn = min(mn, solve(b, c));
		}
	return mn;
}

int main () {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	vector<long long> a;
	vector<char> c;
	a.resize(4);
	c.resize(3);
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	cin>>c[2]>>c[1]>>c[0];
	cout<<solve(a,c);
	return 0;
}