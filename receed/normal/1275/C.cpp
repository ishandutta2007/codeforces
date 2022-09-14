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

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    string s;
    rep(i, n) {
        cin >> s;
        int c0 = 0, c2 = 0, ss = 0;
        for (char c : s) {
            ss = (ss + c - '0') % 3;
            if (c == '0')
                c0++;
            if ((c - '0') % 2 == 0)
                c2++;
        }
        if (ss == 0 && c0 > 0 && c2 > 1)
            cout << "red\n";
        else
            cout << "cyan\n";
    }
}