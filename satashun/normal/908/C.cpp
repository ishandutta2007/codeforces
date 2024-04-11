#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

typedef double R;

int n, r;
int x[1010];
R c[1010];

int main() {
	cin >> n >> r;
	rep(i, n) cin >> x[i];

	rep(i, n) {
		R mx = r;

		rep(j, i) {
			if (x[j] == x[i] - r * 2) {
				mx = max(mx, c[j]);
			} else if (x[j] == x[i] + r * 2) {
				mx = max(mx, c[j]);				
			} else if (x[j] <= x[i] && x[j] > x[i] - r * 2) {
				R t = sqrt(r * r * 4 - (x[i] - x[j]) * (x[i] - x[j])) + c[j];
				mx = max(mx, t);
			} else if (x[j] >= x[i] && x[j] < x[i] + r * 2) {
				R t = sqrt(r * r * 4 - (x[i] - x[j]) * (x[i] - x[j])) + c[j];
				mx = max(mx, t);
			}
		}

		c[i] = mx;
	}

	rep(i, n) printf("%.8f%c", c[i], i == n - 1 ? '\n' : ' ');
	
	return 0;
}