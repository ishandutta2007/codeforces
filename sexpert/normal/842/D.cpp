#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 10;
const int LG = 20;
int to[MAXN*LG][2], cnt[MAXN*LG], sz;

void add(int x) {
    int cur = 0;
    for(int bit = LG - 1; bit >= 0; bit--) {
        cnt[cur]++;
        int b = (x & (1 << bit)) >> bit;
        if(!to[cur][b])
            to[cur][b] = ++sz;
        cur = to[cur][b];
    }
    cnt[cur]++;
}

int qry(int ms) {
    int cur = 0, h = LG, ans = 0;
    while(h) {
        h--;
        int b = (ms & (1 << h)) >> h;
        if(cnt[to[cur][b]] == (1 << h)) {
            ans += (1 << h);
            cur = to[cur][b^1];
        }
        else
            cur = to[cur][b];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto x : v)
        add(x);
    int num = 0;
    while(q--) {
        int x;
        cin >> x;
        num ^= x;
        cout << qry(num) << '\n';
    }
}