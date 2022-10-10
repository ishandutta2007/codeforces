#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 10;
int to[30*MAXN][2], cnt[30*MAXN], sz = 0;

void add(int x) {
    int cur = 0;
    for(int b = 29; b >= 0; b--) {
        cnt[cur]++;
        int d = ((x & (1 << b)) >> b);
        if(!to[cur][d])
            to[cur][d] = ++sz;
        cur = to[cur][d];
    }
    cnt[cur]++;
}

void sub(int x) {
    int cur = 0;
    for(int b = 29; b >= 0; b--) {
        cnt[cur]--;
        int d = ((x & (1 << b)) >> b);
        cur = to[cur][d];
    }
    cnt[cur]--;
}

ii mn(int x) {
    int res = 0, elem = 0, cur = 0;
    for(int b = 29; b >= 0; b--) {
        int d = (x & (1 << b)) >> b;
        if(to[cur][d] && cnt[to[cur][d]] > 0) {
            elem += (1 << b) * d;
            cur = to[cur][d];
        }
        else {
            elem += (1 << b) * (d ^ 1);
            cur = to[cur][d^1];
            res += (1 << b);
        }
    }
    return {res, elem};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
    }
    for(int i = 0; i < n; i++) {
        ii p = mn(a[i]);
        sub(p.second);
        cout << p.first << " ";
    }
    cout << '\n';
}