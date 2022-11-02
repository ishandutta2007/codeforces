#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int k;
int d[370370];

inline int gcd(int a, int b){
    while(b > 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

inline int solve(int l, int r){
    for(int i = 0; i <= r - l; i++){
        d[i] = inf;
    }
    d[0] = 0;
    for(int i = 1; i <= r - l; i++){
        d[i] = min(d[i], d[i - 1] + 1);
        for(int j = 2; j <= k; j++){
            if(i < (l + i) % j){
                continue;
            }
            d[i] = min(d[i], d[i - (l + i) % j] + 1);
        }
    }
    return d[r - l];
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll a, b;
    scanf(LLD" "LLD" %d", &a, &b, &k);
    swap(a, b);
    if(a == b){
        printf("0\n");
        return 0;
    }
    int val = 1;
    for(int i = 2; i <= k; i++){
        val = (val * i) / gcd(val, i);
    }
    ll A = ((a + val - 1) / val) * val;
    ll B = (b / val) * val;
    ll ans;
    if(A <= B){
        ans = solve(a % val, val - 1) + solve(0, b % val) + 1 + (solve(0, val - 1) + 1) * ((B - A) / val);
    }
    else{
        ans = solve(a % val, b % val);
    }
    printf(LLD"\n", ans);
    return 0;
}