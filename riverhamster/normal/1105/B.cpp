#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[200005];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

int n, k;
int cal(char c){
	int l = 0, ans = 0;
	for(int i=0; i<n; i++){
		if(s[i] == c) ++l;
		else l = 0;
		if(l == k) ++ans, l = 0;
	}
	return ans;
}

int main(){
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	in(n); in(k);
	int ans = 0;
	scanf("%s", s);
	for(char i='a'; i<='z'; i++)
		ans = max(ans, cal(i));
	printf("%d\n", ans);
	return 0;
}