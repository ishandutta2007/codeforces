#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

const int N = 150005;
char s[N], a[N];
int f[N][6][6], prej[N][6][6], prek[N][6][6];

void up(int ni, int nj, int nk, int i, int j, int k, int val){
	if(f[ni][nj][nk] > val){
		f[ni][nj][nk] = val;
		prej[ni][nj][nk] = j; prek[ni][nj][nk] = k;
	}
}

int main(){
	// File("a");
	int T;
	in(T);
	while(T--){
		scanf("%s", s+1);
		int n = strlen(s+1);
		for(int i=1; i<=n; i++){
			if(s[i] == 'o') a[i] = 1;
			else if(s[i] == 'n') a[i] = 2;
			else if(s[i] == 'e') a[i] = 3;
			else if(s[i] == 't') a[i] = 4;
			else if(s[i] == 'w') a[i] = 5;
			else a[i] = 0;
		}
		// memset(f, 0x3f, sizeof(f));
		for(int i=0; i<=n; i++)
			for(int j=0; j<=5; j++)
				for(int k=0; k<=5; k++)
					f[i][j][k] = 0x3f3f3f3f;
		f[0][0][0] = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<=5; j++)
				for(int k=0; k<=5; k++){
					if(f[i][j][k] == 0x3f3f3f3f) continue;
					// f[i+1][j][k] = min(f[i+1][j][k], f[i][j][k] + 1);
					up(i+1, j, k, i, j, k, f[i][j][k] + 1);
					if(!(j == 1 && k == 2 && a[i+1] == 3) && !(j == 4 && k == 5 && a[i+1] == 1))
						up(i+1, k, a[i+1], i, j, k, f[i][j][k]);
						// f[i+1][k][a[i+1]] = min(f[i+1][k][a[i+1]], f[i][j][k]);
				}
		int res = 0x3f3f3f3f;
		int ti = 0, tj = 0;
		for(int i=0; i<=5; i++)
			for(int j=0; j<=5; j++)
				if(f[n][i][j] < res) res = f[n][i][j], ti = i, tj = j;
				// res = min(res, f[n][i][j]);
		printf("%d\n", res);
		static int stk[N];
		int top = 0;
		for(int i=n; i>=1; i--){
			int pi = prej[i][ti][tj], pj = prek[i][ti][tj];
			if(f[i][ti][tj] == f[i-1][pi][pj] + 1) stk[++top] = i;
			ti = pi; tj = pj;
		}
		while(top) printf("%d ", stk[top--]);
		putchar('\n');
	}
	return 0;
}