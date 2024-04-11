#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[100005];
bool vis[100005];
// int nxt[100005];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int main(){
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	scanf("%s", s);
	int n = strlen(s), last, l, r;
	int cnt = 0;
	// for(int i=0; i<n; i++) next[i] = i + 1;
	bool flag = true;
	while(flag){
		flag = false; last = -1;
		for(int i=0; i<n; i++){
			if(vis[i]) continue;
			if(last == -1){
				last = i; continue;
			}
			l = last; r = i;
			while(s[l] == s[r] && !vis[l] && !vis[r] && l>=0 && r<n){
				// printf("l = %d r = %d\n", l, r);
				vis[l] = vis[r] = true;
				l--; r++;
				++cnt;
				flag = true;
			}
			last = i;
		}
	}
	// printf("cnt = %d\n", cnt);
	if(cnt & 1) puts("Yes");
	else puts("No");
	return 0;
}