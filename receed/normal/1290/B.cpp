#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200002;
char s[N];
int c[N][26];
vector<int> a;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
    int n = strlen(s), q, l, r;
    rep(i, n) {
        rep(j, 26)
            c[i + 1][j] = c[i][j];
        c[i + 1][s[i] - 'a']++;
    }
    cin >> q;
    rep(z, q) {
        cin >> l >> r;
        l--;
        int k = 0;
        rep(i, 26)
            if (c[r][i] - c[l][i])
                k++;
        if (r - l == 1 || k == 2 && s[l] != s[r - 1] || k > 2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}