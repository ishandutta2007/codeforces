#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

int n, m, k;
int c[N];
int al[N], bl[N];
vector<int> ab, a, b, x;
multiset<int> in, rem;

bool cmp(int i, int j) {
    return c[i] < c[j];
}

ll cursum = 0;

void set_delete(int x) {
    auto it = rem.find(x);
    if(it == rem.end()) {
        cursum -= x;
        in.erase(in.find(x));
    }
    else rem.erase(it);
}

void lim(int len) {
    while(in.size() < len) {
        cursum += *rem.begin();
        in.insert(*rem.begin());
        rem.erase(rem.begin());
    }
    while(in.size() > len) {
        rem.insert(*in.rbegin());
        cursum -= *in.rbegin();
        in.erase(--in.end());
    }
}

void update() {
    if(in.empty() || rem.empty()) return ;
    int a, b;
    while(!in.empty() && !rem.empty() && (a = *in.rbegin()) > (b = *rem.begin())) {
        in.erase(--in.end());
        in.insert(b);
        rem.erase(rem.begin());
        rem.insert(a);
        cursum += b - a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> c[i];
    int na, nb;
    cin >> na;
    for(int i = 0; i < na; i++) {
        int t; cin >> t; t--; al[t] = 1;
    }
    cin >> nb;
    for(int i = 0; i < nb; i++) {
        int t; cin >> t; t--, bl[t] =1;
    }
    for(int i = 0; i < n; i++) {
        if(al[i]) {
            if(bl[i]) ab.push_back(i);
            else a.push_back(i);
        }
        else {
            if(bl[i]) b.push_back(i);
            else x.push_back(i);
        }
    }
    if(ab.size() + min(a.size(), b.size()) < k) return cout << -1 << endl, 0;
    sort(ab.begin(), ab.end(), cmp);
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    sort(x.begin(), x.end(), cmp);

    ll res = INF;

    int ablen = min(k, (int)ab.size());

    for(int i = 0; i < ab.size(); i++) {
        if(i < ablen) cursum += c[ab[i]];
        else rem.insert(c[ab[i]]);
    }
    for(int i = 0; i < b.size(); i++) {
        if(i < k - ablen) cursum += c[b[i]];
        else rem.insert(c[b[i]]);
    }
    for(int i = 0; i < a.size(); i++) {
        if(i < k - ablen) cursum += c[a[i]];
        else rem.insert(c[a[i]]);
    }
    for(int v : x) rem.insert(c[v]);


    for(int len = ablen; len >= 0; len--) {
        int free_size = m - (len + 2 * (k - len));
        if(free_size < 0) break;
        update();
        lim(free_size);
        res = min(res, cursum);
        if(len == 0) break;

        cursum -= c[ab[len-1]];
        rem.insert(c[ab[len-1]]);
        if(k - len >= min(a.size(), b.size())) break;
        cursum += c[a[k - len]] + c[b[k - len]];
        set_delete(c[a[k - len]]);
        set_delete(c[b[k - len]]);

    }

    if(res == INF) res = -1;
    cout << res << endl;

}