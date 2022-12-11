#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e3 + 34;
const ll md = 1e9 + 7;

string s;
int bal;
vector <int> ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> s;

    bal = 0;
    for (int i = s.length() - 1; s[i] != '#'; i--) {
        if (s[i] == '(') bal--;
        else bal++;
        if (bal < 0) {
            cout << -1;
            return 0;
        }
    }

    bal = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            bal++;
        else
            bal--;
        if (bal < 0) {
            cout << -1;
            return 0;
        }
        if (s[i] == '#')
            ans.push_back(1);
    }

    ans.back() += bal;

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

    //return 0;
}