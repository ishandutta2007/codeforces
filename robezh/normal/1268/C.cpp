#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef pair<int, int> P;
typedef long long ll;

int n;
int a[N];
P p[N];

struct BIT {
    int n;
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

} bit;

struct S {
    priority_queue<int, vector<int>, greater<int> > R;
    priority_queue<int> L;
    ll lsum = 0, rsum = 0;

    void insert(int x) {
        if(R.empty() || x >= R.top()) {
            R.push(x);
            rsum += x;
        }
        else {
            L.push(x);
            lsum += x;
        }
        while(L.size() < (L.size() + R.size()) / 2) {
            int v = R.top(); R.pop();
            rsum -= v;
            lsum += v;
            L.push(v);
        }
        while(L.size() > (L.size() + R.size()) / 2) {
            int v = L.top(); L.pop();
            lsum -= v;
            rsum += v;
            R.push(v);
        }
    }

    ll gc(int x) {
        return 1LL * (1 + x) * x / 2;
    }

    ll getsum() {
        ll res;
        if(R.size() > L.size()) {
            int v = R.top(); R.pop();
            rsum -= v;
            res = (rsum - 1LL * R.size() * v - gc(R.size())) + (1LL * L.size() * v - lsum - gc(L.size()));
            rsum += v;
            R.push(v);
        }
        else {
            int v = L.top(); L.pop();
            lsum -= v;
            res = (rsum - 1LL * R.size() * v - gc(R.size())) + (1LL * L.size() * v - lsum - gc(L.size()));
            lsum += v;
            L.push(v);
        }
        return res;
    }
} st;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p, p + n);

    bit.n = n;

    ll cur_inv = 0;
    for(int i = 0; i < n; i++) {
        cur_inv += i - bit.get(p[i].second - 1);
        bit.add(p[i].second, 1);

        st.insert(p[i].second);
        cout << cur_inv + st.getsum() << " ";
    }

}