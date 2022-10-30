#define _CRT_SECURE_NO_WARNINGS

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

int lst;
int n;
int a[1000500];
pii t[2097152];
pair<int64, int64> ts[2097152];
int64 ans[1000500];

void build_tree() {
    lst = 1;
	seta(t, 0);
    while (lst < n)
        lst *= 2;
    for (int i = 0; i < n; i ++)
        t[i+lst] = mp(a[i], i);
    for (int i = n; i < lst; i ++)
        t[i] = mp(inf, 0);
    for (int i = lst-1; i >= 1; i --)
        t[i] = min(t[i*2], t[i*2+1]);      

	seta(ts, 0);
    for (int i = 0; i < n; i ++)
        ts[i+lst] = mp(0LL, 0LL);
    for (int i = n; i < lst; i ++)
        ts[i] = mp(0LL, 0LL);
    for (int i = lst-1; i >= 1; i --)
        ts[i] = min(ts[i*2], ts[i*2+1]);      
}

pii rmq (int v, int l, int r, int a, int b) {
    if (r < a || l > b)
        return mp(inf, 0);
    if (a <= l && r <= b)
        return t[v];
    int mid = (l + r) >> 1;
    return min(rmq(v*2, l, mid, a, b), rmq(v*2+1, mid+1, r, a, b));
}

void push(int v) {
	if (v >= lst)
		return;
	ts[v*2].fs += ts[v].fs;
	ts[v*2+1].fs += ts[v].fs;
	ts[v*2].sc += ts[v].sc;
	ts[v*2+1].sc += ts[v].sc;
	ts[v] = mp (0LL, 0LL);
}

void add (int v, int l, int r, int a, int b, int64 c, int64 cd) {
	if (a > b)
		return;
    push(v);
	if (r < a || l > b)
        return;
    if (a <= l && r <= b) {
		ts[v].fs += c;
		ts[v].sc += cd;
		return;
	}
    int mid = (l + r) >> 1;
	add (v*2, l, mid, a, b, c, cd);
	add (v*2+1, mid+1, r, a, b, c, cd);
}

void go (int l, int r) {
	if (l > r) 
		return;
	pii v = rmq(1, 0, lst-1, l, r);
	int x = v.fs;
	int pos = v.sc;
	int L = pos - l + 1;
	int R = r - pos + 1;
	if (L > R)
		swap (L, R);
	add (1, 1, lst, 1, L, 0, x);
	add (1, 1, lst, L+1, R, (int64)L * x, 0);
	add (1, 1, lst, R+1, r-l+1, (int64)x * (L+R), -x);
	go (l, pos-1);
	go (pos+1, r);
}

int64 calc (int64 v, pair<int64, int64> W) {
	return W.fs + v * W.sc;
}

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);    
	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);
	build_tree();
	go (0, n-1);
	for (int i = 1; i < lst; i ++)
		push(i);
	for (int i = 0; i < n; i ++)
		ans[i+1] = calc(i+1, ts[lst+i]);
	int m;
	cin >> m;
	forn(i, m) {
		int x;
		scanf ("%d", &x);
		printf ("%.9lf\n", 1. * ans[x] / (n-x+1));
	}
    return 0;
}