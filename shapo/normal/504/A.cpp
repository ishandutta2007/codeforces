#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 100500;

int deg[MAXN], s[MAXN];
int n;
vector< pair< int, int > > res;
int used[MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    res.clear();
    for (int i = 0; i < n; ++i) {
        cin >> deg[i] >> s[i];
    }
    vector< int > q(n + 1);
    int qh = 0, qt = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1 && !used[s[i]]) {
            --deg[i];
            used[i] = true;
            q[qt++] = i;
            res.emplace_back(i, s[i]);
        }
    }
    while (qh < qt) {
        int i = q[qh++];
        s[s[i]] ^= i;
        deg[s[i]]--;
        if (deg[s[i]] == 1 && !used[s[s[i]]]) {
            used[s[i]] = true;
            q[qt++] = s[i];
            deg[s[i]]--;
            res.emplace_back(s[i], s[s[i]]);
        }
    }
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}