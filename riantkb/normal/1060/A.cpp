#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(10);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - '0'];
    }
    cout << min(n / 11, cnt[8]) << "\n";
    return 0;
}