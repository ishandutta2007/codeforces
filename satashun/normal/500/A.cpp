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

int n, t;
int to[30010];
bool r[30010];

int main() {
	cin >> n >> t;
	--t;
	r[0] = 1;

	rep(i, n-1) {
		cin >> to[i];
		r[i+to[i]] |= r[i];
	}
	puts(r[t]?"YES":"NO");
	return 0;
}