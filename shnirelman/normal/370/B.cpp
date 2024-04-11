#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<set<int>> a(n);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;

            a[i].insert(x);
        }
    }

    vector<bool> b(n, true);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(i != j) {
                bool fl = false;
                for(auto x : a[i])
                    if(a[j].count(x) == 0) {
                        fl = true;
                        break;
                    }
                if(!fl)
                    b[j] = false;
            }
    }

    for(int i = 0; i < n; i++)
        cout << (b[i] ? "YES" : "NO") << endl;
}