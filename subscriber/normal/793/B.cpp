#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;


int xi[4] = {-1, 0, 1, 0};
int yi[4] = {0, 1, 0, -1};

bool d[1011][1011][4][3];

string fi[1011];
int n, m;

short q[55000111];
int q1, q2;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> fi[i];

	int x, y;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (fi[i][j] == 'S') {
		x = i;
		y = j;
	}
	for (int i = 0; i < 4; i++) {
		d[x][y][i][0] = 1;
		q[q1++] = x;
		q[q1++] = y;
		q[q1++] = i;
		q[q1++] = 0;
	}
//	cout << sizeof(q[0]) << endl;
	while (q1 != q2) {
		int x = q[q2++];
		int y = q[q2++];
		int di = q[q2++];
		int o = q[q2++];
		if (fi[x][y] == 'T') {
			cout << "YES" << endl;
			return 0;
		}

		{
			int xx = x + xi[di];
			int yy = y + yi[di];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && fi[xx][yy] != '*') {
				if (d[xx][yy][di][o] == 0) {
					d[xx][yy][di][o] = 1;
					q[q1++] = xx;
					q[q1++] = yy;
					q[q1++] = di;
					q[q1++] = o;
				}
			}
			if (o < 2) for (int i = 0; i < 4; i++) if (d[x][y][i][o + 1] == 0) {
				d[x][y][i][o + 1] = 1;
				q[q1++] = x;
				q[q1++] = y;
				q[q1++] = i;
				q[q1++] = o + 1;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}