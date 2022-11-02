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
#include <cassert>

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

const int inf = int(1e9);
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;

int add[N];
char s[N];
int cnt[30];
vi lst[30];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m;
    scanf("%d %s", &m, s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
        lst[s[i] - 'a'].pb(i);
    }
    for (int ii = 0; ii < 26; ++ii) {
        if (cnt[ii] == 0) {
            continue;
        }
        int res = 0;
            int bal = 0, ptr = 0;
            bool fl = true;
            for (int i = 0; i + m - 1 < n; ++i) {
                while (ptr + 1 < cnt[ii] && lst[ii][ptr + 1] <= i + m - 1) {
                    ++ptr;
                }
                bal += add[i];
                if (bal == 0) {
                    if (lst[ii][ptr] < i || lst[ii][ptr] > i + m - 1) {
                        fl = false;
                        break;
                    }
                    for (int j = i + 1; j <= lst[ii][ptr]; ++j) {
                        bal += add[j];
                    }
                    i = lst[ii][ptr];
                    ++res;
                }
            }
        if (fl) {
            for (int j = 0; j < ii; ++j) {
                for (int z = 0; z < cnt[j]; ++z) {
                    printf("%c", 'a' + j);
                }
            }
            for (int j = 0; j < res; ++j) {
                printf("%c", 'a' + ii);
            }
            puts("");
            return 0;
        }
        for (int p : lst[ii]) {
            int l = max(p - m + 1, 0);
            ++add[l];
            --add[p + 1];
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            printf("%c", 'a' + i);
        }
    }
    puts("");
    return 0;
}