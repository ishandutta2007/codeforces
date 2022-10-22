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
#define dump(x) cout << #x << " = " << (x) << endl

int main() {
	int b, k; cin >> b >> k;
	vi a(k);
	rep(i, k) cin >> a[i];
	reverse(ALL(a));
	int s = 0;
	int u = 1;
	rep(i, k) {
		s += u * a[i] % 2;
		u = u * b % 2;
		s %= 2;
	}
	puts(s ? "odd" : "even");
	return 0;
}