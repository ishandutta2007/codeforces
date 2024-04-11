#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>

using namespace std;

#define pb push_back
#define pbk pop_back
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define mt make_tuple
#define mp make_pair
#define next hunext
#define prev huprev

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(3e5) + 100;

bool used[N];
int x_ptr[N];
vi lst[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int ptr = 0, k = 0, ans = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            --x;
            lst[x].pb(k++);
            ++ans;
        } else if (t == 2) {
            int x;
            scanf("%d", &x);
            --x;
            while (x_ptr[x] < sz(lst[x])) {
                if (!used[lst[x][x_ptr[x]]]) {
                    --ans;
                    used[lst[x][x_ptr[x]]] = true;
                }
                ++x_ptr[x];
            }
        } else if (t == 3) {
            int cnt;
            scanf("%d", &cnt);
            while (ptr < cnt) {
                if (!used[ptr]) {
                    used[ptr] = true;
                    --ans;
                }
                ++ptr;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}