#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    set<int> s;
    //for(int i = n - 1; i >= 0; i--) {
    for(int i = 0; i < n; i++) {
        auto it = s.lower_bound(a[i]);
        if(it != s.end()) {
            s.erase(it);
            s.insert(a[i]);
        } else {
            s.insert(a[i]);
        }
        //cout << s.size() << endl;
    }

    cout << s.size();
}