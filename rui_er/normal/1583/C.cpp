//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, m, q, c[N], p[N];
vector<int> a[N];
string s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		cin>>s[i];
		s[i] = " " + s[i];
	}
	rep(j, 1, m-1) {
		rep(i, 1, n-1) {
			if(s[i][j+1] == 'X' && s[i+1][j] == 'X') {
				c[j] = 1;
				break;
			}
		}
	}
	rep(j, 1, m) p[j] = p[j-1] + c[j];
	for(scanf("%d", &q);q;q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		int now = p[y-1] - p[x-1];
		puts(now?"NO":"YES");
	}
	return 0;
}