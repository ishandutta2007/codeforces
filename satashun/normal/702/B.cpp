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
int a[100010];
map<int, int> T;
ll ret;

int main() {
    cin >> n;

    rep(i, n) {
	cin >> a[i];
	++T[a[i]];
    }

    for (int i = 1; i <= 30; ++i) {
	int x = 1 << i;

	rep(j, n) {
	    --T[a[j]];
	    int val = x - a[j];
	    if (T.count(val) && T[val] > 0) ret += T[val];
	    ++T[a[j]];
	}
    }

    cout << ret / 2 << endl;

    return 0;
}