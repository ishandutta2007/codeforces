#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

string s;
int n;
bool u[30];
set <char> st;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) st.insert(s[i]);
    if (st.size() < n) cout << "NO\n";
    else {
        cout << "YES";
        for (int i = 0; i < s.length(); i++) {
            if (!u[s[i] - 'a'] && n) {
                n--;
                cout << "\n";
            }
            u[s[i] - 'a'] = true;
            cout << s[i];
        }
    }

    return 0;
}