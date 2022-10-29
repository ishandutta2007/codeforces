#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:300000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

ll a,b;

ll p[] = {2, 3, 5};
ll cnt[] = {0,0,0};
ll cnt2[] = {0,0,0};

bool read(){
    return (cin >> a >> b);
}

void solve(){
    memset(cnt, 0, sizeof cnt);
    memset(cnt2, 0, sizeof cnt2);
    forn(i,3){
        while (a % p[i] == 0){
            a /= p[i];
            cnt[i]++;
        }
    }
    forn(i,3){
        while (b % p[i] == 0){
            b /= p[i];
            cnt2[i]++;
        }
    }
    if (a != b){
        puts("-1");
        return;
    }
    int ans = 0;
    forn(i,3)
        ans += abs(cnt[i] - cnt2[i]);
    cout << ans << endl;
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    while (read())
        solve();
    return 0;
}