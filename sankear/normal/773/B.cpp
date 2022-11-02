#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <sstream>
#include <cassert>
#include <array>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll inf = ll(1e17);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = 123;
const int K = 5;
const int VARS = 6;
const int MAGIC = int(3e6);

const int L[] = { 2, 4, 8, 16, 32, 0 };
const int R[] = { 1, 2, 4, 8, 16, 32 };
const ll COST[] = { 500, 1000, 1500, 2000, 2500, 3000 };

int a[N][K];
int v[K], p[K], solved[K];
ll tmp1[K][VARS], tmp2[K][VARS], C1[K][VARS], C2[K][VARS];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < K; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != -1) {
                ++solved[j];
            }
        }
    }
    for (int i = 0; i < K; ++i) {
        v[i] = a[0][i];
        p[i] = a[1][i];
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < VARS; ++j) {
            tmp1[i][j] = n - 1LL * R[j] * solved[i];
            tmp2[i][j] = n - 1LL * L[j] * solved[i];
            C1[i][j] = COST[j] * (250 - v[i]) / 250;
            C2[i][j] = COST[j] * (250 - p[i]) / 250;
        }
    }
    for (int x = 0; x < MAGIC; ++x) {
        ll diff = 0;
        for (int i = 0; i < K; ++i) {
            if (v[i] != -1) {
                ll max_diff = -inf;
                for (int j = 0; j < VARS; ++j) {
                    ll rt = x;
                    ll tmp = tmp1[i][j] + x;
                    if (tmp < 0) {
                        continue;
                    }
                    tmp /= R[j];
                    if (tmp < rt) {
                        rt = tmp;
                    }
                    if (L[j] != 0) {
                        tmp = tmp2[i][j] + x;
                        if (tmp >= 0 && tmp / L[j] + 1 > rt) {
                            continue;
                        }
                    }
                    ll cur_diff = C1[i][j];
                    if (p[i] != -1) {
                        cur_diff -= C2[i][j];
                    }
                    if (cur_diff > max_diff) {
                        max_diff = cur_diff;
                    }
                }
                assert(max_diff > -inf / 2);
                diff += max_diff;
            } else if (p[i] != -1) {
                ll cost = -1;
                for (int j = 0; j < VARS; ++j) {
                    if (tmp1[i][j] + x >= 0 && (L[j] == 0 || tmp2[i][j] + x < 0)) {
                        cost = C2[i][j];
                        break;
                    }
                }
                assert(cost != -1);
                diff -= cost;
            }
        }
        if (diff > 0) {
            cout << x << endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}