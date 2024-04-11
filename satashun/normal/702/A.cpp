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
int ret;

int main() {
    cin >> n;
    int prv = -1;
    int l = 0;

    rep(i, n) {
	int x;
	cin >> x;
	if (x > prv) {
	    ++l;
	} else {
	    l = 1;
	}
	prv = x;

	ret = max(ret, l);
    }

    cout << ret << endl;

    return 0;
}