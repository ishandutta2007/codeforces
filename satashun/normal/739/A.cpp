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
int l[100010], r[100010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int w = n;

	rep(i, m) {
		cin >> l[i] >> r[i];
		--l[i]; --r[i];
		w = min(w, r[i]-l[i]+1);
	}

	cout << w << endl;
	rep(i, n) {
		cout << i % w << (i == n - 1 ? '\n' : ' ');
	}

	return 0;
}