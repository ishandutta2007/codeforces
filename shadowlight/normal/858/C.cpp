#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

set <char> good = { 'a', 'e', 'i', 'o', 'u'};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    string s;
    cin >> s;
    string ans = "";
    string add = "";
    for (char c : s) {
        if (good.find(c) != good.end()) {
            ans += add + c;
            add = "";
            continue;
        }
        if (add.size() < 2) {
            add += c;
        } else {
            if (add[0] == add[1] && add[1] == c) {
                ans += c;
            } else {
                ans += add + " ";
                add = c;
            }
        }
    }
    cout << ans + add;
}