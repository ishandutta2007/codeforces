#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void solve() {

}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    vector<int> a(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ind = -1;
    vector<pair<int, int>> b;
    for(int i = 0; i < n; i++) {
        string t = s[i];
        reverse(t.begin(), t.end());
        for(int j = i + 1; j < n; j++)
            if(t == s[j]) {
                a[j] = i;
                a[i] = j;
                b.emplace_back(i, j);
                break;
            }

        if(a[i] == -1) {
            if(s[i] == t) {
                ind = i;
                a[i] = i;
            }
        }
    }

    string ans ="";
    for(int i = 0; i < b.size(); i++)
        ans += s[b[i].f];

    if(ind != -1)
        ans += s[ind];
    for(int i = b.size() - 1; i >= 0; i--)
        ans += s[b[i].s];

    cout << ans.size() << endl << ans;

//    int t;
//    cin >> t;
//    while(t--)
//        solve();
}