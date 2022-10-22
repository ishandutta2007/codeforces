#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 50;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    vector <string> s(n), t(n);
    vector <vector <set <ll> > > allm(n, vector <set <ll> > (MAXN));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        t[i] = s[i];
        for (int l = min(MAXN - 1, (int) s[i].size()); l > 0; l--) {
            ll mask = 0;
            for (int j = 0; j < l; j++) {
                mask = 2 * mask + s[i][j] - '0';
            }
            set <ll> masks;
            masks.insert(mask);
            for (int j = l; j < s[i].size(); j++) {
                if (s[i][j - l] == '1') {
                    mask -= (1LL << (l - 1));
                }
                mask = 2 * mask + s[i][j] - '0';
                masks.insert(mask);
            }
            allm[i][l] = masks;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        allm.push_back(vector <set <ll> > (MAXN));
        t.push_back("");
        s.push_back("");
        int a, b;
        cin >> a >> b;
        a--, b--;
        string res = t[a] + s[b];\
        for (ll k = 0; k < MAXN; k++) {
            for (ll mask : allm[a][k]) {
                allm[i + n][k].insert(mask);
            }
            for (ll mask : allm[b][k]) {
                allm[i + n][k].insert(mask);
            }
        }
        for (int l = min(MAXN - 1, (int) res.size()); l > 0; l--) {
            ll mask = 0;
            for (int j = 0; j < l; j++) {
                mask = 2 * mask + res[j] - '0';
            }
            allm[i + n][l].insert(mask);
            for (int j = l; j < res.size(); j++) {
                if (res[j - l] == '1') {
                    mask -= (1LL << (l - 1));
                }
                mask = 2 * mask + res[j] - '0';
                allm[i + n][l].insert(mask);
            }
        }
        ll ans = 0;
        for (ll l = MAXN - 1; l >= 0; l--) {
            if (allm[i + n][l].size() == (1LL << l)) {
                ans = l;
                break;
            }
        }
        t[i + n] = t[b];
        if (t[i + n].size() < MAXN) {
            t[i + n] = t[a] + t[i + n];
            if (t[i + n].size() > MAXN) {
                t[i + n] = t[i + n].substr(t[i + n].size() - MAXN, MAXN);
            }
        }
        s[i + n] = s[a];
        if (s[i + n].size() < MAXN) {
            s[i + n] += s[b];
            if (s[i + n].size() > MAXN) {
                s[i + n] = s[i + n].substr(0, MAXN);
            }
        }
        cout << ans << "\n";
    }
}