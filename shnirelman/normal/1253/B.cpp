#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0, c = 0;
    vector<int> b;
    set<int> st, st1;
    for(int i = 0; i < n; i++) {
        if(st.count(a[i])) {
            cout << -1;
            return 0;
        }

        if(a[i] > 0) {
            st.insert(a[i]);
            if(st1.count(a[i])) {
                cout << -1;
                return 0;
            }
            st1.insert(a[i]);
        } else {
            if(!st.count(-a[i])) {
                cout << -1;
                return 0;
            }

            st.erase(-a[i]);
        }

        if(st.size() == 0) {
            b.push_back(st1.size() * 2);
            st1.erase(st1.begin(), st1.end());
        }
    }

    int s = 0;
    for(auto b1 : b)
        s += b1;

    if(s == n) {
        cout << b.size() << endl;
        for(auto b1 : b)
            cout << b1 << ' ';
    } else {
        cout << -1;
    }

}