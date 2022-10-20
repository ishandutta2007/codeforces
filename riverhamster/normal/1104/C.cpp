#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[1005];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("c.in", "r", stdin);
	// freopen("c.out", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	bool h1 = false, s1 = false;
	for(int i=0; i<n; i++){
		if(s[i] == '0'){ // --
			if(!h1) h1 = true, puts("1 4");
			else h1 = false, puts("3 4");
		}
		else{
			if(!s1) s1 = true, puts("4 1");
			else s1 = false, puts("4 3");
		}
	}
	return 0;
}