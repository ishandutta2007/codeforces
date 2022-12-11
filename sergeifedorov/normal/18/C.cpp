#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

const int mod = 51123987;
const int nmax = 160;

int n;
int a[100100];
int p1,p2;

int main(){


	cin >> n;
	forn(i,n){
		scanf("%d", &a[i]);
		p2 += a[i];
	}
	p1 = 0;
	int res = 0;
	forn(i,n-1){
		p1 += a[i];
		p2 -= a[i];
		if (p1 == p2) res++;
	}
	cout << res << endl;

	return 0;
}