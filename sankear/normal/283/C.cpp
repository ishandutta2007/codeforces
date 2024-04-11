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
const int MOD = int(1e9) + 7;

int a[333], s[333], t[333], go[333];
int d[100100], nd[100100];

inline void norm(int &a){
    while(a >= MOD){
        a -= MOD;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q, T;
    scanf("%d %d %d", &n, &q, &T);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        go[i] = -1;
    }
    for(int i = 0; i < q; i++){
        int b, c;
        scanf("%d %d", &b, &c);
        b--;
        c--;
        go[c] = b;
    }
    for(int i = 0; i < n; i++){
        int j = i;
        bool fl = false;
        while(j != -1){
            if(j == i){
                if(fl){
                    printf("0\n");
                    return 0;
                }
                fl = true;
            }
            s[i] += a[j];
            t[i] += (j != i) * a[j];
            j = go[j];
        }
    }
    d[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= T; j++){
            nd[j] = 0;
        }
        for(int j = 0; j <= T; j++){
            if(j - t[i] >= 0){
                nd[j] += d[j - t[i]];
                norm(nd[j]);
            }
            if(j - s[i] >= 0){
                nd[j] += nd[j - s[i]];
                norm(nd[j]);
            }
        }
        for(int j = 0; j <= T; j++){
            d[j] = nd[j];
        }
    }
    printf("%d\n", d[T]);
    return 0;
}