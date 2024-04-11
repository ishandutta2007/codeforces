#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
const ll md = 1e9 + 7;

bool is_simple(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

vector <int> ans;

bool trytodoit(int n, int mx) {
    if (is_simple(n)) {
        ans.clear();
        ans.push_back(n);
        return true;
    }
    if (mx == 1) 
        return false;
    for (int i = n - 1; i > 0; i--)
        if (is_simple(i))
            if (trytodoit(n - i, mx - 1)) {
                ans.push_back(i);
                return true;
            }
    return false;
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    clock_t t0 = clock();
    trytodoit(n, 3);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    // cout << "\n" << clock() - t0 << "\n";
    // while (true);

    return 0;
}