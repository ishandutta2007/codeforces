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

int main(){
	// File("b");
	int T;
	in(T);
	while(T--){
		int n, r, p, s, cnt = 0;
		in(n); in(r); in(p); in(s);
		static char S[105], res[105];
		scanf("%s", S);
		memset(res, 0, sizeof res);
		for(int i=0; i<n; i++){
			if(S[i] == 'R'){
				if(p) --p, ++cnt, res[i] = 'P';
			}
			else if(S[i] == 'P'){
				if(s) --s, ++cnt, res[i] = 'S';
			}
			else{
				if(r) --r, ++cnt, res[i] = 'R';
			}
		}
		for(int i=0; i<n; i++){
			if(!res[i]){
				if(r) --r, res[i] = 'R';
				else if(p) --p, res[i] = 'P';
				else if(s) --s, res[i] = 'S';
			}
		}
		if(cnt >= (n + 1) / 2){
			puts("YES");
			puts(res);
		}
		else puts("NO");
	}
	return 0;
}