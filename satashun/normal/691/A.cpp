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
int cnt;

int main() {
    cin >> n;
    rep(i, n) {
	int x;
	cin >> x;
	cnt += x;
    }

    bool ok;
    if (n > 1) {
	ok = (cnt == n - 1);
    } else ok = (cnt == 1);
    puts(ok ? "YES" : "NO");
    return 0;
}