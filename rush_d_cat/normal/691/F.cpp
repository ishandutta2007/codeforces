#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
//#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define dd(x) cout << #x << " = " << x << endl;
#define max(x, y) (x > y ? x : y)
typedef pair<int, int> pii;
typedef long long LL;
const LL INF = 1e16;
const LL MOD = 1000000007;
const int N = 3000000+10;

int n, m;
LL a[N], q[N];
LL c[N], s[N]; // cnt of <= x

LL bit[N];

void init() {
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%lld", &a[i]); c[a[i]] ++;
    }
    rep(i, 1, N-1) s[i] = s[i-1] + c[i];
    rep(i, 1, N-1) if (c[i]) {
        for (int j = i; j < N; j += i) {
            // x = i, y:[j/i, N], z:[j-i+1,j]
            if (i < j/i) {
                bit[j-i+1] += (s[N-1]-s[j/i-1]) * c[i];
                bit[j+1] -= (s[N-1]-s[j/i-1]) * c[i];
            } else {
                bit[j-i+1] += (s[N-1]-s[j/i-1]-1) * c[i];
                bit[j+1] -= (s[N-1]-s[j/i-1]-1) * c[i];
            }
        }
    }
    rep(i,1,N-1) bit[i]+=bit[i-1];
    
    scanf("%d", &m);
    rep(i, 1, m) {
        int x; scanf("%d", &x);
        printf("%lld\n", bit[x]);
    }
}
int main() {
    init();
}