//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int x, y, a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int calc(int k) {
	int lcm = x / __gcd(x, y) * y;
	return k / lcm;
}

int main() {
	scanf("%d%d%d%d", &x, &y, &a, &b);
	printf("%d\n", calc(b)-calc(a-1));
	return 0;
}