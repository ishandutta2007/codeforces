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
#define mp make_pair
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d %d", &x, &y)
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define dd(x) cout << #x << " = " << x << endl;
#define max(x, y) (x > y ? x : y)
typedef pair<int, int> pii;
typedef long long LL;
const LL INF = 1000000007;
const LL MOD = 1000000007;
const int N = 100000+10;
LL n, m;

int main() {
    cin >> n >> m;
    LL t = 1;
    rep(i, 1, n) {
        t <<= 1L;
        if (t > m) {
            return !printf("%lld\n", m);
        }
    }
    printf("%lld\n", m % t);
}