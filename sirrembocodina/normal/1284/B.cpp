#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

vector<int> a[100100];
bool ok[100100];
int mx[100100];
int mn[100100];
vector<int> mn_srt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    forn (i, n) {
        int l;
        cin >> l;
        a[i].resize(l);
        mx[i] = -1e9;
        mn[i] = 1e9;
        forn (j, l) {
            cin >> a[i][j];
            mn[i] = min(mn[i], a[i][j]);
            mx[i] = max(mx[i], a[i][j]);
            if (a[i][j] > mn[i]) {
                ok[i] = true;
            }
        }
        if (!ok[i]) {
            mn_srt.push_back(mn[i]);
        }
    }
    sort(mn_srt.begin(), mn_srt.end());
    long long ans = n * 1ll * n - mn_srt.size() * 1ll * mn_srt.size();
    forn (i, n) {
        if (!ok[i]) {
            ans += lower_bound(mn_srt.begin(), mn_srt.end(), mx[i]) - mn_srt.begin();
        }
    }
    cout << ans << endl;
}