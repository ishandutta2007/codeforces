#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;

istream& operator >>(istream& cin, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    return cin;
}

ostream& operator <<(ostream& cout, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    return cout;
}

const int M = 1e9 + 7;

void solve() {
//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    cin >> a;

    string s;
    cin >> s;

    for(int i = 2; i < s.size(); i++) {
        set<char> st;
        if(s[i] != '.')
            st.insert(s[i]);
        if(s[i - 1] != '.')st.insert(s[i - 1]);
        if(s[i - 2] != '.')st.insert(s[i - 2]);

        if(st.size() == 3) {
            cout << "Yes";
            exit(0);
        }
    }

    cout << "No";

}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}