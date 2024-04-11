#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)1e5 + 50, LOG = 42;

int n;
int gpow[LOG], gcon[LOG], ed[LOG];
int totcon[LOG];

P get_bit(ll x) {
    int cnt = 0;
    bool good = true;
    while(x > 1) {
        cnt++;
        if(x % 2 == 1) good = false;
        x /= 2;
    }
    return {cnt, good};
}

bool check(int m) {
    if(gpow[0] < m) return false;
    fill(ed, ed + LOG, 0);
    for(int i = 0; i < LOG; i++) totcon[i] = gcon[i];
    int sz = m;
    for(int i = 0; i < LOG; i++) {
        if(gpow[i] < sz) {
            ed[i-1] = sz - gpow[i];
            sz = gpow[i];
        }
        else {
            totcon[i] += gpow[i] - sz;
        }
    }
//    for(int i = 0; i < LOG; i++) cout << ed[i] << " ";
//    cout << endl;
//    for(int i = 0; i < LOG; i++) cout << totcon[i] << " ";
//    cout << endl;
    int cur = 0;
    for(int i = 0; i < LOG; i++) {
        cur += totcon[i];
        cur -= min(ed[i], cur);
    }
    return cur == 0;


}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        P p = get_bit(a);
        if(p.second) gpow[p.first]++;
        else gcon[p.first]++;
    }
    vector<int> res;

//    check(12);

    for(int i = 1; i <= n; i++) {
        if(check(i)) res.push_back(i);
    }
    if(res.empty()) cout << -1 << endl;
    else {
        for(int x : res) cout << x << " ";
        cout << endl;
    }
}