#include <bits/stdc++.h>
using namespace std;

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, mx = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    stack<int> s;
    for (int i=0; i<n;) {
        if (a[i] == mx)
            i++;
        else {
            int j = i;
            while (j < n && a[j] != mx) {
                if (!s.empty() && s.top() == a[j])
                    s.pop();
                else if (s.empty() || s.top() > a[j])
                    s.push(a[j]);
                else {
                    cout << "NO\n";
                    return 0;
                }
                j++;
            }
            if (!s.empty()) {
                cout << "NO\n";
                return 0;
            }
            i = j;
        }
    }
    cout << "YES\n";

    return 0;
}