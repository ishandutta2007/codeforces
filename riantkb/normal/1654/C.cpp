// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        map<long long, int> mp;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            ++mp[a];
            sum += a;
        }
        queue<long long> q;
        q.push(sum);
        for (int _ = 0; _ < n - 1; ++_) {
            if (q.empty()) {
                cout << "NO\n";
                goto A;
            }
            long long p = q.front();
            q.pop();
            while (mp[p] > 0) {
                --mp[p];
                if (q.empty()) {
                    cout << "NO\n";
                    goto A;
                }
                p = q.front();
                q.pop();
            }
            long long a = p / 2;
            long long b = (p + 1) / 2;
            q.push(a);
            q.push(b);
        }
        while (q.size()) {
            long long p = q.front();
            q.pop();
            if (mp[p] > 0) {
                --mp[p];
            }
            else {
                cout << "NO\n";
                goto A;
            }
        }
        for (auto& i : mp) {
            if (i.second) {
                cout << "NO\n";
                goto A;
            }
        }
        cout << "YES\n";
        A: continue;
    }
    return 0;
}