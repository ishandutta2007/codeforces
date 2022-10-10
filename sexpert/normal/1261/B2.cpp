#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int bit[MAXN], ans[MAXN], arr[MAXN];

struct qry {
    int k, p, idx;
    bool operator< (const qry &o) const {
        return tie(k, p, idx) < tie(o.k, o.p, o.idx);
    }
};

vector<qry> qs;

void upd(int p, int v) {
    for(; p < MAXN; p += (p & -p))
        bit[p] += v;
}

int find(int s) {
    int p = 0;
    for(int l = 20; l >= 0; l--) {
        //cout << p << " " << s << endl;
        if(p + (1 << l) < MAXN && bit[p + (1 << l)] < s) {
            s -= bit[p + (1 << l)];
            p += (1 << l);
        }
    }
    return p + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] *= -1;
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return tie(arr[a], a) < tie(arr[b], b);
    });
    int cur = -1;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int k, p;
        cin >> k >> p;
        k--;
        qs.push_back({k, p, i});
    }
    sort(qs.begin(), qs.end());
    for(auto qry : qs) {
        int k = qry.k, pos = qry.p;
        while(cur < k) {
            cur++;
            //cout << "upded " << ord[cur] + 1 << endl;
            upd(ord[cur] + 1, 1);
        }
        ans[qry.idx] = -arr[find(pos) - 1];
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}