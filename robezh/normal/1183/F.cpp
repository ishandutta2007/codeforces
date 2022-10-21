#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int T;
int n;
set<int, greater<> > S;

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        S.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            int a; cin >> a; S.insert(a);
        }

        int res = 0;
        int mx = *S.begin();
        if(S.count(mx / 2) && S.count(mx / 3) && S.count(mx / 5)) {
            res = mx / 2 + mx / 3 + mx / 5;
        }
        vector<int> v;
        v.push_back(*S.begin());
        S.erase(*S.begin());
        while(!S.empty() && v.size() < 3) {
            for(auto it = S.begin(); it != S.end();) {
                bool dvd = false;
                int x = *it;
                for(int d : v) if(d % x == 0) {
                    dvd = true;
                    break;
                }
                it = S.erase(it);
                if(!dvd) {
                    v.push_back(x);
                    break;
                }
            }
        }
        res = max(res, accumulate(v.begin(), v.end(), 0));
        cout << res << "\n";
    }
}