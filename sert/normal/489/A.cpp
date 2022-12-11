#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>

#define ff first
#define ss second
#define y1 yy1

using namespace std;

typedef long long ll;
const ll N = 1e6 + 7;

ll n, m, a[N], b[N], ps;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n;
    cout << n - 1 << "\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        ps = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[ps])
                ps = j;
        swap(a[i], a[ps]);
        cout << i << " " << ps << "\n";
    }
}