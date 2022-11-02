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

int k, ans;
bool used[10];
int p[10];

inline int calc(int a, int b){
    int res = 1;
    while(b > 0){
        if(b % 2 != 0){
            res = (ll(res) * a) % MOD;
        }
        a = (ll(a) * a) % MOD;
        b /= 2;
    }
    return res;
}

void gen(int x){
    if(x >= k){
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                used[j] = false;
            }
            bool good = false;
            int j = i;
            while(!used[j]){
                if(j == 0){
                    good = true;
                    break;
                }
                used[j] = true;
                j = p[j];
            }
            if(!good){
                return;
            }
        }
        ans++;
        return;
    }
    for(int i = 0; i < k; i++){
        p[x] = i;
        gen(x + 1);
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d %d", &n, &k);
    ans = 0;
    gen(0);
    ans = (ll(ans) * calc(n - k, n - k)) % MOD;
    printf("%d\n", ans);
    return 0;
}