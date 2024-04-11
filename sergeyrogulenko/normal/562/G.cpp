#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_DEPRECATE

#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<bitset>
#include<cmath>
#include<complex>
#include<ctime>
#include<iostream>
#include<sstream>
#include<vector>

#define next nexthui
#define prev prevhui
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define last(x) ((int)x.size()-1)

using namespace std;

typedef long long int64;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;
const ldb EPS = 1e-9;

const int NMAX = (30 * 1000 + 50);

int a[4*NMAX], b[4*NMAX], c[4*NMAX];
int n;
int s[NMAX];
vector<int> x, y;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	srand(534856);
	scanf("%d", &n);
	forn(i, n)
		s[i] = 4;
	x.resize(n * 4);
	forn(i, n * 4) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i]--;
		b[i]--;
		c[i]--;
		x[i] = i;
	}
	printf("YES\n");
	while (x.size() > 0) {
		random_shuffle(all(x));
		y.clear();
		forn(i, x.size()) {
			int aa = a[x[i]];
			int bb = b[x[i]];
			int cc = c[x[i]];
			s[aa]--;
			s[bb]++;
			s[cc]++;
			if (s[bb] <= 9 && s[cc] <= 9) {
				printf("%d ", x[i] + 1);
			} else {
				s[aa]++;
				s[bb]--;
				s[cc]--;
				y.pb(x[i]);
			}
		}
		x = y;
	}
	printf("\n");
}