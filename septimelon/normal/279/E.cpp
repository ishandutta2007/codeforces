#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    
    s.push_back('0');
    s.push_back('0');
    int ans = 0;
    int f1 = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            if (f1 == -1) {
                f1 = i;
            }
        }
        if (s[i] == '0') {
            if (f1 == i - 1) {
                ++ans;
                f1 = -1;
            }
            else if (f1 >= 0) {
                if (s[i - 1] == '1') {
                    ++ans;
                }
                else {
                    ++ans;
                    f1 = -1;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}