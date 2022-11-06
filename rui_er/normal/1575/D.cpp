// Problem: CF1575D Divisible by Twenty-Five
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1575D
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int n;
char s[10];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(int val) {
	int x = -1;
	per(i, n, 1) {
		int u = val % 10;
		val /= 10;
		if(isdigit(s[i]) && s[i] - '0' != u) return 0;
		if(s[i] == 'X') {
			if(x == -1) x = u;
			else if(x != u) return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	if(n == 1) return puts(s[1]=='_'||s[1]=='X'||s[1]=='0'?"1":"0")&0;
	int k = 1, ans = 0;
	rep(i, 2, n) k *= 10;
	for(int i=k+(25-k%25)%25;i<k*10;i+=25) ans += check(i);
	printf("%d\n", ans);
	return 0;
}