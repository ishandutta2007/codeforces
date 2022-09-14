#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bitset>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using ld = long double;
using namespace std;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    string s;
    cin >> n >> s;
    while (1) {
        int pos = -1;
        rep(i, s.size())
            if ((i > 0 && s[i] - s[i - 1] == 1 || i + 1 < s.size() && s[i] - s[i + 1] == 1) && (pos == -1 || s[i] > s[pos]))
                pos = i;
        if (pos < 0)
            break;
        s = s.substr(0, pos) + s.substr(pos + 1);
    }
    cout << n - s.size();
}