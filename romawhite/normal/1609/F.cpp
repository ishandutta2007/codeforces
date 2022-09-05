#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
#include <random>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1000007;
const int MOD = 1000000007;

const int K = 60;

Int A[MAX];
int B[MAX];

Int res = 0;

int szx = 0;
Int X[MAX];
int BX[MAX];
int szy = 0;
Int Y[MAX];
int BY[MAX];

Int MN[MAX];
Int MX[MAX];
VI MXID[K];

void f(bool c) {
	// cout << c << endl;
	// FOR(i,0,szx) {
	// 	cout << X[i] << ' ' << BX[i] << "   ";
	// }
	// cout << endl;
	// FOR(i,0,szy) {
	// 	cout << Y[i] << ' ' << BY[i] << "   ";
	// }
	// cout << endl;
	// res = 0;
	FOR(i,0,K) {
		MXID[i].clear();
	}
	Int mn = LINF + 7;
	int bmn, bmx;
	Int mx = -1;
	FOR(i,0,szy) {
		if (Y[i] < mn) {
			mn = Y[i];
			bmn = BY[i];
		}
		if (Y[i] > mx) {
			mx = Y[i];
			bmx = BY[i];
		}
		MN[i] = -mn;
		MX[i] = mx;
		MXID[bmx].push_back(i);
	}
	mn = LINF + 7;
	mx = -1;
	FOR(i,0,szx) {
		if (X[i] < mn) {
			mn = X[i];
			bmn = BX[i];
		}
		if (X[i] > mx) {
			mx = X[i];
			bmx = BX[i];
		}
		
		if (bmn == bmx) {
			int cnt = min(lower_bound(MN, MN + szy, -mn + c) - MN, lower_bound(MX, MX + szy, mx + c) - MX);
			res += cnt;
		}
		int r = lower_bound(MN, MN + szy, -mn + c) - MN;
		int l = lower_bound(MX, MX + szy, mx + c) - MX;
		// cout << "l r " << l << ' ' << r << ' ' << bmn << endl;
		if (r > l) {
			// cout << bmn << endl;
			res += lower_bound(ALL(MXID[bmn]), r) - lower_bound(ALL(MXID[bmn]), l);
		}
	}
	// cout << "RES " << res << endl;
}


void solve(int l, int r) {
	if (l == r) {
		res ++;
		return;
	}
	int m = (l + r) / 2;
	solve(l, m);
	solve(m + 1, r);

	szx = 0;
	RFOR(i,m + 1, l) {
		BX[szx] = B[i];
		X[szx ++] = A[i];
	}
	szy = 0;
	FOR(i,m + 1, r + 1) {
		BY[szy] = B[i];
		Y[szy ++] = A[i];
	}
	f(0);
	szx = 0;
	FOR(i,m + 1, r + 1) {
		BX[szx] = B[i];
		X[szx ++] = A[i];
	}
	szy = 0;
	RFOR(i,m + 1, l) {
		BY[szy] = B[i];
		Y[szy ++] = A[i];
	}
	f(1);
}

int brute(int l, int r) {
	int res = 0;
	FOR(i,l, r + 1) {
		Int mn = LINF + 7;
		Int mx = -1;
		int bmn, bmx;
		FOR(j,i, r + 1) {
			if (A[j] < mn) {
				mn = A[j];
				bmn = B[j];
			}
			if (A[j] > mx) {
				mx = A[j];
				bmx = B[j];
			}
			if (bmn == bmx) {
				res ++;
			}
		}
	}
	return res;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng;
	
	int n;
	cin >> n;
	FOR(i,0,n) {
		cin >> A[i];
		FOR(j,0,63) {
			if (A[i] & (1LL << j))
				++ B[i];
		}
	}
	res = 0;
	solve(0, n - 1);
	cout << res << endl;
	// cout << res << ' ' << brute(0, n - 1) << endl;

	// while (true) {
	// 	int n;
	// 	// cin >> n;
	// 	n = 1000;
	// 	FOR(i,0,n) {
	// 		// cin >> A[i];
	// 		A[i] = rng() % (1LL << 30) + 3;
	// 		B[i] = 0;
	// 		FOR(j,0,K) {
	// 			if (A[i] & (1LL << j))
	// 				++ B[i];
	// 		}
	// 	}
	// 	res = 0;
	// 	solve(0, n - 1);

	// 	cout << res << ' ' << brute(0, n - 1) << endl;
	// 	if (res != brute(0, n - 1)) {
	// 		cout << "FAIL" << endl;
	// 		FOR(i,0,n) {
	// 			cout << A[i] << ' ';
	// 		}
	// 		cout << endl;
	// 		break;
	// 	}
	// }
	

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}