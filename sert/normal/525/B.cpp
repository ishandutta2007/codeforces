#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

set <int> s;
string t;
int n, x;
bool turn;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> t >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        x--;
        if (s.find(x) != s.end())
            s.erase(x);
        else
            s.insert(x);
    }

    s.insert(t.length() + 34);

    for (int i = 0; i < t.length(); i++) {
        if (i == *(s.begin())) {
            turn = !turn;
            s.erase(s.begin());
        }
        if (turn && i < t.length() / 2)
            swap(t[i], t[t.length() - i - 1]);
        cout << t[i];
    }

    return 0;
}