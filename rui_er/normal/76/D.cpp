//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef unsigned long long ll;

ll a, b, x, y;

int main() {
    scanf("%llu%llu", &a, &b);
    if(a < b || (a - b) & 1) return puts("-1"), 0;
    x = (a - b) / 2; y = a - x;
    printf("%llu %llu\n", x, y);
    return 0;
}