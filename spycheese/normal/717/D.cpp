#define _ijps 0
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;

#define name ""
typedef unsigned long long ull;
typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

struct __isoff{
	__isoff(){
		if (_ijps)
			freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
		//else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
		//ios_base::sync_with_stdio(0);
		//srand(time(0));
		srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
	}
	~__isoff(){
		//if(_ijps) cout<<times<<'\n';
	}
} __osafwf;
const ull p1 = 131;
const ull p2 = 129;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int infi = 1e9 + 7;
const ll inf = 1e18 + 7;
const ll dd = 1e5 + 7;
const ll mod = 1e9 + 7;

int const si = 130;

struct mat{
	double mats[si][si];
	mat(){
		forn(i, si)
			forn(j, si)
				mats[i][j] = 0;
	}
};


mat mul(mat a, mat b){
	mat c;
	forn(i, si){
		forn(j, si){
			forn(k, si){
				c.mats[i][j] += a.mats[i][k] * b.mats[k][j];
			}
		}
	}
	return c;
}

mat bp(mat c, int k){
	if(k == 1){
		return c;
	}
	if(k % 2 == 1){
		return mul(bp(c, k - 1), c);
	}
	c = bp(c, k / 2);
	return mul(c, c);
}

int main(){
	mat q, w;
	q.mats[0][0] = 1;
	int n, k;
	cin >> n >> k;
	forn(i, k + 1){
		double t;
		cin >> t;
		forn(j, si){
			if((j ^ i) < si)
				w.mats[j][j ^ i] = t;
		}
	}
	q = bp(w, n);
	double res = 1 - q.mats[0][0];
	printf("%0.10f", res);
}