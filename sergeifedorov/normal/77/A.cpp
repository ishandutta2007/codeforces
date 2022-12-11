#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}


vector<int> g[10], a[10];
int pos[10];
int n;
long long A, B, C;
long long bst, cc;
map<string, int> h;
int K;

int num(string s){
	if (h.count(s) > 0)
		return h[s];
	h[s] = K;
	K ++;
	return h[s];
}

int main ()
{
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);

	K = 0;
	cin >> n;
	forn(i, n){
		string s1,s2, w;
		cin >> s1 >> w >> s2;
		g[num(s1)].pb(num(s2));
		cerr << num(s1) << " " << num(s2) << endl;
	}
	cin >> A >> B >> C;
	bst = 1e18;
	cc = -1e9;
	forn(i, pow(3.0, 7.0) + 1){
		forn(j, 10)
			a[j].clear();
		int now = i;
		forn(j, 7){
			a[now % 3].pb(j);
			pos[j] = now  %3;
			now /= 3;
		}
		if (a[0].size() == 0 || a[1].size() == 0 || a[2].size() == 0)
			continue;

		long long pnt = max(A / a[0].size(), max(B / a[1].size(), C / a[2].size())) - min(A / a[0].size(), min(B / a[1].size(), C / a[2].size()));
		int cnt = 0;
		forn(i, 7)
			forn(j, g[i].size())
				if (pos[i] == pos[g[i][j]])
					cnt ++;
		if (pnt < bst || (pnt == bst && cc < cnt)){
			bst = pnt;
			cc = cnt;
		}
	}
	cout << bst << " "<< cc << endl;


	return 0;
}