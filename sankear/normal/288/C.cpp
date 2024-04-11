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

int n, ans;
int sz[1000100], p[1000100];
bool used[1010];
vector <vi> best;

void gen(int x){
    if(x > n){
        int res = 0;
        for(int i = 0; i <= n; i++){
            res += (i ^ p[i]);
        }
        if(res > ans){
            ans = res;
            best.clear();
        }
        if(res == ans){
            vi cur;
            for(int i = 0; i <= n; i++){
                cur.pb(p[i]);
            }
            best.pb(cur);
        }
        return;
    }
    for(int i = 0; i <= n; i++){
        if(!used[i]){
            p[x] = i;
            used[i] = true;
            gen(x + 1);
            used[i] = false;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    /*ans = -1;
    gen(0);
    cout << ans << endl;
    for(int i = 0; i < sz(best); i++){
        for(int j = 0; j <= n; j++){
            cout << best[i][j] << " ";
        }
        cout << endl;
    }*/
    n++;
    sz[1] = 1;
    sz[2] = 2;
    for(int i = 3; i <= n; i++){
        if(sz[i - 1] == i - 1){
            sz[i] = 2;
        }
        else{
            sz[i] = sz[i - 1] + 2;
        }
    }
    int k = 0;
    while(n > 0){
        for(int i = n - sz[n]; i < n; i++){
            p[k++] = i;
        }
        n -= sz[n];
    }
    reverse(p, p + k);
    ll ans = 0;
    for(int i = 0; i < k; i++){
        ans += (i ^ p[i]);
    }
    printf(LLD"\n", ans);
    for(int i = 0; i < k; i++){
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}