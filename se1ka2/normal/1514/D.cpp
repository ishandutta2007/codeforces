#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a[600005];
int s[600005];
int t[1200005];
vector<int> c[600005];

int foo(int l, int r){
    int res = -1;
    for(int i = l; i < r; i++) s[a[i]]++;
    for(int i = l; i < r; i++){
        if(s[a[i]] * 2 > r - l) res = a[i];
    }
    for(int i = l; i < r; i++) s[a[i]]--;
    return res;
}

void rec(int k, int l, int r){
    t[k] = foo(l, r);
    if(r - l > 1){
        rec(k * 2, l, (l + r) / 2);
        rec(k * 2 + 1, (l + r) / 2, r);
    }
}

void rec2(int k, int l, int r, int p, int q, vector<int> &v){
    if(p >= l && q <= r){
        v.push_back(t[k]);
        return;
    }
    if(p >= r || q <= l){
        return;
    }
    rec2(k * 2, l, r, p, (p + q) / 2, v);
    rec2(k * 2 + 1, l, r, (p + q) / 2, q, v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        c[a[i]].push_back(i);
    }
    int nn = 1;
    while(nn < n) nn <<= 1;
    swap(n, nn);
    rec(1, 0, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        vector<int> v;
        rec2(1, l, r, 0, n, v);
        int d = 0;
        for(int u : v){
            int x = lower_bound(c[u].begin(), c[u].end(), l) - c[u].begin();
            int y = lower_bound(c[u].begin(), c[u].end(), r) - c[u].begin();
            d = max(d, y - x);
        }
        cout << max(1, d * 2 - (r - l)) << "\n";
    }
}