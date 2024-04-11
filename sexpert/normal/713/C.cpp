#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef priority_queue<int> pq;

struct fn {
    ll a, b;
    pq slp;

    fn(ll a, ll b) : a(a), b(b), slp(pq()) {}
};

void merge(fn &f1, fn &f2) {
    f1.a += f2.a;
    f1.b += f2.b;
    while(f2.slp.size()) {
        int x = f2.slp.top();
        f2.slp.pop();
        f1.slp.push(x);
    }
}

void minimize(fn &f) {
    while(f.a > 0) {
        int ch = f.slp.top();
        f.a--;
        f.b += ch;
        f.slp.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] -= i;
    }
    fn f(0, 0);
    for(int i = 0; i < n; i++) {
        fn g(1, -v[i]);
        g.slp.push(v[i]);
        g.slp.push(v[i]);
        merge(f, g);
        minimize(f);
    }
    cout << f.b << '\n';
}