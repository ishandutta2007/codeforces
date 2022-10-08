#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define GN(x) cin >> x

struct P {
  int x, y;
  P(){}
  P(int _x, int _y):x(_x), y(_y) {}
  P operator + (const P&a) const {return P(x+a.x, y+a.y);}
  P operator - (const P&a) const {return P(x-a.x, y-a.y);}
  ll dot (const P&a) const {return (ll)x*a.x + (ll)y*a.y;}
  ll crs (const P&a) const {return (ll)x*a.y - (ll)y*a.x;}
  P rot90 () const {return P(-y,x);} 
  bool operator < (const P&a) const {
  return x < a.x || x == a.x && y < a.y;
  }
  bool upper () const {return y > 0 || y == 0 && x > 0;}
  void get() {GN(x); GN(y);}
  void out() {printf ("%d %d\n", x, y);}
};

#define N 310
int n; P a[N];
bitset<N> b[N][N];
int s[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) a[i].get();
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			for (int k = 0; k < n; k ++)
				if ((a[j]-a[i]).crs(a[k]-a[i]) > 0) b[i][j][k] = 1;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			for (int k = 0; k < n; k ++)
				if ((a[j]-a[i]).crs(a[k]-a[i]) > 0) {
					s[(b[i][j] & b[j][k] & b[k][i]).count()] ++;
				}
	for (int i = 0; i < n; i ++) s[i] /= 3;
	ll S = (ll)n*(n-1)*(n-2)*(n-3)*(n-4)/120;
	ll T = 0;
	for (int i = 0; i < n; i ++) T += (ll) s[i] * i * (n-4);
	S -= T/2;
	for (int i = 0; i < n; i ++) S += (ll) s[i] * i * (i-1)/2;
	cout << S << endl;
	return 0;
}