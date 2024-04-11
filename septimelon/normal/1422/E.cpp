#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
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

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    s += "##";
    vector<string> f10(n + 5, ""), l2(n + 5, "");
    vector<int> stay(n + 5, 0);
    vector<bool> ng(n + 5, false);
    vector<bool> nd(n + 5, false);
    for (int i = n - 1; i >= 0; --i) {
        if (!nd[i + 1] && s[i] == s[i + 1] && !ng[i + 1]) {
            f10[i] = f10[i + 2];
            l2[i] = l2[i + 2];
            stay[i] = stay[i + 2];
            ng[i] = ng[i + 2];
            nd[i] = true;
        }
        else {
            f10[i] = (s.substr(i, 1) + f10[i + 1]).substr(0, 10);
            l2[i] = s.substr(i, 1) + l2[i + 1];
            while (l2[i].size() > 2) {
                l2[i] = l2[i].substr(1, 2);
            }
            stay[i] = stay[i + 1] + 1;
            if (stay[i + 1] == 0 || s[i] > f10[i + 1][0] || (s[i] == f10[i + 1][0] && !ng[i + 1])) {
                ng[i] = false;
            }
            else {
                ng[i] = true;
            }
            nd[i] = false;
        }
        //cout << s[i] << ": " << f10[i] << " " << l2[i] << " " << stay[i] << " " << ng[i] << " " << nd[i] << "\n";
    }

    for (int i = 0; i < n; ++i) {
        cout << stay[i] << " ";
        if (stay[i] < 11) {
            cout << f10[i] << "\n";
        }
        else {
            cout << f10[i].substr(0, 5) << "..." << l2[i] << "\n";
        }
    }

    return 0;
}