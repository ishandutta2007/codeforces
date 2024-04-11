#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[200100];
int b[200100];
map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    forn (i, n) {
        m[b[i]] = i;
    }
    forn (i, n) {
        a[i] = m[a[i]];
    }
    vector<bool> used(n, false);
    vector<vector<int> > ans;
    forn (i, n) {
        if (used[i]) {
            continue;
        }
        int v = i;
        ans.pb(vector<int>());
        while (true) {
            ans.back().pb(v);
            used[v] = true;
            v = a[v];
            if (v == i) {
                break;
            }
        }
    }
    cout << ans.size() << endl;
    forn (i, ans.size()) {
        cout << ans[i].size() << " ";
        forn (j, ans[i].size()) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}