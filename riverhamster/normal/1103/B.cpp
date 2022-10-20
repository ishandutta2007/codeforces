#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
char s[50], ts[50];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

bool ask(int x, int y){ //true if greater-equal
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%s", ts);
	if(ts[0] == 'e') exit(0);
	return ts[0] == 'x';
}
void answer(int x){
	printf("! %d\n", x);
	fflush(stdout);
}

int main(){
	// freopen("cf1103b.in", "r", stdin);
	// freopen("cf1103b.out", "w", stdout);
	int l, r, lb, mid, ans;
	while(true){
		scanf("%s", s);
		if(strcmp(s, "start") != 0) return 0;
		if(ask(0, 1)){
			answer(1);
			continue;
		}
		for(l=1, r=2; !ask(l, r); l<<=1, r<<=1);
		lb = l; ++l;
		ans = 0;
		while(l <= r){
			mid = (l + r) >> 1;
			if(ask(lb, mid)){
				ans = mid; r = mid - 1;
			}
			else l = mid + 1;
		}
		answer(ans);
	}
	return 0;
}