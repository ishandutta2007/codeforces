#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<li> a(n);
    map<li, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    auto it = mp.begin();
    while(it != mp.end()) {
        li x = it->f;
        vector<int> b = it->s;
        sort(b.begin(), b.end());

        for(int i = 1; i < b.size(); i += 2) {
            a[b[i - 1]] = -1;
            a[b[i]] = x * 2;
            mp[x * 2].push_back(b[i]);
        }

        it = mp.upper_bound(x);
    }

    vector<li> c;
    for(int i = 0; i < n; i++)
        if(a[i] != -1)
            c.push_back(a[i]);

    cout << c.size() << endl;
    for(auto x : c)
        cout << x << ' ';
    cout << endl;
}