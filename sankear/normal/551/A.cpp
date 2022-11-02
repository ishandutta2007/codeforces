#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define pbk pop_back

typedef long long ll;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 2020;

int a[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] > a[i]) {
                ++ans;
            }
        }
        printf("%d ", 1 + ans);
    }
    puts("");
    return 0;
}