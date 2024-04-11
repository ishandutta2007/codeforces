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
ll a, b, T;
string s;
int ret;
ll acc[500010];
vector<ll> tm;

int main() {
    cin >> n >> a >> b >> T >> s;

    rep(tt, 2) {
	rep(i, n) acc[i + 1] = acc[i] + (s[i] == 'w' ? b : 0);
	
	vector<ll> vt;
	vt.clear();

	vt.pb(0);
	for (int i = n - 1; i >= 0; --i) vt.pb(vt.back() + (s[i] == 'w' ? b : 0) + a + 1);

	rep(i, n) { //first:[0, i]
	    ll cur = i + 1 + acc[i + 1] + a * i;
	    if (cur > T) continue;
	    ret = max(ret, i + 1);
	    ll zan = T - cur - a * i;
	    if (zan < 0) continue;
	    int can = upper_bound(ALL(vt), zan) - vt.begin() - 1;
	    ret = max(ret, min(i + 1 + can, n));
	}

	string t;
	t.pb(s[0]);
	for (int i = n - 1; i >= 1; --i) t.pb(s[i]);

	s = t;
    }

    cout << ret << endl;

    return 0;
}