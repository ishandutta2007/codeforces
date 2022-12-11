#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 34;

int n, a[N], mn = 1e9, sum, less0, x;
vector <int> v1, v0;
int p0, p1, s0, s1, k;
vector <int> cur;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> k >> p0;
    p1 = k - p0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2)
            v1.push_back(x);
        else
            v0.push_back(x);
    }
    s0 = v0.size();
    s1 = v1.size();

    if (s1 >= p1 && (s1 - p1) / 2 + s0 >= p0 && (s1 - p1) % 2 == 0) {
        cout << "YES\n";

        if (p0 == 0) {
            for (int i = 0; i < p1 - 1; i++) cout << "1 " << v1[i] << "\n";
            cout << s1 - p1 + 1 + s0;
            for (int i = p1 - 1; i < s1; i++)
                cout << " " << v1[i];
            for (int i = 0; i < s0; i++)
                cout << " " << v0[i];
            cout << "\n";
            return 0;
        }

        for (int i = 0; i < p1; i++) {
            cout << "1 " << v1.back() << "\n";
            v1.pop_back();
        }
        k -= p1;
        for (int i = 0; i < v1.size() / 2; i++) {
            cur.push_back(v1[i * 2]);
            cur.push_back(v1[i * 2 + 1]);
            if (k > 1) {
                k--;
                cout << cur.size();
                for (int i = 0; i < cur.size(); i++)
                    cout << " " << cur[i];
                cout << "\n";
                cur.clear();
            }
        }
        for (int i = 0; i < s0; i++) {
            cur.push_back(v0[i]);
            if (k > 1) {
                k--;
                cout << cur.size();
                for (int i = 0; i < cur.size(); i++)
                    cout << " " << cur[i];
                cout << "\n";
                cur.clear();
            }
        }
        if (k == 1) {
            cout << cur.size();
            for (int i = 0; i < cur.size(); i++)
                cout << " " << cur[i];
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}