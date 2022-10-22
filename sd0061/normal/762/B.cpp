#include <bits/stdc++.h>
using namespace std;


int main() {
    int a , b , c;
    cin >> a >> b >> c;
    int res = 0;
    long long sum = 0;
    vector< pair<int , int> > V;
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        string s;
        cin >> x >> s;
        V.push_back({x , s[0] == 'U'});
    }
    sort(V.begin() , V.end());
    for (auto &it : V) {
        if (it.second == 1) {
            if (a || c) {
                res ++;
                sum += it.first;
                if (a) {
                    -- a;
                } else {
                    -- c;
                }
            }
        } else {
            if (b || c) {
                res ++;
                sum += it.first;
                if (b) {
                    -- b;
                } else {
                    -- c;
                }
            }
        }
    }
    cout << res << ' ' << sum << endl;
}