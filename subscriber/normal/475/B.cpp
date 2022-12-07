#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
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
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, m;
string s1, s2;
int d[22][22];
int q[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int ii = 0; ii < n; ii++) 
				for (int jj = 0; jj < m; jj++) d[ii][jj] = 0;
			int q1 = 0, q2 = 0;
			d[i][j] = 1;
			q[q1++] = i;
			q[q1++] = j;
			while (q1 != q2) {
				int x = q[q2++];
				int y = q[q2++];
				if (s1[x] == '>' && y < m - 1 && d[x][y + 1] == 0) {
					d[x][y + 1] = 1;
					q[q1++] = x;
					q[q1++] = y + 1;
				}
				if (s1[x] == '<' && y > 0 && d[x][y - 1] == 0) {
					d[x][y - 1] = 1;
					q[q1++] = x;
					q[q1++] = y - 1;
				}
				if (s2[y] == 'v' && x < n - 1 && d[x + 1][y] == 0) {
					d[x + 1][y] = 1;
					q[q1++] = x + 1;
					q[q1++] = y;
				}
				if (s2[y] == '^' && x > 0 && d[x - 1][y] == 0) {
					d[x - 1][y] = 1;
					q[q1++] = x - 1;
					q[q1++] = y;
				}
			}
			for (int ii = 0; ii < n; ii++) 
				for (int jj = 0; jj < m; jj++) if (d[ii][jj] == 0) {
					puts("NO");
					return 0;
				}
		}
	}
	puts("YES");
	return 0;
}