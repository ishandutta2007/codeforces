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

int h, w, q;
string s[510];
int tat[510][510], yok[510][510];

int main() {
    ios::sync_with_stdio(false);
    cin >> h >> w;
    rep(i, h) cin >> s[i];
    rep(i, h) {
	rep(j, w - 1) if (s[i][j] == '.' && s[i][j+1] == '.') {
	    yok[i][j+1] = 1;
	}
	rep(j, w-1) yok[i][j+1] += yok[i][j];
    }

    rep(i, w) {
	rep(j, h - 1) if (s[j+1][i] == '.' && s[j][i] == '.') {
	    tat[i][j+1] = 1;
	}
	rep(j, h-1) tat[i][j+1] += tat[i][j];
    }

    cin >> q;
    rep(i, q) {
	int ret = 0;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	--c1;--r1;--r2;--c2;
	for (int i = r1; i <= r2; ++i) {
	    ret += yok[i][c2] - yok[i][c1];
	}
	for (int i = c1; i <= c2; ++i) {
	    ret += tat[i][r2] - tat[i][r1];
	}
	cout << ret << "\n";
    }
    return 0;
}