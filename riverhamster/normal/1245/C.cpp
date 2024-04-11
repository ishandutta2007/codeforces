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

const int N = 100005, mod = 1000000007;
char s[N];
int f[N];

int main(){
	// File("c");
	scanf("%s", s);
	int n = strlen(s);
	for(int i=0; i<n; i++){
		if(s[i] == 'm' || s[i] == 'w'){
			puts("0");
			return 0;
		}
	}
	f[0] = 1;
	f[1] = ((s[0] == 'u' && s[1] == 'u') || (s[0] == 'n' && s[1] == 'n')) ? 2 : 1;
	for(int i=2; i<n; i++){
		f[i] = f[i-1];
		// printf("%c %c\n", s[i], s[i-1]);
		if((s[i] == 'u' && s[i-1] == 'u') || (s[i] == 'n' && s[i-1] == 'n')) f[i] = (f[i] + f[i-2]) % mod;
		// printf("f[%d] = %d\n", i, f[i]);
	}
	printf("%d\n", f[n-1]);
	return 0;
}