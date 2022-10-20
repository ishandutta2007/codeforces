// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;
const long long LM = 1LL << 60;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, k;
        long long x;
        string s;
        cin >> n >> k >> x >> s;
        vector<int> v;
        int c = 0;
        for (auto& i : s) {
            if (i == 'a') {
                if (c > 0) {
                    v.push_back(c);
                }
                c = 0;
            }
            else {
                ++c;
            }
        }
        if (c > 0) {
            v.push_back(c);
        }
        vector<int> cnt(v.size());
        --x;
        for (int i = (int)v.size() - 1; i >= 0; --i) {
            int y = v[i] * k + 1;
            cnt[i] = x % y;
            x /= y;
        }
        string t = "";
        int j = 0;
        c = 0;
        for (auto& i : s) {
            if (i == 'a') {
                if (c > 0) {
                    if (cnt[j] > 0)
                        t += string(cnt[j], 'b');
                    ++j;
                }
                t += "a";
                c = 0;
            }
            else {
                ++c;
            }
        }
        if (c > 0) {
            if (cnt[j] > 0)
                t += string(cnt[j], 'b');
        }
        cout << t << '\n';
    }
    return 0;
}