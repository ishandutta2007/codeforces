#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <numeric>
#include <deque>
#include <queue>
typedef long long l;
typedef long double ld;
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size(), t;
    s += s;
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);
    int ans = 0;
    vector<int> cnt(26);
    for (int c = 0; c < 26; c++) {
        int bk = 0;
        for (int i = 1; i < n; i++) {
            int k = 0;
            for (int j : pos[c]) {
                t = s[j + i] - 'a';
                cnt[t]++;
            }
            for (int j : pos[c]) {
                t = s[j + i] - 'a';
                if (cnt[t] == 1)
                    k++;
                cnt[s[j + i] - 'a'] = 0;
            }
            bk = max(bk, k);
        }
        ans += bk;
    }
    cout << fixed << setprecision(8) << (ld) ans / n;
}