#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

void refresh(priority_queue<pair<int, int>>& que, int incl) {
    while (que.size() > 0 && que.top().second < incl) {
        que.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll w, n, k;
    cin >> n >> w >> k;
    vector<ll> a(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<bool> lon(n, true);
    priority_queue<pair<int, int>> shor, lonn;
    int incl = 0;
    ll tott = 0LL;
    ll tota = 0LL;
    int cw = 0;
    ll mans = 0;
    for (int it = 0; it < n; ++it) {
        tott += t[it];
        tota += a[it];
        if (cw == w) {
            lonn.push({ t[it], it });
        }
        else {
            lon[it] = false;
            shor.push({ INF - t[it], it });
            tott -= t[it] / 2;
            ++cw;
        }
        refresh(lonn, incl);
        refresh(shor, incl);
        if (shor.size() > 0 && lonn.size() > 0 && INF - shor.top().first < lonn.top().first) {
            lon[lonn.top().second] = false;
            tott -= lonn.top().first / 2;
            shor.push({ INF - lonn.top().first, lonn.top().second });
            lonn.pop();
            lon[shor.top().second] = true;
            tott += (INF - shor.top().first) / 2;
            lonn.push({ INF - shor.top().first, shor.top().second });
            shor.pop();
        }
        while (tott > k) {
            //cout << tott << ", ";
            tott -= t[incl];
            tota -= a[incl];
            if (!lon[incl]) {
                tott += t[incl] / 2;
                --cw;
            }
            ++incl;
            refresh(lonn, incl);
            if (cw < w && lonn.size() > 0) {
                lon[lonn.top().second] = false;
                tott -= lonn.top().first / 2;
                shor.push({ INF - lonn.top().first, lonn.top().second });
                lonn.pop();
                ++cw;
            }
            //cout << it << "|" << incl << "\n";
        }
        //cout << it << ": " << tota << "\n";
        mans = max(mans, tota);
    }

    cout << mans << "\n";

    return 0;
}