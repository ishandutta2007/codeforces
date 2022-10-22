#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    set<string> s(a.begin(), a.end());
    cout << n - s.size() << endl;

    for(int i = 0; i < n; i++) {
        bool fl = false;
        for(int j = 0; j < i; j++)
            if(a[i] == a[j]) {
                fl = true;
            }

        if(!fl) {
            cout << a[i] << endl;
            continue;
        }

        string t = a[i];
        for(char l = '0'; l <= '9'; l++) {
            t[0] = l;
            if(!s.count(t)) {
                a[i] = t;
                s.insert(a[i]);
                break;
            }
        }

        cout << a[i] << endl;
    }

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}