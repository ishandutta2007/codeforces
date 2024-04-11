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
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
ll m;
ll ans = 9e18;
void calc(ll x, ll y, ll d) {
    if (x > y) swap(x, y);
    if (d >= ans) return;
    if (y >= m) {
        ans = d;
        return;
    }  
    if (x > 0) {
        calc(y, x + y, d + 1);
    }
    if (x <= 0 && y > 0) {
        ll cc = (-x / y) + 1;
        calc(y, x + cc * y, d + cc);
    } 
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    ll x, y;
    cin>>x>>y>>m;
    calc(x, y, 0);
    if (ans > 8e18) 
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}