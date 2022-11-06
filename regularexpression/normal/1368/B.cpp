#include<bits/stdc++.h>
using namespace std;

#define int long long 

const string codeforces = "codeforces";

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    int len = codeforces.size();
    vector<int> cnt(len, 0);
    while (1) {
        int subs = 1;
        for (auto i : cnt)
            subs *= i;
        if (subs < k) {
            int ind = 0;
            for (int i = 1; i < len; i++) {
                if (cnt[i] < cnt[ind])
                    ind = i;
            }
            cnt[ind]++;
        } else
            break;
    }
    for (int i = 0; i < len; i++)
        cout << string(cnt[i], codeforces[i]);
    return 0;
}