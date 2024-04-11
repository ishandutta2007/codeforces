//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e3+5;

int n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d", &a[i]);
	sort(a+1, a+1+m);
	if(a[1] == 1 || a[m] == n) return puts("NO") & 0;
	rep(i, 1, m-2) if(a[i] == a[i+1] - 1 && a[i+1] == a[i+2] - 1) return puts("NO") & 0;
	puts("YES");
	return 0;
}