#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        vector<int> cnt(2);
        int n;
        cin >> n;
        while(n--) {
            int x;
            cin >> x;
            cnt[x % 2] = 1;
        }
        if(cnt[0] && cnt[1])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}