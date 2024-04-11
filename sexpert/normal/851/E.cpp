#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 20;
int gdy[1 << N];
map<int, int> res;

vector<int> pf(int x) {
    vector<int> pfs;
    for(int d = 2; d * d <= x; d++) {
        if(x % d)
            continue;
        pfs.push_back(d);
        while(x % d == 0)
            x /= d;
    }
    if(x > 1)
        pfs.push_back(x);
    return pfs;
}

int grundy(int x) {
    if(x < (1 << N))
        return gdy[x];
    if(res.count(x))
        return res[x];
    vector<int> v(32);
    for(int k = 2; k <= x; k *= 2)
        v[grundy((x / k) | (x % k))]++;
    for(int i = 0; i < 32; i++)
        if(v[i] == 0)
            return res[x] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int x = 2; x < (1 << N); x++) {
        vector<int> v(25);
        for(int k = 2; k <= x; k *= 2)
            v[gdy[(x / k) | (x % k)]]++;
        for(int i = 0; i < 25; i++)
            if(v[i] == 0) {
                gdy[x] = i;
                break;
            }
    }

    int n;
    cin >> n;
    vector<int> v(n), ps;
    for(auto &x : v) {
        cin >> x;
        for(auto p : pf(x))
            ps.push_back(p);
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    int ans = 0;
    for(auto p : ps) {
        int ms = 0;
        for(auto x : v) {
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt++;
            }
            ms |= (1 << cnt);
        }
        ans ^= grundy(ms);
    }
    cout << (ans ? "Mojtaba" : "Arpa") << '\n';
}