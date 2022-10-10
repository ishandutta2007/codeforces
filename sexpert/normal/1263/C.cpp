#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MA = 50000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> all;
        for(int i = 1; i < MA; i++)
            all.insert(n/i);
        for(int i = 1; i < MA; i++) {
            if(n/i > (n + i)/(i + 1))
                all.insert(i);
        }
        all.insert(0);
        cout << all.size() << '\n';
        for(auto x : all)
            cout << x << " ";
        cout << '\n';
    }
}