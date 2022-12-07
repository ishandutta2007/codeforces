// LUOGU_RID: 95054395
// Problem: B. William the Vigilant
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/B
// Memory Limit: 256 MB
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
const int N = 1e5+5;

int n, m;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%s", &n, &m, s+1);
	int cnt = 0;
	rep(i, 1, n-2) {
		if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') ++cnt;
	}
	while(m--) {
		int i; char c[2];
		scanf("%d%s", &i, c);
		if(i >= 1 && s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') --cnt;
		if(i >= 2 && s[i-1] == 'a' && s[i] == 'b' && s[i+1] == 'c') --cnt;
		if(i >= 3 && s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c') --cnt;
		s[i] = c[0];
		if(i >= 1 && s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') ++cnt;
		if(i >= 2 && s[i-1] == 'a' && s[i] == 'b' && s[i+1] == 'c') ++cnt;
		if(i >= 3 && s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c') ++cnt;
		printf("%d\n", cnt);
	}
	return 0;
}