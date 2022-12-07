#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;

pair<pair<int, int>, pair<int, long long> > q[2000222];
int k;

int A[55][3];
int nt[55];
int h;
int ans;

void gen(int x, int s1, int s2, int s3, long long mask) {
	if (x == h) {
		q[k++] = mp(mp(s2 - s1, s3 - s1), mp(-s1, mask));
		return;
	}
	for (int i = 0; i < 3; i++) {
		int ss1 = s1;
		int ss2 = s2;
		int ss3 = s3;
		if (i != 0) ss1 += A[x][0];
		if (i != 1) ss2 += A[x][1];
		if (i != 2) ss3 += A[x][2];
		gen(x + 1, ss1, ss2, ss3, mask * 4 + (i + 1)); 
	}
}

void gen2(int x, int s1, int s2, int s3, long long mask) {
	if (x == n) {
		pair<int, int> need = mp(-(s2 - s1), -(s3 - s1));
		int g = lower_bound(q, q + k, mp(need, mp((int) -1e9, 0ll))) - q;
		if (g >= k || q[g].F != need) return;

		int val = s1 - q[g].S.F;
		if (val > ans) {
			ans = val;
			long long t = q[g].S.S;
			for (int i = h - 1; i >= 0; i--) {
				nt[i] = (t & 3) - 1;
				t >>= 2;
			}
			t = mask;
			for (int i = n - 1; i >= h; i--) {
				nt[i] = (t & 3) - 1;
				t >>= 2;
			}
		}
		return;

	}
	for (int i = 0; i < 3; i++) {
		int ss1 = s1;
		int ss2 = s2;
		int ss3 = s3;
		if (i != 0) ss1 += A[x][0];
		if (i != 1) ss2 += A[x][1];
		if (i != 2) ss3 += A[x][2];
		gen2(x + 1, ss1, ss2, ss3, mask * 4 + (i + 1)); 
	}
}


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) cin >> A[i][j];

	ans = -1e9;
	h = n / 2;
	gen(0, 0, 0, 0, 0);
	sort(q, q + k);
	gen2(h, 0, 0, 0, 0);
	if (ans == -1e9) {
		puts("Impossible");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (nt[i] != 0) putchar('L');
		if (nt[i] != 1) putchar('M');
		if (nt[i] != 2) putchar('W');
		puts("");
	}
	return 0;
}