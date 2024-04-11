#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5205;
int charMap[128];
bool a[N][N];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
inline int gcd(int x, int y){
	int t;
	while(y)
		t = x, x = y, y = t % y;
	return x;
}

int main(){
	// freopen("cf1107d.in", "r", stdin);
	// freopen("cf1107d.out", "w", stdout);
	int n, x, ans = 0;
	char ch;
	in(n);
	for(int i='0'; i<='9'; i++) charMap[i] = i - '0';
	for(int i='A'; i<='F'; i++) charMap[i] = i - 'A' + 10;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j+=4){
			while(isspace(ch = getchar()));
			x = charMap[(int)ch];
			a[i][j] = x & 8; a[i][j+1] = x & 4; a[i][j+2] = x & 2; a[i][j+3] = x & 1;
		}
	}
	int len;
	for(int i=1; i<=n; i++){
		len = 1;
		for(int j=2; j<=n; j++){
			if(a[i][j] == a[i][j-1]) ++len;
			else{
				ans = gcd(len, ans);
				if(ans == 1) goto end;
				len = 1;
			}
		}
		ans = gcd(len, ans);
		len = 1;
		for(int j=2; j<=n; j++){
			if(a[j][i] == a[j-1][i]) ++len;
			else{
				ans = gcd(len, ans);
				if(ans == 1) goto end;
				len = 1;
			}
		}
		ans = gcd(len, ans);
	}
	end: printf("%d\n", ans);
	return 0;
}