#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 1000005;
char s[N], ss[N];
ll sum[N];

int main(){
	// File("b");
	scanf("%s", s+1);
	int n = strlen(s+1), l = 0;
	ll res = 0;
	for(int i=1; i<=n; i++){
		if(s[i] == 'o') ss[++l] = 'o';
		else if(i >= 1 && s[i] == 'v' && s[i-1] == 'v') ss[++l] = 'w';
	}
	for(int i=1; i<=l; i++)
		sum[i] = sum[i-1] + (int)(ss[i] == 'w');
	// for(int i=1; i<=l; i++)
		// printf("sum[%d] = %lld\n", i, sum[i]);
	for(int i=1; i<=l; i++)
		if(ss[i] == 'o')
			res += sum[i-1] * (sum[l] - sum[i]);
	printf("%lld\n", res);
	return 0;
}