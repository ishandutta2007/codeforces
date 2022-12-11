#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int p, q, l, r, ta, tb, ans;
vector < pair <int, int> > a, b;
pair<int, int> c[N], v;
bool inter;

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> p >> q >> l >> r;
    for (int i = 0; i < p; i++) {
        cin >> ta >> tb;
        a.push_back(make_pair(ta, 1));
        a.push_back(make_pair(tb, -1));
    }
    for (int i = 0; i < q; i++) {
        cin >> ta >> tb;
        b.push_back(make_pair(ta + l - 1, 1));
        b.push_back(make_pair(tb + l - 1, -1));
    }

    for (int i = l; i <= r; i++) {
        for (int j = 0; j < b.size(); j++)
            b[j].first++;
        merge(a.begin(), a.end(), b.begin(), b.end(), c);
        inter = false;
        for (int j = 1; j < 2 * (p + q) && !inter; j++)
            if (c[j].second == c[j - 1].second || c[j].first == c[j - 1].first)
                inter = true;
        ans += int(inter);
    }
    
    cout << ans;
    //return 0;
}