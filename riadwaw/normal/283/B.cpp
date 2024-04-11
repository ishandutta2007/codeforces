#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <cassert>
#include <list>
//#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    clock_t start = clock();
#else
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}
li n;
li dp[202020][2];
li  a[202020];
li ans(li x, bool step){
    
    li& res = dp[x][step];
    for(int i = 0; i <=3 ;++i){
        //cout << "i =" <<i << ' ' <<dp[i][0] <<' '<< dp[i][1] << endl;
    }
    if(res == -2){
        res = -1;
        return res;
    }
    if(res != -3)
        return res;
    res = -2;
    
    li nextX = (step) ? (x + a[x]) : (x - a[x]);
    if(nextX < 0 || nextX >= n){
        return res = a[x];
    }
    li g = ans(nextX, !step);
    if(g == -1)
        return res = -1;
    return res = a[x] + g;
}

void solve(){
    
    cin >> n;
    for(li i = 1; i < n; ++i){
        cin >> a[i];
        dp[i][0] = dp[i][1] = -3;
    }
    
    for(li i = 1; i < n; ++i){
        //cerr << "go " << i << endl;
        dp[0][0] = dp[0][1] = -3;
        a[0] = i;
        cout << ans(0, true) <<'\n';
    }
}