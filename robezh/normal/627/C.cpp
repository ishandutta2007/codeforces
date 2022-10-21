#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef pair<int, int> P;
typedef long long ll;

ll res = 0;
int d, vol_max, n;
P p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> d >> vol_max >> n;
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    p[n].first = d, p[n].second = 0;
    n++;
    sort(p, p + n);

    deque<int> que;
    int vol = vol_max;
    int la = 0;
    for(int i = 0; i < n; i++) {
        vol -= p[i].first - la;
        while(vol < 0 && !que.empty()) {
            int v = que.front();
            int fil = min(abs(vol), vol_max - (p[i].first - p[v].first - abs(vol)));
            assert(fil >= 0);
            res += 1LL * fil * p[v].second;
            vol += fil;
            if(vol < 0) que.pop_front();
        }
        if(vol < 0) return cout << "-1" << endl, 0;
        while(!que.empty() && p[que.back()].second >= p[i].second) que.pop_back();
        que.push_back(i);
        la = p[i].first;
    }
    cout << res << endl;
}