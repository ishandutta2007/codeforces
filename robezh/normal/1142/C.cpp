#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef double ld;

const int N = (int)1e5 + 50;

struct P {
    ll x, y;
} p[N];

int x[N], y[N];
int n;
deque<int> que;

Pll slp(int i, int j) {
    return {p[j].y - p[i].y, p[j].x - p[i].x};
}

bool leq(Pll a, Pll b) {
    return a.first * b.second <= a.second * b.first;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        p[i].x = x[i];
        p[i].y = y[i] - 1LL * x[i] * x[i];
    }
    sort(p, p + n, [](const P &p1, const P &p2) {
        return p1.x < p2.x;
    });
    for(int i = 0; i < n; i++) {
        if(i != 0 && p[i-1].x == p[i].x) {
            if(p[que.back()].y >= p[i].y) continue;
            else que.pop_back();
        }
        
        while(que.size() > 1) {
            int ls = que.size() - 1;
            if(leq(slp(que[ls-1], que[ls]), slp(que[ls], i))) que.pop_back();
            else break;
        }
        que.push_back(i);
    }
    cout << que.size() - 1 << endl;
}