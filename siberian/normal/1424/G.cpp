#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

struct Event{
    int x, t;
};

bool operator<(const Event& a, const Event& b) {
    return tie(a.x, a.t) < tie(b.x, b.t);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
    int n;
    cin >> n;
    vector<Event> a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.push_back({l, 1});
        a.push_back({r, -1});
    } 
    sort(all(a));
    int cnt = 0;
    int ansX = 0, ansCnt = 0;
    for (auto i : a) {
        cnt += i.t;
        if (cnt > ansCnt) {
            ansCnt = cnt;
            ansX = i.x;
        }
    }
    cout << ansX << " " << ansCnt << endl;
	return 0;
}