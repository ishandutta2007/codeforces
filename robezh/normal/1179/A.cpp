#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)1e5 + 50;

int n, m;
deque<int> que;
vector<P> res;
int mxi = 0, mx = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        que.push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(que[i] > que[mxi]) mxi = i;
    }
    mx = que[mxi];
    res.push_back({0, 0});
    while(que.front() != mx) {
        int a = que.front(); que.pop_front();
        int b = que.front(); que.pop_front();
        res.push_back({a, b});
        if(a <= b) swap(a, b);
        que.push_front(a);
        que.push_back(b);
    }
    while(m--) {
        ll x; cin >> x;
        if(x < res.size()) cout << res[x].first << " " << res[x].second << "\n";
        else {
            x -= (int)res.size() - 1;
            x--;
            cout << que.front() << " " << que[1 + x % (n - 1)] << "\n";
        }
    }
}