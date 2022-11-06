// Problem: CF1157C1 Increasing Subsequence (easy version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1157C1
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N = 2e5+5;

int n, a[N];
vector<int> ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	int L = 1, R = n, lst = -1;
	rep(i, 1, n) {
		if(a[L] > lst && a[R] > lst) {
			if(a[L] < a[R]) {
				ans.push_back('L');
				lst = a[L++];
			}
			else {
				ans.push_back('R');
				lst = a[R--];
			}
		}
		else if(a[L] > lst) {
			ans.push_back('L');
			lst = a[L++];
		}
		else if(a[R] > lst) {
			ans.push_back('R');
			lst = a[R--];
		}
		else break;
	}
	printf("%d\n", (int)ans.size());
	for(auto i : ans) putchar(i);
	return 0;
}