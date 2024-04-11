#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n;

vi compose(const vi &p2, const vi &p1) {
    vi res(n);
    for(int i = 0; i < n; i++)
        res[i] = p2[p1[i]];
    return res;
}

vi iterate(vi p, int e) {
    vi res(n);
    iota(res.begin(), res.end(), 0);
    while(e) {
        if(e & 1) res = compose(p, res);
        p = compose(p, p);
        e >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    n = s.size();
    vi shift(n);
    iota(shift.begin(), shift.end(), -1);
    shift[0] = n - 1;
    int m;
    cin >> m;
    while(m--) {
        int k, d;
        cin >> k >> d;
        vi perm(n), pre(d);
        iota(perm.begin(), perm.end(), 0);
        pre[0] = 0;
        for(int i = 1; i < d; i++)
            pre[i] = pre[i - 1] + (k - i)/d + 1;
        for(int i = 0; i < k; i++) {
            int a = i / d , b = i % d;
            perm[i] = a + pre[b]; 
        }
        vi q = compose(shift, perm);
        vi res = iterate(q, n - k + 1);
        string t = s;
        for(int i = 0; i < n; i++)
            t[(res[i] + n - k + 1)%n] = s[i];
        s = t;
        cout << s << '\n';
    }
}