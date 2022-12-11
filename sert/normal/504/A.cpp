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

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N], n, m, p[N], k[N], v;
set <pair<int, pair<int, int> > > s;
pair <int, pair<int, int> > pt;
vector <pair<int, int> > ans;
bool u[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> k[i];
        s.insert(make_pair(p[i], make_pair(k[i], i)));
    }

    while (!s.empty()) {
        //cerr << s.size() << "\n";
        if (s.begin()->first == 0) {
            s.erase(s.begin());
            continue;
        }
        pt = *s.begin();
        if (pt.first != 1) return 34;
        m = pt.ss.ss;
        v = pt.ss.ff;
        s.erase(s.begin());
        s.erase(make_pair(p[v], make_pair(k[v], v)));
        p[v]--;
        k[v] ^= m;
        s.insert(make_pair(p[v], make_pair(k[v], v)));
        ans.push_back(make_pair(m, v));
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";

    return 0;
}