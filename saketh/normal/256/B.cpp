#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}


ll N, X, Y, C;

ll past_wall(ll x, ll t){
    if(t < x) return 0;
    return (t-x+1) * (t-x+1);
}

ll past_corner(ll x, ll y, ll t){
    if(t - x - y < 0) return 0;
    return (t-x-y+1)*(t-x-y+2)/2;
}

bool fill(ll t){
    ll ans = 1 + t * (t+1) * 2;
    ans -= past_wall(X, t);
    ans -= past_wall(Y, t);
    ans -= past_wall(N+1-X, t);
    ans -= past_wall(N+1-Y, t);
    ans += past_corner(X, Y, t);
    ans += past_corner(N+1-X, Y, t);
    ans += past_corner(X, N+1-Y, t);
    ans += past_corner(N+1-X, N+1-Y, t);
    return ans >= C;
}

int main(){
    setup();
    cin >> N >> X >> Y >> C;

    ll ans = 1e9;
    ll lo = 0, hi = 1e9; 
    while( lo <= hi ){
        ll mi = (lo + hi) / 2;
        if(!fill(mi)){
            lo = mi + 1;
        }
        else{
            ans = mi;
            hi = mi - 1;
        }
    }

    cout << ans << endl;
}