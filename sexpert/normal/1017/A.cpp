#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int n;
    cin >> n;
    vector<ii> v;
    for(int i = 0; i < n; i++) {
        int s = 0;
        for(int j = 0;j < 4; j++) {
            int x;
            cin >> x;
            s -= x;
        }
        v.push_back({s, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        if(v[i].second == 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}