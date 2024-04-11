#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define next _next

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e6);

bool used[N + 100];
int sum[N + 100];

inline bool check(int l, int r) {
    if (l > r) {
        return false;
    }
    return (sum[r] - (l > 0 ? sum[l - 1] : 0)) > 0;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        used[cur] = true;
        ++sum[cur];
    }
    for (int i = 1; i <= N; ++i) {
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= N; ++i) {
        if (!used[i]) {
            continue;
        }
        for (int j = i; j <= N; j += i) {
            while (check(j + ans + 1, min(j + i - 1, N))) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}