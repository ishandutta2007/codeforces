// Codeforces contest template
#include <bits/stdc++.h>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
	char ch; x = 0;int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> inline void wi(T x){
	static char stk[128]; int top = 0;
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	while(x) stk[++top] = x % 10, x /= 10;
	while(top) putchar(stk[top--] + '0');
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

int main(){
	// File("b");
	int T;
	gi(T);
	while(T--){
		int n, m;
		gi(n); gi(m);
		static int a[305][305], res[305][305];
		for(int i=1; i<=m; i++) res[1][i] = res[n][i] = 3;
		for(int i=1; i<=n; i++) res[i][1] = res[i][m] = 3;
		res[1][1] = res[n][1] = res[1][m] = res[n][m] = 2;
		for(int i=2; i<n; i++)
			for(int j=2; j<m; j++)
				res[i][j] = 4;
		bool flag = true;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++){
				gi(a[i][j]);
				if(a[i][j] > res[i][j]){
					if(flag) puts("NO");
					flag = false;
				}
			}
		if(!flag) continue;
		puts("YES");
		// printf("m = %d\n", m);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++) wi(res[i][j]), SP;
			EL;
		}
	}
	return 0;
}