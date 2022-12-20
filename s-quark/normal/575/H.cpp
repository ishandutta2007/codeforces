#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 2123456;
int P = (int)(1e9+7.5);

int fac[MAXN], fac1[MAXN];
int inv[MAXN];

int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    int i, j, k;

    scanf("%d", &n);
    inv[1] = 1;
    for(i = 2; i <= 2*n+2; i++){
        inv[i] = (ll)(P-inv[P%i]) * (P/i) % P;
    }
    fac[0] = fac1[0] = 1;
    for(i = 1; i <= 2*n+2; i++){
        fac[i] = (ll)fac[i-1] * i % P;
        fac1[i] = (ll)fac1[i-1] * inv[i] %P;
    }

    int ans = (ll)fac[2*n+2] * fac1[n+1] % P * fac1[n+1] % P - 1;

    printf("%d\n", ans);

    return 0;
}