#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    if (x < y) {
        return gcd(y, x);
    }
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

pair<int, int> my_upper_bound() {
    int l = 0, r = 1000000001;
    int mid;
    int qcount = 0;
    while (r - l > 1) {
        mid = (l + r) / 2;
        ++qcount;
        cout << "> " << mid << '\n';
        fflush(stdout);
        int ans;
        cin >> ans;
        if (ans == 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return make_pair(r, qcount);
}

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    int n;
    cin >> n;
    if (n <= 60) {
        {
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                cout << "? " << i + 1 << '\n';
                fflush(stdout);
                cin >> a[i];
            }
            sort(a.begin(), a.end());
            cout << "! " << a[0] << " " << a[1] - a[0] << '\n';
            return 0;
        }
    }
    pair<int, int> upper = my_upper_bound();
    int cura;
    int d;
    ++upper.second;
    cout << "? " << 1 << '\n';
    fflush(stdout);
    cin >> cura;
    if (cura == upper.first) {
        ++upper.second;
        cout << "? " << 2 << '\n';
        fflush(stdout);
        cin >> cura;
    }
    d = upper.first - cura;
    while (upper.second < 60) {
        ++upper.second;
        cout << "? " << rnd() % n + 1 << '\n';
        fflush(stdout);
        cin >> cura;
        int curd = upper.first - cura;
        d = gcd(d, curd);
    }
    cout << "! " << upper.first - d * (n - 1) << " " << d << '\n';
    return 0;
}