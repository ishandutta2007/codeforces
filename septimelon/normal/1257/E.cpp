#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = (int)1e9+7;

void smin(int& x, int& y) {
    if (y < x) {
        swap(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k[3];
    for (int i = 0; i < 3; ++i) {
        cin >> k[i];
    }
    vector<int> a[3];
    int n = k[0] + k[1] + k[2];
    vector<int> task(n);
    for (int i = 0; i < 3; ++i) {
        a[i].resize(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            cin >> a[i][j];
            task[a[i][j] - 1] = i;
        }
    }

    int tot2 = k[0] + k[2];

    vector<int> pref(n);
    vector<int> pref2(n);
    vector<int> suf(n);
    vector<int> suf2(n);

    pref[0] = (task[0] == 0 ? 0 : 1);
    pref2[0] = (task[0] == 1 ? 0 : 1);
    suf[n - 1] = (task[n - 1] == 2 ? 0 : 1);
    suf2[n - 1] = (task[n - 1] == 1 ? 0 : 1);

    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1];
        if (task[i] != 0) {
            ++pref[i];
        }
        pref2[i] = pref2[i - 1];
        if (task[i] != 1) {
            ++pref2[i];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = suf[i + 1];
        if (task[i] != 2) {
            ++suf[i];
        }
        suf2[i] = suf2[i + 1];
        if (task[i] != 1) {
            ++suf2[i];
        }
    }

    priority_queue<pii> sufs;
    for (int i = 0; i < n; ++i) {
        sufs.push({INF - (suf[i] - suf2[i]), i});
    }
    sufs.push({INF, n});
    int mina = INF - sufs.top().first;
    for (int i = 0; i < n; ++i) {
        while (sufs.top().second <= i) {
            sufs.pop();
        }
        mina = min(mina, pref[i] - pref2[i] + INF - sufs.top().first);
    }
    mina += tot2;
    cout << mina << '\n';

    return 0;
}