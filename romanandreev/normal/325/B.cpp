#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;


#define TASK "a"
ll n;
ld f(ll x) {
	if (x <= 0) return -1;
	ll y = x;
	while (y % 2 == 0) {
		y /= 2;
	}
	return x - y + (ld)y * (y - 1) / 2;
}
vector<ll> ans;
void check(ld x) {
	x = round(x);
	if (x > n + 100) return;
	for (int i = -1000; i <= 1000; i++) {
		if (fabs(f(x + i) - n) < 1e-2) {
			ans.pb(x + i);
		}
	}
}
ll C;
void calc(ld a, ld b, ld c) {	
	ld D = b * b - 4 * a * c;
	ld x1 = (-b - sqrt(fabs(D))) / (2 * a);
	ld x2 = (-b + sqrt(fabs(D))) / (2 * a);	
    check(x1 * (C + 1));
    check(x2 * (C + 1));
}                   
int main()                 
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif    
    cin>>n;
    for (int i = 0; i <= 60; i++) {
    	C = (1LL << i) - 1;
    	calc(1, 2 * C - 1, -2 * n);
    }
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    if (sz(ans) == 0) {
    	printf("-1\n");
    } else {
    	for (int i = 0; i < sz(ans); i++) {
    		cout<<ans[i]<<endl;
    	}
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}