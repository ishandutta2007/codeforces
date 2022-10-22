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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int h, w;
string s[60];
int gx, gy;
int sx, sy;
int pe[4];
string com;

bool safe(int a, int b)
{
	return a >= 0 && a < h && b >= 0 && b < w && s[a][b] != '#';
}

int main() {
	cin >> h >> w;

	rep(i, h) {
		cin >> s[i];
		rep(j, w) {
			if (s[i][j] == 'S') {
				sx = i, sy = j;
				s[i][j] = '.';
			}
			if (s[i][j] == 'E') {
				gx = i, gy = j;
				s[i][j] = '.';				
			}
		}
	}
	cin >> com;

	rep(i, 4) {
		pe[i] = i;
	}

	int ret = 0;
	do {

		int p = sx, q = sy;

		bool ok = 0;
		rep(j, com.size()) {
			int t = com[j] - '0';
			int np = p + dx[pe[t]], nq = q + dy[pe[t]];
			if (safe(np, nq)) {
				p = np, q = nq;
			} else {
				break;
			}
			if (p == gx && q == gy) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			++ret;
		}
	} while (next_permutation(pe, pe + 4));

	cout << ret << endl;

	return 0;
}