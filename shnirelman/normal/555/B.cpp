#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
4 1
4 1 2 3 4

4 4
1 1
1 2
1 3
1 4
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<li, li>> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i].f >> b[i].s;
    }

    vector<pair<li, int>> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(a.begin(), a.end());

    vector<pair<li, li>> c(n - 1);
    map<pair<li, li>, vector<int>> mp;
    for(int i = 1; i < n; i++) {
        li l = b[i].f - b[i - 1].s;
        li r = b[i].s - b[i - 1].f;

        c[i - 1] = {l, r};
        mp[c[i - 1]].push_back(i - 1);
//        cout << l << ' ' <<r << endl;
    }

//    cout << endl;
    n--;

    sort(c.begin(), c.end());

//    for(int i = 0; i < n;i++) {
//        cout << c[i].f << ' ' << c[i].s << endl;
//    }

    multiset<pair<li, li>> sc;
//    set<li> sa(a.begin(), a.end());
    int j = 0;
    vector<int> ans(n, -1);
    int cnt = 0;
    for(int i = 0; i < m; i++) {
//        while(!sa.empty() && )
        while(j < n && c[j].f <= a[i].f) {
            sc.insert({c[j].s, c[j].f});
            j++;
        }

        while(!sc.empty() && sc.begin()->f < a[i].f)
            sc.erase(sc.begin());

        if(sc.empty())
            continue;

        li l = sc.begin()->s;
        li r = sc.begin()->f;

        ans[mp[{l, r}].back()] = a[i].s;
        mp[{l, r}].pop_back();
        sc.erase(sc.begin());
        cnt++;
    }

    if(cnt < n) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(int i = 0; i < n; i++) {
            cout << ans[i] + 1 << ' ';
        }
    }
}