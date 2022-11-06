// Problem: CF5C Longest Regular Bracket Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF5C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, a[N];
char s[N];
stack<int> st;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	rep(i, 1, n) {
		if(s[i] == '(') st.push(i);
		else if(!st.empty()) {
			a[i] = a[st.top()] = 1;
			st.pop();
		}
	}
	int len = 0, cnt = 1, now = 0;
	rep(i, 1, n) {
		if(a[i]) {
			++now;
			if(now > len) len = now, cnt = 1;
			else if(now == len) ++cnt;
		}
		else now = 0;
	}
	printf("%d %d\n", len, cnt);
	return 0;
}