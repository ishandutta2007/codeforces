#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define P1 2317
#define P2 999991

#define N 300010
int w[N];
int a[N],n;
int f[N*4],g[N*4];

void upd(int p, int l, int r, int x) {
	if (l == r-1) {
		f[p] = g[p] = 1;
		return;
	}
	int mid = (l+r)/2;
	if (x < mid) upd(p*2+1,l,mid,x);
	else upd(p*2+2,mid,r,x);
	f[p] = ((ll)f[p*2+1]*w[r-mid]+f[p*2+2])%P2;
	g[p] = ((ll)g[p*2+2]*w[mid-l]+g[p*2+1])%P2;
}

int askf(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return f[p];
	int mid = (l+r)/2;
	if (R <= mid) return askf(p*2+1,l,mid,L,R);
	if (L >= mid) return askf(p*2+2,mid,r,L,R);
	int S1 = askf(p*2+1,l,mid,L,R);
	int S2 = askf(p*2+2,mid,r,L,R);
	int rl = min(r,R)-mid;
	return ((ll)S1*w[rl]+S2)%P2;
}

int askg(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return g[p];
	int mid = (l+r)/2;
	if (R <= mid) return askg(p*2+1,l,mid,L,R);
	if (L >= mid) return askg(p*2+2,mid,r,L,R);
	int S1 = askg(p*2+1,l,mid,L,R);
	int S2 = askg(p*2+2,mid,r,L,R);
	int rl = mid-max(l,L);
	return ((ll)S2*w[rl]+S1)%P2;
}

int main()
{
	w[0] = 1;
	for (int i = 1; i < N; i ++)
		w[i] = (ll)w[i-1]*P1%P2;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		a[i] --;
	}
	for (int _i = 0; _i < n; _i ++) {
		int i = a[_i];
		upd(0,0,n,i);
		int le = 0, ri = n;
		if (i-le < ri-i-1) ri = i+(i-le)+1;
		else le = i-(ri-i-1);
		if (le >= i || i+1 >= ri) continue;
		if (askf(0,0,n,le,i) != askg(0,0,n,i+1,ri)) {
			puts ("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}