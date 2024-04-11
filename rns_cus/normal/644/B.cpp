#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
using namespace std;
/*int siz = 256 << 20; // 256MB
	char *_ = (char*)malloc(siz) + siz;
	__asm__("movl %0, %%esp\n"::"r"(_));*/
typedef long long LL;
typedef pair<int, int> pii;
typedef vector <int> VI;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef queue<int> QI;
#define rep(i, n) for(int i = 0; i < n; i ++)
#define Rep(i, a, b) for(int i = a; i <= b; i ++)
#define X first
#define Y second
#define MP make_pair
#define PB push_back
const int mod = 1000000007;
const int oo = 1000000000;
const LL ooL = 1000000000000000000LL;
const double pi = acos(-1);
const double ep = 1e-8;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
/*template <typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T> inline T _abs(T a) { return a < 0 ? -a : a; }
template <typename T> inline T sqr(T a) { return a * a; }
template <typename T> chkmin(T &a, T b) { if(a > b) a = b; }
template <typename T> chkmax(T &a, T b) { if(a < b) a = b; }*/

#define N 200200

int n, b;
int tt[N], d[N], id[N];

bool cmp(int i, int j) { return tt[i] < tt[j]; }

LL ans[N], q[N];
int h, t;

int main() {
    //freopen("in.txt","r",stdin);
    scanf("%d %d", &n, &b);
    for(int i = 0; i < n; i ++) scanf("%d %d", tt + i, d + i), id[i] = i, ans[i] = -1;
    sort(id, id + n, cmp);
    LL cur = 0;
    for(int i = 0; i < n; i ++) {
        int j = id[i];
        while(h < t) {
                if(cur + d[q[h]] <= tt[j]) {
                    ans[q[h]] = cur + d[q[h]];
                    cur += d[q[h ++]];
                } else break;
            }
        if(h == t) {
            q[t ++] = j;
            cur = tt[j];
        } else {
            
            if(t - h <= b) q[t ++] = j;
        }
    }
    while(h < t) {
        ans[q[h]] = cur + d[q[h]];
        cur += d[q[h ++]];
    }
    printf("%I64d", ans[0]);
    for(int i = 1; i < n; i ++) printf(" %I64d", ans[i]); puts("");
    return 0;
}