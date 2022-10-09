#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int rec(int n, vector<int> &mv) {
    if (n == 0) {
        return 0;
    }
    vector<int> a;
    forn (i, n) {
        bool was = false;
        forn (j, mv.size()) {
            if (mv[j] == i + 1) {
                was = true;
                break;
            }
        }
        if (was) {
            continue;
        }
        mv.push_back(i + 1);
        a.push_back(rec(n - i - 1, mv));
        mv.pop_back();
    }
    sort(a.begin(), a.end());
    int cur = 0;
    forn (i, a.size()) {
        if (a[i] == cur) {
            ++cur;
        } else if (a[i] > cur) {
            break;
        }
    }
    return cur;
}

int ans[1000];

int main() {
    ios::sync_with_stdio(false);
    /*freopen("output.txt", "wt", stdout);
    vector<int> a;
    forn (i, 60) {
        a.clear();
        cout << "   ans[" << i << "] = " << rec(i, a) << ";\n";
    }*/
    int j = 0;
    forn (i, 20) {
        forn (k, i + 1) {
            ans[j++] = i;
        }
    }
    int n;
    cin >> n;
    int res = 0;
    forn (i, n) {
        int x;
        cin >> x;
        res ^= ans[x];
    }
    cout << (res == 0 ? "YES\n" : "NO\n") << endl;
    return 0;
}