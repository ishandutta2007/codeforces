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
        string s;
        cin >> s;
        int c = 0;
        for (auto& i : s) {
            c += i == 'N';
        }
        cout << (c == 1 ? "NO" : "YES") << '\n';
    }
    return 0;
}