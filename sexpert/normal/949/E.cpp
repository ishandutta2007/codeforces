#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int _cnt[20][2 * MAXN];
int* cnt[20];

vector<int> solve(int bnd, int k = 0) {
    if(bnd == 1) {
        if(cnt[k][1] && cnt[k][-1])
            return {1, -1};
        if(cnt[k][1])
            return {1};
        if(cnt[k][-1])
            return {-1};
        return {};
    }
    bool good = true;
    for(int i = -bnd; i <= bnd; i++) {
        if(cnt[k][i] > 0 && (i & 1))
            good = false;
    }
    if(good) {
        cnt[k + 1][0] = cnt[k][0];
        for(int i = 1; i <= bnd/2; i++) {
            cnt[k + 1][i] = cnt[k][2*i];
            cnt[k + 1][-i] = cnt[k][-2*i];
        }
        auto v = solve(bnd / 2, k + 1);
        for(auto &x : v)
            x *= 2;
        return v;
    }
    else {
        vector<int> v[2];
        int nb = (bnd + 1)/2;
        for(int i = 0; i < 2; i++) {
            int off = 2*i - 1;
            cnt[k + 1][0] = cnt[k][0] + cnt[k][off];
            for(int i = 1; i <= nb; i++) {
                cnt[k + 1][i] = cnt[k][2*i] + cnt[k][2*i + off];
                cnt[k + 1][-i] = cnt[k][-2*i] + cnt[k][-2*i + off];
            }
            v[i] = solve(nb, k + 1);
            for(auto &x : v[i])
                x *= 2;
            v[i].push_back(off);
        }
        if(v[0].size() < v[1].size())
            return v[0];
        return v[1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 20; i++)
        cnt[i] = _cnt[i] + MAXN;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[0][x]++;
    }
    auto v = solve(100000);
    cout << v.size() << '\n';
    for(auto x : v)
        cout << x << " ";
    cout << '\n';
}