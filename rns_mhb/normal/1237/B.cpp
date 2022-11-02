#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int main() {
    int n;
    cin >> n;
    vector <pii> v(n);
    for(int i = 0, x; i < n; i ++) cin >> x, v[x-1].second = i;
    for(int i = 0, x; i < n; i ++) cin >> x, v[x-1].first = i;
    sort(v.begin(), v.end());
    set <int> s;
    int ans = 0;
    for(int i = n-1, j = n-1; i >= 0; i = j) {
        while(j >= 0 && v[i].first == v[j].first) j --;
        for(int k = i; k > j; k --) if(s.lower_bound(v[k].second) != s.begin()) ans ++;
        for(int k = i; k > j; k --) s.insert(v[k].second);
    }
    cout << ans << endl;
}