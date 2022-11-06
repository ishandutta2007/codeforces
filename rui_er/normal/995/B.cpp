// Problem: CF995B Suit and Tie
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF995B
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
const int N = 205;

int n, a[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	n <<= 1;
	rep(i, 1, n) scanf("%d", &a[i]);
	while(n) {
		int pos = 0;
		rep(i, 1, n-1) {
			if(a[i] == a[n]) {
				pos = i;
				break;
			}
		}
		rep(i, pos, n-2) {
			swap(a[i], a[i+1]);
			++ans;
		}
		n -= 2;
	}
	printf("%d\n", ans);
	return 0;
}