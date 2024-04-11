// Problem: CF264A Escape from Stones
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF264A
// Memory Limit: 250 MB
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
const int N = 1e6+5;

int n;
char s[N];
deque<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	per(i, n, 1) {
		if(s[i] == 'l') ans.push_back(i);
		else ans.push_front(i);
	}
	while(!ans.empty()) {
		printf("%d\n", ans.front());
		ans.pop_front();
	}
	return 0;
}