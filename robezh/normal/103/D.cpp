#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, SQRT = 550;

struct query {
    int a, id;
};

int n,q;
int w[N];
ll sum[N];

ll res[N];
vector<query> qrys[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--;
        qrys[b].push_back({a, i});
    }
    for(int b = 1; b < SQRT; b++) {
        if(qrys[b].empty()) continue;
        for(int j = 0; j < min(b, n); j++) sum[j] = w[j];
        for(int j = b; j < n; j++) sum[j] = w[j] + sum[j-b];
        for(const auto &p : qrys[b]) {
            if(n-1 < p.a) res[p.id] = 0;
            else {
                res[p.id] = sum[(n-1-p.a)/b * b + p.a];
//                cout << p.id << " " << res[p.id] << " " << (n-1-p.a)/b << " " <<  p.a << endl;
                if(p.a - b >= 0) res[p.id] -= sum[p.a - b];
//                cout << p.id << " " << res[p.id] << endl;
            }
        }
    }
    for(int b = SQRT; b <= n; b++) {
        for(const auto &p : qrys[b]) {
            ll tot = 0;
            for(int j = p.a; j < n; j += b) tot += w[j];
            res[p.id] = tot;
        }
    }
    for(int i = 0; i < q; i++) cout << res[i] << "\n";
}