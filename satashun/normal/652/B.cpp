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
int a[1010];
int l, r;

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    sort(a, a + n);

    r = n - 1;

    vi ans;
    rep(i, n) {
	if (i & 1) ans.pb(a[r--]);
	else ans.pb(a[l++]);
    }

    rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    
    return 0;
}