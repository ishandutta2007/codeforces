#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int toI(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    if (c == '0') {
        return 'o' - 'a';
    }
    if (c == '1') {
        return 'i' - 'a';
    }
    return -1;
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
    string s;
    cin >> s;
    int n = s.size();
    int z;
    cin >> z;
    map <char, vector <char> > bad;
    for (int i = 0; i < z; i++) {
        string t;
        cin >> t;
        if (s.size() != t.size()) continue;
        bool fl = true;
        for (int pos = 0; pos < n; pos++) {
            char a = s[pos], b = t[pos];
            int x = toI(a), y = toI(b);
            if (x > y) {
                swap(x, y);
            }
            if ((x == y) || (x == 'i' - 'a' && y == 'l' - 'a')) {
                continue;
            }
            fl = false;
            break;
        }
        if (fl) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}