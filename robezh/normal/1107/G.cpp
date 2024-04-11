#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;
const ll INF = (ll)1e18;
typedef pair<ll, ll> pl;

int n,a;
ll d[N], c[N];

ll solve(int l, int r) {
    if(l > r) return INF;
    if(l == r) return c[l];
    int mid = (l + r) / 2;
    vector<pl> dl, dr;
    for(int i = mid - 1; i >= l; i--) {
        dl.push_back(dl.empty() ? make_pair(abs(d[i + 1] - d[i]), c[i]) :
                     make_pair(max(abs(d[i + 1] - d[i]), dl.back().first), c[i] + dl.back().second));
    }
    dr.push_back({0, c[mid]});
    for(int i = mid + 1; i <= r; i++) {
        dr.push_back(dr.empty() ? make_pair(abs(d[i] - d[i-1]), c[i]) :
                     make_pair(max(abs(d[i] - d[i-1]), dr.back().first), c[i] + dr.back().second));
    }

    sort(dl.begin(), dl.end());
    sort(dr.begin(), dr.end());
//    cout << "dl :";
//    for(auto p : dl) cout << "{" << p.first << ", " << p.second << "}" << " ";
//    cout << endl;
//    cout << "dr :";
//    for(auto p : dr) cout << "{" << p.first << ", " << p.second << "}" << " ";
//    cout << endl;

    ll res = c[mid];
//    for(auto p : dr) res = min(res, p.first * p.first + p.second);
    int tr = 0;
    ll mn = 0;
    for(int i = 0; i < dl.size(); i++) {
        while(tr < dr.size() && dr[tr].first <= dl[i].first) {
            mn = min(mn, dr[tr].second);
            tr++;
        }
        res = min(res, 1LL * dl[i].first * dl[i].first + dl[i].second + mn);
    }
    int tl = 0;
    mn = 0;
    for(int i = 0; i < dr.size(); i++) {
        while(tl < dl.size() && dl[tl].first <= dr[i].first) {
            mn = min(mn, dl[tl].second);
            tl ++;
        }
        res = min(res, 1LL * dr[i].first * dr[i].first + dr[i].second + mn);
    }
    res = min(res, min(solve(l, mid - 1), solve(mid + 1, r)));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a;
    for(int i = 0; i < n; i++) cin >> d[i] >> c[i], c[i] -= a;

    cout << max(0LL, -solve(0, n-1)) << endl;

}