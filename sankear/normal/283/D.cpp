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

ll a[5050];
int b[5050], d[5050];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(LLD, &a[i]);
        b[i] = 0;
        while(a[i] % 2 == 0){
            a[i] /= 2;
            b[i]++;
        }
    }
    for(int i = 0; i < n; i++){
        d[i] = i;
        for(int j = 0; j < i; j++){
            if(a[j] % a[i] == 0 && (b[j] + i - j == b[i] || i - j > b[i])){
                d[i] = min(d[i], d[j] + i - j - 1);
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < n; i++){
        ans = min(ans, d[i] + n - i - 1);
    }
    printf("%d\n", ans);
    return 0;
}