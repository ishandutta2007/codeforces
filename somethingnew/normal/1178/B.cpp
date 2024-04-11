#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1] and s[i] == 'v')
            cnt++;
    }
    long long cnt2 = 0;
    long long res = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1] and s[i] == 'v')
            cnt2++;
        if (s[i] == 'o') {
            res += cnt2 * (cnt - cnt2);
        }
    }
    cout << res << '\n';
}