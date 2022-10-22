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

int mn[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    string c, b;
    int a;
    cin >> a >> b >> c;
    if (c == "week") {
	a %= 7;
	int cnt = 0, cur = 5;
	rep(i, 12) {
	    rep(j, mn[i]) {
		if (cur == a) ++cnt;
		cur = (cur + 1) % 7;
	    }
	}
	cout << cnt << endl;
    } else {
	int cnt = 0;
	rep(i, 12) if (a <= mn[i]) ++cnt;
	cout << cnt << endl;
    }
    return 0;
}