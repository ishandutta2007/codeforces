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
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

string s[55], t[55];

int bad[222][222];
int n;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (s[i][j] == 'o')
		for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) if (s[x][y] == '.') bad[x - i + n][y - j + n] = 1;

	for (int i = 0; i < n; i++) t[i] = s[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (t[i][j] == 'x') t[i][j] = '.';
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (t[i][j] == 'o') for (int x = -(n - 1); x < n; x++) for (int y = -(n - 1); y < n; y++) if (!bad[x + n][y + n]) {
		int xx = i + x;
		int yy = j + y;
		if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;

		if (t[xx][yy] == '.') t[xx][yy] = 'x';
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (t[i][j] != s[i][j]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int x = -(n - 1); x < n; x++) {
		for (int y = -(n - 1); y < n; y++) {
			if (x == 0 && y == 0) putchar('o'); else if (bad[x + n][y + n]) putchar('.'); else putchar('x');
		}
		puts("");
	}		

	return 0;
}