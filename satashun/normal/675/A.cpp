#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const string ye = "YES";
const string no = "NO";

int a, b, c;

int main() {
    cin >> a >> b >> c;

    if (c == 0) {
	if (a == b) cout << ye << endl;
	else cout << no << endl;
    } else {
	int t = (b - a) / c;
	if (t >= 0 && a + t * c == b) cout << ye << endl;
	else cout << no << endl;
    }

    return 0;
}