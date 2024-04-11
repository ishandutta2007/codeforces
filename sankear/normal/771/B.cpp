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
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = 55;

int n, k;
char s[N][22];
string names[N];
int ans[N];
bool used[N];

inline void gen_names() {
    int ptr = 0;
    for (int i = 0; i < 26 && ptr < N; ++i) {
        for (int j = 0; j < 26 && ptr < N; ++j) {
            names[ptr].pb('A');
            names[ptr].pb('a' + i);
            names[ptr].pb('a' + j);
            ++ptr;
        }
    }
}

inline void print_ans() {
    for (int i = 0; i < n - k + 1; ++i) {
        set<string> s;
        for (int j = 0; j < k; ++j) {
            s.insert(names[ans[i + j]]);
        }
        if (sz(s) == k) {
            assert(strcmp(::s[i], "YES") == 0);
        } else {
            assert(strcmp(::s[i], "NO") == 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s ", names[ans[i]].data());
    }
    puts("");
    exit(0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gen_names();
    cin >> n >> k;
    for (int i = 0; i < n - k + 1; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n - k + 1; ++i) {
        if (strcmp(s[i], "YES") == 0) {
            for (int j = 0; j < k; ++j) {
                ans[i + j] = j;
            }
            int last = 1;
            for (int j = i + 1; j < n - k + 1; ++j) {
                if (strcmp(s[j], "YES") == 0) {
                    if (last) {
                        ans[j + k - 1] = ans[j - 1];
                    } else {
                        assert(ans[j - 1] == ans[j + k - 2]);
                        for (int z = 0; z < k; ++z) {
                            used[z] = false;
                        }
                        for (int z = 0; z < k; ++z) {
                            used[ans[j - 1 + z]] = true;
                        }
                        vi can;
                        for (int z = 0; z < k; ++z) {
                            if (!used[z]) {
                                can.pb(z);
                            }
                        }
                        assert(sz(can) == 1);
                        ans[j + k - 1] = can[0];
                    }
                    last = 1;
                } else {
                    ans[j + k - 1] = ans[j];
                    last = 0;
                }
            }
            last = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (strcmp(s[j], "YES") == 0) {
                    if (last) {
                        ans[j] = ans[j + k];
                    } else {
                        assert(ans[j + 1] == ans[j + k]);
                        for (int z = 0; z < k; ++z) {
                            used[z] = false;
                        }
                        for (int z = 0; z < k; ++z) {
                            used[ans[j + 1 + z]] = true;
                        }
                        vi can;
                        for (int z = 0; z < k; ++z) {
                            if (!used[z]) {
                                can.pb(z);
                            }
                        }
                        assert(sz(can) == 1);
                        ans[j] = can[0];
                    }
                    last = 1;
                } else {
                    ans[j] = ans[j + k - 1];
                    last = 0;
                }
            }
            print_ans();
        }
    }
    print_ans();
    return 0;
}