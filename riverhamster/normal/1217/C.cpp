#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) stdin = freopen(s".in", "r", stdin), stdout = freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 200005;
char s[N];
int pre0[N];

int main(){
	// File("c");
	int T;
	in(T);
	while(T--){
		scanf("%s", s+1);
		int n = strlen(s+1);
		s[0] = '1';
		for(int i=1; i<=n; i++)
			if(s[i-1] == '1') pre0[i] = 1;
			else pre0[i] = pre0[i-1] + 1;
		ll res = 0;
		for(int i=1; i<=n; i++){
			int num = 0;
			for(int j=i; j>=1; j--){
				num += (s[j] - '0') << (i - j);
				if(num > i || (1 << (i - j)) > i) break;
				// printf("i = %d num = %d\n", i, num);
				if(s[j] == '1' && num != 0 && i - num + 1 >= j - pre0[j] + 1) ++res;//, printf("Found i %d num %d\n", i, num);
				// printf("tried %d\n", j);
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}