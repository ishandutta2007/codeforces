#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;
ll mods[7] = {469762049, 998244353, 1004535809, (int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};

struct hs {
    ll val[4];
    hs() {
        memset(val, 0, sizeof(val));
    }
    hs(int v) {
        fill(val, val + 4, v);
    }
    hs operator + (const hs &other) const{
        hs res;
        for(int i = 0; i < 4; i++) res.val[i] = ( val[i] + other.val[i]) % mods[i];
        return res;
    }
    hs operator * (const hs &other) const{
        hs res;
        for(int i = 0; i < 4; i++) res.val[i] = (val[i] * other.val[i]) % mods[i];
        return res;
    }
    bool operator==(const hs &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return false;
        return true;
    }
};

int n, m;
string str[N];
vector<hs> dpu[N], dpd[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::shuffle(mods, mods + 7, rng);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        dpu[i].resize(m);
        dpd[i].resize(m);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) {
                dpu[i][j] = hs(1);
                continue;
            }
            dpu[i][j] = hs();
            if(str[i][j] == '#') continue;
            if(i > 0) dpu[i][j] = dpu[i][j] + dpu[i-1][j];
            if(j > 0) dpu[i][j] = dpu[i][j] + dpu[i][j-1];
        }
    }
//    cout << dpu[n-1][m-1].val[0] << endl;
    if(dpu[n-1][m-1] == hs()) return cout << "0" << endl, 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(i == n - 1 && j == m - 1) {
                dpd[i][j] = hs(1);
                continue;
            }
            dpd[i][j] = hs();
            if(str[i][j] == '#') continue;
            if(i + 1 < n) dpd[i][j] = dpd[i][j] + dpd[i+1][j];
            if(j + 1 < m) dpd[i][j] = dpd[i][j] + dpd[i][j+1];
            if(!((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) &&
                dpd[i][j] * dpu[i][j] == dpu[n-1][m-1]) {
//                cout << i << ", " << j << endl;
                return cout << 1 << endl, 0;

            }
        }
    }
//    cout << dpu[0][1].val[0] << " " << dpd[0][1].val[0] << endl;

    cout << 2 << endl;



}