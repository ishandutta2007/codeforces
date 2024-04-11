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
int a[32];
int cnt_odd;
int cent;
int sum;
string ans;

int main() {
    cin >> n;

    rep(i, n) {
	cin >> a[i];
	sum += a[i];
	if (a[i] & 1) {
	    cnt_odd++;
	    cent = i;
	}
    }

    if (cnt_odd > 1) {
	puts("0");
	rep(i, n) rep(j, a[i]) ans.pb('a' + i);
    } else if (cnt_odd == 1) {
	int num = a[0];
	for (int i = 1; i < n; ++i) num = __gcd(num, a[i]);

	rep(i, n) a[i] /= num;

	cout << num << endl;

	string block;

	block.resize(sum / num);

	block[sum / num / 2] = 'a' + cent;

	int now = 0;
	rep(i, n) rep(j, a[i] / 2) {
	    block[now] = block[sum / num - 1 - now] = 'a' + i;
	    ++now;
	}

	rep(i, num) ans += block;
    } else {
	int num = a[0];
	for (int i = 1; i < n; ++i) num = __gcd(num, a[i]);

	cout << num << endl;
	string block[2];
	rep(i, n) rep(j, a[i] / num) block[0].pb('a' + i);
	block[1] = block[0];
	reverse(ALL(block[1]));

	rep(i, num) ans += block[i & 1];
    }

    cout << ans << endl;

    return 0;
}