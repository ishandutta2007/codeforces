#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> a;
    int minx = 10000000, miny = 10000000;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        minx = min(minx, x[i]);
        miny = min(miny, y[i]);
        if ((x[i] + y[i]) % 2 == 0) {
            a.push_back(i + 1);
        }
        //maxs = max(maxs, abs(x[i] + y[i]));
    }
    for (int i = 0; i < n; ++i) {
        x[i] -= minx;
        y[i] -= miny;
    }
    bool acc = false;
    while (a.size() == 0 || a.size() == n) {
        a.clear();
        if (!acc) {
            acc = true;
            if (x[0] % 2 == 1) {
                for (int i = 0; i < n; ++i) {
                    ++x[i];
                }
            }
            if (y[0] % 2 == 1) {
                for (int i = 0; i < n; ++i) {
                    ++y[i];
                }
            }
            for (int i = 0; i < n; ++i) {
                if (x[i] % 2 == 0) {
                    a.push_back(i + 1);
                }
            }
        } else {
            acc = false;
            for (int i = 0; i < n; ++i) {
                x[i] /= 2;
                y[i] /= 2;
            }
            for (int i = 0; i < n; ++i) {
                if ((x[i] + y[i]) % 2 == 0) {
                    a.push_back(i + 1);
                }
            }
        }
        /*for (int i = 0; i < n; ++i) {
            cout << x[i] << "-" << y[i] << ";";
        }
        cout << '\n';*/
    }
    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}