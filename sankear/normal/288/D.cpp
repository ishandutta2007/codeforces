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

int n;
ull ans;
bool used[100100];
int sz[100100], cnt[100100], p[100100];
ull d[100100][3];
vi v[100100];

void dfs(int a){
    used[a] = true;
    sz[a] = 1;
    for(int i = 0; i < sz(v[a]); i++){
        if(!used[v[a][i]]){
            p[v[a][i]] = a;
            dfs(v[a][i]);
            sz[a] += sz[v[a][i]];
        }
    }
    int k = 0;
    for(int i = 0; i < sz(v[a]); i++){
        if(p[v[a][i]] == a){
            cnt[k++] = sz[v[a][i]];
        }
    }
    cnt[k++] = 1;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= 2; j++){
            d[i][j] = 0;
        }
    }
    d[0][0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= 2; j++){
            d[i][j] += d[i - 1][j];
            if(j > 0){
                d[i][j] += d[i - 1][j - 1] * cnt[i - 1];
            }
        }
    }
    ull res = d[k][2] * d[k][2];
    res += d[k][2] * d[k][1] * (n - sz[a]) * 2;
    //cerr << a << " " << res << endl;
    ans -= res;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i = 0; i < n; i++){
        p[i] = -1;
    }
    ans = (ull(n) * (n - 1) / 2) * (ull(n) * (n - 1) / 2);
    dfs(0);
    cout << ans << endl;
    return 0;
}