#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<int> v;
int a, b, n, k;
 
ll amt(int l, int r) {
    if(v[0] > r || v[k - 1] < l)
        return 0;
    int li, ri;
    int lo = 0, hi = k - 1;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(v[mi] >= l)
            hi = mi;
        else
            lo = mi + 1;
    }
    li = lo;
    lo = 0, hi = k - 1;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(v[mi] <= r)
            lo = mi;
        else
            hi = mi - 1;
    }
    ri = lo;
    if(li > ri)
        return 0;
    return (ri - li + 1);
}
 
ll solve(int l, int r) {
    ll cnt = amt(l, r);
    if(cnt == 0) {
        //cout << l << " " << r << " " << a << endl;
        return a;
    }
    ll cst = b*cnt*((ll)(r - l + 1));
    //cout << l << " " << r << " " << cst << endl;
    if(l == r)
        return cst;
    return min(cst, solve(l, (l + r)/2) + solve((l + r)/2 + 1, r));
}
 
int main() {
    cin >> n >> k >> a >> b;
    v.resize(k);
    for(int i = 0; i < k; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << solve(1, (1 << n)) << endl;
}