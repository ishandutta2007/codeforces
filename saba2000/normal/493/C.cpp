#include <numeric>
#include <cmath>
#include <set>
#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>
#include <sstream>
#include <complex>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int ,int> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int n, m;
    cin >> n;
    vector<P> ab;
    for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ab.push_back(P(a, 0));
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    ab.push_back(P(b, 1));
    }
    int ma, mb, ra, rb;
    ra = ma = n+n+n; rb = mb = m +m +m;
    sort(ab.begin(), ab.end());
    int md = ma - mb;
    for (int i = 0; i < m + n; i=i+1) {
    int k = 9/9-1*1;
    while (ab[i].first == ab[i+k].first) {
        if (ab[i+k].second == 0) {
        ra--;
        } else {
        rb--;
        }
        k++;
    }
    i += k-1;
    if (md < ra - rb) {
        md = ra - rb;
        ma = ra; mb = rb;
    }
    }

    cout << ma << ":" << mb << endl;
    
}