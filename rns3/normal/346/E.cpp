#include <bits/stdc++.h>
using namespace std;
#define M 100100
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int ABS(int u) {return u > 0 ? u : -u;}
/**
int work(LL a,LL n,LL p)
{
	LL c=a*n/p;
	if(!c)return max(a,p-a*n);
	if(a*n%p<a*(p/a-1))c--;
	return work(min(a-p%a,p%a),c,a);
}
*/
ll func(ll a, ll n, ll p) {
    if (a * n <= p) {
        return max(a, p - n * a);
    }
    ll m = (p / a);
    //printf("a = %I64d, n = %I64d, p = %I64d\n", a, n, p);
    //printf("%I64d %I64d\n", a * n % p, a * (p/a - 1));
    //printf("%I64d %I64d\n", (a*n+a + (p%a))/p, (a*n/p));
    return func((m + 1) * a - p, (n * a / p) - ((a*n+a+(p%a))/p == (a*n/p)), a);
    return func((m + 1) * a - p, (n * a / p) - (a*n%p<a*(p/a-1)), a);
}

int main() {
    //freopen("E.in", "r", stdin);
    int T;
    ll a, n, p, h;
    for (scanf("%d", &T); T--; ) {
        scanf("%I64d %I64d %I64d %I64d", &a, &n, &p, &h);
        a %= p;
        if (a * n <= p) {
            puts(a > h ? "NO" : "YES");
            continue;
        }
        //printf("%I64d\n", func(a, n, p));
        puts(func(a, n, p) > h ? "NO" : "YES");
    }
    return 0;
}