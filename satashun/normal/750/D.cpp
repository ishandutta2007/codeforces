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

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const int B = 205;

int n;
int t[32];
bool f[410][410];
bool u[32][8][410][410];

int main() {
	cin >> n;
	rep(i, n) cin >> t[i];
	u[0][0][B][B] = 1;

	rep(i, n) {
		rep(j, 8) {
			rep(k, 410) rep(l, 410) {
				if (u[i][j][k][l]) {
					int x = k, y = l;
					rep(m, t[i]) {
						x += dx[j];
						y += dy[j];
						f[x][y] = 1;
					}
					for (int t : {-1, 1}) {
						int dir = (j + t + 8) % 8;
						u[i+1][dir][x][y] = 1;
					}
				}
			}
		}
	}

	int ret = 0;
	rep(i, 410) rep(j, 410) ret += f[i][j];

	cout << ret << endl;

	return 0;
}