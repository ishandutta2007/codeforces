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
char s1[N], s2[N], res[N];

int main(){
	// File("e");
	int n, n2;
	scanf("%s", s1+1);
	n = strlen(s1+1);
	n2 = n/2;
	if(n <= 3){
		printf("%c\n", s1[1]);
		return 0;
	}
	for(int i=1; i<=n2; i++)
		s2[i] = s1[n-i+1];
	for(int i=1; i+1<=n2; i+=2){
		if(s1[i] == s2[i] || s1[i] == s2[i+1]) res[(i+1)/2] = s1[i];
		else if(s1[i+1] == s2[i] || s1[i+1] == s2[i+1]) res[(i+1)/2] = s1[i+1];
	}
	for(int i=1; i<=n2/2; i++) putchar(res[i]);
	if(n2 & 1) putchar(s1[n2 + 1]);
	for(int i=n2/2; i>=1; i--) putchar(res[i]);
	putchar('\n');
	return 0;
}