#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[505][505];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	int n, ans = 0;
	in(n);
	for(int i=1; i<=n; i++) scanf("%s", s[i] + 1);
	for(int i=2; i<n; i++)
		for(int j=1; j<n; j++)
			if(s[i][j] == 'X' && s[i-1][j-1] == 'X' && s[i+1][j+1] == 'X' && s[i-1][j+1] == 'X' && s[i+1][j-1] == 'X') ++ans;
	printf("%d\n", ans);
	return 0;
}