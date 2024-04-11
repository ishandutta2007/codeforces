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

int n;
ll k;
int a[100010];
ll s[100010];
ll ret;

int main() {
	cin >> n >> k;

	rep(i, n) {
		scanf("%d", &a[i]);
		s[i+1] = s[i] + a[i];
	}

	map<ll, int> M;
	M[0] = 1;

	rep(i, n) {
		set<ll> us;
		ll t = 1;
		ll num = s[i+1];

		while (true) {
			if (us.count(t)) {
				break;
			}

			if (abs(t) > 1e15) {
				break;
			}

			if (M.count(num - t)) {
				ret += M[num - t];
			}

			us.insert(t);
			t = t * k;
		}

		M[s[i+1]]++;
	}

	cout << ret << endl;

	return 0;
}