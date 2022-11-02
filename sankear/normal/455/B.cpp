#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int LEN = int(1e5) + 100;

char s[LEN];
bool can_win[LEN], can_loose[LEN];
int next[LEN][26];

void dfs(int v) {
    bool exists = false;
    for (int i = 0; i < 26; ++i) {
        if (next[v][i] != -1) {
            exists = true;
            dfs(next[v][i]);
        }
    }
    if (!exists) {
        can_loose[v] = true;
    }
    else {
        for (int i = 0; i < 26; ++i) {
            if (next[v][i] != -1) {
                can_loose[v] |= !can_loose[next[v][i]];
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (next[v][i] != -1) {
            can_win[v] |= !can_win[next[v][i]];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 26; ++i) {
        next[0][i] = -1;
    }
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s), cur = 0;
        for (int j = 0; j < len; ++j) {
            int c = s[j] - 'a';
            if (next[cur][c] == -1) {
                next[cur][c] = ++ptr;
                for (int z = 0; z < 26; ++z) {
                    next[ptr][z] = -1;
                }
            }
            cur = next[cur][c];
        }
    }
    dfs(0);
    if (k == 1) {
        if (can_win[0]) {
            puts("First");
        }
        else {
            puts("Second");
        }
        return 0;
    }
    if (!can_win[0]) {
        puts("Second");
        return 0;
    }
    if (can_loose[0] && can_win[0]) {
        puts("First");
        return 0;
    }
    if (k % 2 == 0) {
        puts("Second");
        return 0;
    }
    puts("First");
    return 0;
}