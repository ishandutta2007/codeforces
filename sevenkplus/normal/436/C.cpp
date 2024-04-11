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

#define N 1010
string s[N];
int c,r,n,w,sz;
int px[N*N],py[N*N],pz[N*N],p[N*N],L,f[N];

bool cmp(int x, int y){return pz[x] < pz[y];}
int ff(int x) {return f[x] == x? x:(f[x]=ff(f[x]));}

int he[N],ad[N*2],ne[N*2],di[N*2];
void addE(int x, int y, int z) {
	static int t = 0;
	++ t, ne[t] = he[x], he[x] = t, ad[t] = y, di[t] = z;
	++ t, ne[t] = he[y], he[y] = t, ad[t] = x, di[t] = z;
}

void ff(int x, int y, bool z) {
	if (!z) {printf ("%d %d\n",x+1,0);}
	else {printf ("%d %d\n",x+1,y+1);}
	for (int p = he[x]; p; p = ne[p])
		if (ad[p] != y) {
			ff(ad[p],x,di[p] <= sz);
		}
}

int main()
{
	cin >> c >> r >> n >> w;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < c; j ++) {
			string t; cin >> t;
			s[i] += t;
		}
	}
	sz = c*r;
	for (int i = 0; i < n; i ++) 
		for (int j = i+1; j < n; j ++) {
			int S = 0;
			for (int k = 0; k < sz; k ++) 
				S += (s[i][k] != s[j][k]);
			px[L] = i;
			py[L] = j;
			pz[L] = S;
			p[L] = L;
			L ++;
		}
	sort(p,p+L,cmp);
	for (int i = 0; i < n; i ++) f[i] = i;
	int S = sz;
	for (int _i = 0; _i < L; _i ++) {
		int i = p[_i];
		if (ff(px[i]) != ff(py[i])) {
			addE(px[i],py[i],pz[i]*w);
			if (pz[i]*w > sz) S += sz; else S += pz[i]*w;
			f[ff(px[i])] = ff(py[i]);
		}
	}
	printf ("%d\n",S);
	ff(0,-1,0);
	return 0;
}