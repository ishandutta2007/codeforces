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

int m;
int cnt;
vi ans;

int main() {
    cin >> m;
    for (int i = 1; ; ++i) {
	int c2 = 0, c5 = 0;
	int t = i;

	while (t > 0) {
	    c2 += t / 2;
	    t /= 2;
	}
	t = i;
	while (t > 0) {
	    c5 += t / 5;
	    t /= 5;
	}

	int num = min(c2, c5);
	if (num > m) break;

	if (num == m) {
	    ++cnt;
	    ans.pb(i);
	}
    }
    cout << cnt << endl;
    rep(i, ans.size()) cout << ans[i] << (i < cnt - 1 ? ' ' : '\n');

    return 0;
}