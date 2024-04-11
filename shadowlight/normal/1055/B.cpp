#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
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
    ll n, m, l;
    cin >> n >> m >> l;
    set <pair <ll, ll> > segs;
    vector <ll> a(n);
    ll lt = -1, rt = -1;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > l) {
            rt = i;
            if (lt == -1) lt = i;
        } else {
            if (lt != -1) {
                segs.insert({lt, rt});
            }
            lt = -1, rt = -1;
        }
    }
    if (lt != -1) {
        segs.insert({lt, rt});
    }
    for (ll i = 0; i < m; i++) {
        ll tp;
        cin >> tp;
        if (!tp) {
            cout << segs.size() << "\n";
            continue;
        }
        ll p, d;
        cin >> p >> d;
        p--;
        a[p] += d;
        if (a[p] - d <= l && a[p] > l) {
            ll lt = p, rt = p;
            auto it = segs.lower_bound({p, INF});
            vector <pair <ll, ll> > er;
            if (it != segs.end() && (*it).first == p + 1) {
                rt = (*it).second;
                er.push_back(*it);
            }
            if (it != segs.begin()) {
                it--;
                if ((*it).second == p - 1) {
                    lt = (*it).first;
                    er.push_back(*it);
                }
            }
            for (auto t : er) {
                segs.erase(t);
            }
            segs.insert({lt, rt});
        }
    }
}