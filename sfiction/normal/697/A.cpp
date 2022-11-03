#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

int main(){
	int t, s, x;
	scanf("%d%d%d", &t, &s, &x);
	x -= t;
	puts(0 <= x && x != 1 && x % s <= 1 ? "YES" : "NO");
	return 0;
}