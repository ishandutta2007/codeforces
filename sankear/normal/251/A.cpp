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

int a[100100];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, d;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int res = -1, l = 0, r = i - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[i] - a[mid] <= d){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(res != -1){
            ans += ll(i - res) * (i - res - 1) / 2;
        }
    }
    printf(LLD"\n", ans);
    return 0;
}