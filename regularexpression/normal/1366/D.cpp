#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

#define ll long long

int n;
int sv[11111111];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    iota(sv, sv + 11111111, 0);
    for (int i = 2; i < 11111111; i++) {
        if (sv[i] == i) {
            for (int j = i+i; j < 11111111; j += i) {
                if (i < sv[j]) sv[j] = i;
            }
        }
    }
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vector<int> f;
        while (a != 1) {
            f.pb(sv[a]);
            a /= sv[a];
        }
        if (f[0] == f.back()) ans.pb({-1, -1}); else {
            int d = 1;
            for (auto e : f) {
                if (e != f[0]) d *= e;
            }
            ans.pb({f[0], d});
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i].x << " ";
    cout << '\n';
    for (int i = 0; i < n; i++) cout << ans[i].y << " ";
    return 0;
}