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

char s[1000100];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d %d", &n, &k);
    if(k == 1){
        if(n == 1){
            printf("a\n");
            return 0;
        }
        printf("-1\n");
        return 0;
    }
    if(n < k){
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < n - k + 2; i++){
        s[i] = (i % 2 == 0 ? 'a' : 'b');
    }
    for(int i = n - k + 2; i < n; i++){
        s[i] = 'c' + i - n + k - 2;
    }
    printf("%s\n", s);
    return 0;
}