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
void solve(){
    int n;
    cin >> n;
    vector<string> s(2);
    vector<int> seen(n);
    cin >> s[0] >> s[1];
    int res = 0;
    for (int j = 0; j < n; ++j) {
        if (s[1][j] + s[0][j] == '0' + '1') {
            seen[j] = 1;
            res += 2;
            continue;
        }
        if (s[0][j] == '0') {
            res++;
            if (j and seen[j - 1] == 0 and s[0][j-1] == '1') {
                res++;
            }
            else if (j + 1 < n and s[0][j + 1] == '1' and s[1][j + 1] == '1') {
                res++;
                seen[j + 1] = 1;
            }
        }
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}