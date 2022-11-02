#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <ctime>
#include <cassert>
#include <complex>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i ++)
#define ford(i,n) for (int j = (int)(n)-1; j >= 0; j --)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define fs first
#define sc second
#define I (int)
#define seta(x,y) memset (x, y, sizeof (x))

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const int inf = (1 << 30) - 1;
const int64 inf64 = (1LL << 62) - 1;
const ldb eps = 1e-9;
const ldb pi = acosl(-1.); 

char buf[2000000];
bool u[26];
vector<int> a[26];
vector<pii> b;
vector <pii> Q[1<<13];
int s[1<<13];

void update(vector <pii>& Q) {
	seta(s, 0);
	forn(i, Q.size())
		s[Q[i].fs] ++;
	Q.clear();
	forn(i, 1<<13)
		if (s[i])
			Q.pb (mp (i, s[i]));
}

int find(vector <pii>& Q, int mask) {
	seta(s, 0);
	forn(i, Q.size())
		s[Q[i].fs] += Q[i].sc;
	return s[mask];
}

int get(int mask) {
	return find(Q[mask>>13], mask & ((1 << 13) - 1));
}

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);    
	gets(buf);
	int n = strlen(buf);
	forn(i, n)
		buf[i] -= 'a';
	forn(i, 26)
		a[i].clear();
	forn(i, n)
		a[buf[i]].pb(i);
	forn(i, 26)
	reverse(all(a[i]));
	forn(i, n) {
		b.clear();
		forn(j, 26)
			if (a[j].size())
				b.pb(mp(a[j].back(), j));
		sort(all(b));
		a[buf[i]].pop_back();
		int mask = 0;
		forn(j, b.size()) {
			mask |= (1 << b[j].sc);
			if (i == 0 || (mask & (1 << buf[i-1])) == 0)
				Q[mask >> 13].pb (mp(mask & ((1 << 13) - 1), 1));
		}
	}
	forn(i, 1<<13)
		update(Q[i]);
	int m;
	scanf("%d", &m);
	forn(i, m) {
		scanf("%s", buf);
		string s = buf;
		int mask = 0;
		forn(i, s.length())
			mask |= 1 << (s[i]-'a');
		cout << get(mask) << endl;
	}
	return 0;
}