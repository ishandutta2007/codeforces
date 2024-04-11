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
        long long w, h;
        cin >> w >> h;
        vector<long long> x1;
        {
            int k;
            cin >> k;
            x1 = vector<long long>(k);
            for (int i = 0; i < k; ++i) {
                cin >> x1[i];
            }
        }
        vector<long long> x2;
        {
            int k;
            cin >> k;
            x2 = vector<long long>(k);
            for (int i = 0; i < k; ++i) {
                cin >> x2[i];
            }
        }
        vector<long long> y1;
        {
            int k;
            cin >> k;
            y1 = vector<long long>(k);
            for (int i = 0; i < k; ++i) {
                cin >> y1[i];
            }
        }
        vector<long long> y2;
        {
            int k;
            cin >> k;
            y2 = vector<long long>(k);
            for (int i = 0; i < k; ++i) {
                cin >> y2[i];
            }
        }
        long long ans = max(max(x1[(int)x1.size() - 1] - x1[0], x2[(int)x2.size() - 1] - x2[0]) * h, max(y1[(int)y1.size() - 1] - y1[0], y2[(int)y2.size() - 1] - y2[0]) * w);
        cout << ans << '\n';
    }
    return 0;
}