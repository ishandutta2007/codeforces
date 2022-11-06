// Problem: D. Guess The String
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforc.es/contest/1697/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n;
char s[N];
map<char, int> lst;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
char ask1(int x) {
	printf("? 1 %d\n", x);
	fflush(stdout);
	char s[3];
	scanf("%s", s);
	return s[0];
}
int ask2(int l, int r) {
	if(l == r) return 1;
	printf("? 2 %d %d\n", l, r);
	fflush(stdout);
	scanf("%d", &l);
	return l;
}
void give(char* s, int n) {
	s[n+1] = '\0';
	printf("! %s\n", s+1);
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	s[1] = ask1(1);
	lst[s[1]] = 1;
	rep(i, 2, n) {
		vector<int> pos;
		for(auto it : lst) pos.push_back(it.second);
		sort(pos.begin(), pos.end());
		int len = pos.size();
		if(ask2(1, i) > len) s[i] = ask1(i);
		else {
			// puts("QWQ");
			int l = 0, r = len;
			while(l < r) {
				int mid = (l + r) >> 1;
				if(ask2(pos[mid]+1, i) == len - mid) r = mid;
				else l = mid + 1;
			}
			s[i] = s[pos[l]];
		}
		lst[s[i]] = i;
	}
	give(s, n);
	// system("pause");
	return 0;
}