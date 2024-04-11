#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    str s, t; cin >> s >> t;
    int ij = 0, j = 0;
    while (s[ij] == '0') ij++;
    while (t[j] == '0') j++;
    if (s.size() - ij > t.size() - j) {
        cout << '>';
    } else if (s.size() - ij < t.size() - j) {
        cout << '<';
    } else {
        for (int i = ij; i < s.size(); i++) {
            if (s[i] < t[i-ij+j]) {
                cout << '<'; return 0;
            } else if (s[i] > t[i-ij+j]) {
                cout << '>'; return 0;
            }
        }
        cout << '=';
    }
}