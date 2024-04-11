#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pnt;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())

int n;
ll l, t;
ll a[5000000];
int main() {
	#ifdef home
    	freopen("a.in", "r", stdin);
	    freopen("a.out", "w", stdout);
	#endif
    scanf("%d %I64d %I64d", &n, &l, &t);
    for (int i = 0; i < n; i++) {
    	scanf("%I64d", &a[i]);
    	a[i + n] = a[i] + l;
    	a[i + 2 * n] = a[i] + l * 2;
    }
    a[3 * n] = 1e18;
    ll k = t / l;
    t = t % l; 
    int yk = 0;
    ld ans = 0;
    for (int i = 0; i < n; i++) {
    	while (yk < i + 2 * n && a[yk + 1] - a[i] <= 2 * t) {
    		yk++;
    	}
    	ans = ans + (ll)k * ((n - 1)) + (yk - i - (yk >= i + n ? 1 : 0)) * 0.5;
    }
    printf("%.18lf\n", (double)ans / 2);
	return 0;
}