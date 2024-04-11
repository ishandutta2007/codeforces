#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)10005, HF = 5000;

struct P {
    int x, y;
};

struct edge {
    int d, l, r;
};

struct BIT {
    int n;
    int bit[N];

    void clear() {
        memset(bit, 0, sizeof(bit));
    }

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    int get(int l, int r) {
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }

} bit;

int n;
vector<edge> hor, ver;
P p[N];
int nn;
ll res = 0;

int main() {
    bit.n = N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += HF, b += HF, c += HF, d += HF;
        if(a == c) ver.push_back({a, min(b, d), max(b, d)});
        else hor.push_back({b, min(a, c), max(a, c)});
    }
    sort(ver.begin(), ver.end(), [](const edge &e1, const edge &e2) {
        return e1.r < e2.r;
    });
    sort(hor.begin(), hor.end(), [](const edge &e1, const edge &e2) {
        return e1.d < e2.d;
    });
    for(int i = 0; i < hor.size(); i++) {
        bit.clear();
        nn = 0;
        for(auto &e : ver) {
            if(e.l <= hor[i].d && e.r > hor[i].d) {
                p[nn].x = e.r;
                p[nn].y = e.d;
                nn++;
                bit.add(e.d, 1);
            }
        }
        int cur = 0;
        for(int j = i + 1; j < hor.size(); j++) {
            while(cur < nn && p[cur].x < hor[j].d) {
                bit.add(p[cur++].y, -1);
            }
            int l = max(hor[i].l, hor[j].l), r = min(hor[i].r, hor[j].r);
            int sum = bit.get(l, r);
            res += sum * (sum - 1) / 2;
        }
    }
    cout << res << endl;
}