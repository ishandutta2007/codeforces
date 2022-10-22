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
vi res;

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];

    rep(i, n) {
	if (i && __gcd(a[i], a[i-1]) > 1) {
	    res.pb(1);
	}
	res.pb(a[i]);
    }
    cout << (int)res.size() - n << endl;
    rep(i, res.size()) cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    
    return 0;
}