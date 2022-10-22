#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c[3]{0, 0, 0};

    vector<bool> used(500000, false);
    vector<int> primes;
    for (int i = 2; i < 500000; ++i) {
        if (used[i]) {
            continue;
        }
        primes.push_back(i);
        if (i < 10000) {
            for (int j = i * i; j < 500000; j += i) {
                used[j] = true;
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        ++c[q];
    }

    int cur = 0;
    int np = 0;
    vector<int> ans;
    while (c[1] > 0 || c[2] > 0) {
        if ((primes[np] - cur > 1 && c[2] > 0) || c[1] == 0) {
            --c[2];
            cur += 2;
            ans.push_back(2);
        } else {
            --c[1];
            ++cur;
            ans.push_back(1);
        }
        if (cur > primes[np]) {
            ++np;
        }
        if (cur == primes[np]) {
            ++np;
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}