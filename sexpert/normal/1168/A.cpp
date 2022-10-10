#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> v;

bool can(int k) {
    //cout << k << '\n';
    vector<int> val(n);
    val[0] = v[0] + k >= m ? 0 : v[0];
    //cout << val[0] << " ";
    for(int i = 1; i < n; i++) {
        if((v[i] <= val[i - 1] && v[i] + k >= val[i - 1]) || (v[i] + k >= m + val[i - 1])) {
            val[i] = val[i - 1];
            //cout << val[i] << " ";
            continue;
        }
        if(v[i] < val[i - 1])
            return false;
        val[i] = v[i];
        //cout << val[i] << " ";
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    int lo = 0, hi = m - 1;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(can(mi))
            hi = mi;
        else
            lo = mi + 1;
        //cout << endl;
    }
    cout << lo << '\n';
}