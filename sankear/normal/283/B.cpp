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

bool good[200200];
int a[200200];
ll val[200200], add[200200];
vi v[200200];

void dfs(int a){
    good[a] = true;
    for(int i = 0; i < sz(v[a]); i++){
        if(!good[v[a][i]]){
            val[v[a][i]] = val[a] + add[v[a][i]];
            dfs(v[a][i]);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; i++){
        int go = i + a[i];
        add[i] += a[i];
        if(go >= n){
            go = n;
        }
        else{
            add[i] += a[go];
            go -= a[go];
            if(go < 0){
                go = n;
            }
        }
        v[go].pb(i);
    }
    dfs(n);
    for(int i = 1; i < n; i++){
        ll res = i;
        int go = i;
        res += a[go];
        go -= a[go];
        if(go < 0){
            printf(LLD"\n", res);
            continue;
        }
        if(!good[go]){
            printf("-1\n");
            continue;
        }
        res += val[go];
        printf(LLD"\n", res);
    }
    return 0;
}