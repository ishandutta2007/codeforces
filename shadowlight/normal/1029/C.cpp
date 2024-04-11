#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
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
    vector <pair <int, int> > a(n);
    multiset <int> lt, rt;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        lt.insert(a[i].first);
        rt.insert(a[i].second);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int l = a[i].first, r = a[i].second;
        lt.erase(lt.find(l));
        rt.erase(rt.find(r));
        int lmax = *lt.rbegin();
        int rmin = *rt.begin();
        res = max(res, rmin - lmax);
        lt.insert(l);
        rt.insert(r);
    }
    cout << res;
}