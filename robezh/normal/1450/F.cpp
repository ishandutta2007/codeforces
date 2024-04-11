#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
int a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        fill(cnt, cnt + n, 0);
        rep(i, 0, n) cin >> a[i], a[i]--, cnt[a[i]]++;
        int bad = 0;
        rep(i, 0, n) bad |= (cnt[i] + cnt[i] - 1 > n);
        if(bad) {
            cout << -1 << '\n';
            continue;;
        }
        fill(cnt, cnt + n, 0);
        int r = 0;
        vector<pii> ss;
        int res = 0 ;
        for(int i = 0; i < n; i = r + 1) {
            r = i;
            while(r + 1 < n && (a[r] != a[r + 1])) r++;
            ss.push_back({a[i], a[r]});
            if(a[i] == a[r]) cnt[a[i]]++;
        }
        int mx = 0;
        rep(i, 1, n) if(cnt[i] > cnt[mx]) mx = i;
        res += sz(ss) - 1;
        int nab = 0, nkk = 0, ncc = 0;
        for(auto &p : ss) {
            if(p.first == p.second) {
                if(p.first == mx) nkk++;
                else ncc++;
            } else if(p.first != mx && p.second != mx) {
                nab++;
            }
        }
        cout << res + max(0, nkk - ncc - nab - 1) << '\n';

    }
}