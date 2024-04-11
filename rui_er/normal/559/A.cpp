//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int a, b, c, d, e, f;
int calc() {
	int x = a + b + c;
	return x * x - a * a - c * c - e * e;
}

int main() {
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	printf("%d\n", calc());
	return 0;
}