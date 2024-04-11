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

const int N = 6;

string schema[] = {
    "+------------------------+",
    "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|",
    "|#.......................|",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
    "+------------------------+"
};

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k;
    scanf("%d", &k);
    vector<pii> v;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < sz(schema[i]); ++j) {
            if (((j == 1 && i >= 1 && i <= 4) || (i >= 1 && i <= 4 && i != 3)) && j % 2 != 0 && j < (int) strlen("|#.#.#.#.#.#.#.#.#.#.#")) {
                v.pb(mp(j, i));
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; ++i) {
        schema[v[i].sc][v[i].fs] = 'O';
    }
    for (int i = 0; i < N; ++i) {
        cout << schema[i] << endl;
    }
    return 0;
}