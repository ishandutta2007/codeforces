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
#define len(s) int((s).size())
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
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int cnt[10];
vector <pair <int, pii> > ans;

inline void fail(){
    puts("-1");
    exit(0);
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int cur;
        scanf("%d", &cur);
        cnt[cur]++;
    }
    while(cnt[3] > 0){
        if(cnt[1] == 0 || cnt[6] == 0){
            fail();
        }
        ans.pb(mp(1, mp(3, 6)));
        cnt[1]--;
        cnt[3]--;
        cnt[6]--;
    }
    while(cnt[6] > 0){
        if(cnt[1] == 0 || cnt[2] == 0){
            fail();
        }
        ans.pb(mp(1, mp(2, 6)));
        cnt[1]--;
        cnt[2]--;
        cnt[6]--;
    }
    while(cnt[4] > 0){
        if(cnt[1] == 0 || cnt[2] == 0){
            fail();
        }   
        ans.pb(mp(1, mp(2, 4)));
        cnt[1]--;
        cnt[2]--;
        cnt[4]--;
    }
    for(int i = 1; i <= 7; i++){
        if(cnt[i] > 0){
            fail();
        }
    }
    for(int i = 0; i < sz(ans); i++){
        printf("%d %d %d\n", ans[i].fs, ans[i].sc.fs, ans[i].sc.sc);
    }
    return 0;
}