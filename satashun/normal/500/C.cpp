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

int n, m;
int w[510];
int ret;
int la[510];
int c[1010];

int main() {
	cin >> n >> m;
	rep(i, n) cin >> w[i];
	rep(i, 510) la[i] = -1;

	rep(i, m) {
		int v;
		cin >> v;
		--v;
		c[i] = v;

		rep(j, n) {
			if (la[j] > la[v]) {
				ret += w[j];
			}
		}

		la[v] = i;
	}

	cout << ret << endl;
	return 0;
}