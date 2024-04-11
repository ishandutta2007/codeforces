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

int n, k;
int ans;
int c;

int main() {
	cin >> n >> k;
	k = 240 - k;
	for (int i = 1; i <= n; ++i) {
		if (c + i * 5 <= k) {
			c += i * 5;
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}