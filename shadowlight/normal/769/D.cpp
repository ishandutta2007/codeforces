#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10007;
const int Q = 14;
vector <int> perms;

inline void brute_force(int n, int now_mask, int prev) {
    if (!n) {
        perms.push_back(now_mask);
        return;
    }
    for (int i = prev + 1; i < Q; i++) {
        brute_force(n - 1, now_mask | (1 << i), i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    brute_force(k, 0, -1);
    vector <vector <int> > data(MAXN);
    vector <long long> cnt(MAXN, 0);
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < perms.size(); j++) {
            int x = perms[j] ^ i;
            if (x < MAXN) {
                data[i].push_back(x);
            }
        }
    }
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]--;
        for (int j = 0; j < data[a[i]].size(); j++) {
            sum += cnt[data[a[i]][j]];
        }
    }
    cout << sum << endl;
}