#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);

vi p1[30], p2[30];
vector <ll> s1[30], s2[30];
char s[200200], t[200200];

inline ll get(vector <ll> &s, int l, int r){
	if(l > r){
		return 0;
	}
	return s[r] - (l > 0 ? s[l - 1] : 0);
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	int n;
	scanf("%d %s %s", &n, s, t);
	for(int i = 0; i < n; i++){
		p1[s[i] - 'A'].pb(i);
	}
	for(int i = 0; i < n; i++){
		p2[t[i] - 'A'].pb(i);
	}
	for(int i = 0; i < 26; i++){
		s1[i].resize(sz(p2[i]));
		for(int j = 0; j < sz(p2[i]); j++){
			s1[i][j] = (j > 0 ? s1[i][j - 1] : 0) + (n - p2[i][j]);
		}
		s2[i].resize(sz(p2[i]));
		for(int j = 0; j < sz(p2[i]); j++){
			s2[i][j] = (j > 0 ? s2[i][j - 1] : 0) + (p2[i][j] + 1);
		}
	}
	double ans = 0;
	ll all = 0;
	for(int i = 1; i <= n; i++){
		all += ll(n - i + 1) * (n - i + 1);
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < sz(p1[i]); j++){
			int pos = lower_bound(p2[i].begin(), p2[i].end(), p1[i][j]) - p2[i].begin();
			ans += double(n - p1[i][j]) * get(s2[i], 0, pos - 1) / all;
			ans += double(p1[i][j] + 1) * get(s1[i], pos, sz(p2[i]) - 1) / all;
		}
	}
	printf("%.18lf\n", ans);
	return 0;
}