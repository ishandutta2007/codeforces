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
bool a[1010];

int main() {
    cin >> n;
    rep(i, n) {
	int x;
	cin >> x;
	a[x] = 1;
    }

    for (int i = 1; i <= 1000; ++i) {
	if (a[i] && a[i + 1] && a[i + 2]) {
	    puts("YES");
	    return 0;
	}
    }
    puts("NO");
    return 0;
}