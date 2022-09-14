#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue>
#include <cmath>
#include <cstring>
#include <cassert>
typedef long double ld;
using namespace std;

const int N = 400000;
int g[N][26], cnt[N], term[N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ans = 0, num = 0;
    char c;
    string s = "";
    vector<string> a;
    while ((c = getchar()) != EOF) {
        if ('a' <= c && c <= 'z')
            s += c;
        else {
            ans++;
            if (!s.empty()) {
                a.push_back(s);
                s.clear();
            }
        }
    }
    if (!s.empty())
        a.push_back(s);
    for (string &t : a) {
        int cv = 0, pos = 0, one = -1;
        for (; pos < t.size() && g[cv][t[pos] - 'a']; pos++) {
            if (pos > 0 && one == -1 && cnt[cv] + term[cv] == 1)
                one = pos;
            cv = g[cv][t[pos] - 'a'];
        }
        if (cnt[cv] == 0 && one > -1) {
            ans += one + 1 + (t.size() - pos);
        }
        else
            ans += t.size();
        if (pos < t.size() || !term[cv]) {
            cv = 0;
            for (int i = 0; i < t.size(); i++) {
                cnt[cv]++;
                if (!g[cv][t[i] - 'a'])
                    g[cv][t[i] - 'a'] = ++num;
                cv = g[cv][t[i] - 'a'];
            }
            term[cv] = 1;
        }
    }
    printf("%d", ans);
}