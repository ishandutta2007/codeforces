#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

string s;
ll n;

bool check(ll sum) {
    ll now = 0;
    for (ll i = 0; i < n; i++) {
        now += s[i] - '0';
        if (now > sum) {
            return false;
        }
        if (now == sum) {
            now = 0;
        }
    }
    return now == 0;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> s;
    ll ms = 0;
    for (char c : s) {
        ms += c - '0';
    }
    if (!ms) {
        cout << "YES\n";
        return 0;
    }
    for (ll sum = 1; sum < ms; sum++) {
        if (check(sum)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}