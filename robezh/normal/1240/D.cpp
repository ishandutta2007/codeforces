#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
const int N = (int)3e5 + 50;

string s, t;
int p = N;
ll pw[4][N];

struct hs {
    ll val[4];

    hs() { fill(val, val + 4, 0); }

    hs(ll a, ll b, ll c, ll d) {
        val[0] = a, val[1] = b, val[2] = c, val[3] = d;
    }

    bool operator<(const hs &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return val[i] < other.val[i];
        return false;
    }

    bool operator==(const hs &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return false;
        return true;
    }

    hs operator + (const hs &other) const{
        hs res;
        for(int i = 0; i < 4; i++) res.val[i] = ( val[i] + other.val[i]) % mods[i];
        return res;
    }

    hs operator - (const hs &other) const{
        hs res;
        for(int i = 0; i < 4; i++) res.val[i] = (val[i] - other.val[i] + mods[i]) % mods[i];
        return res;
    }

    hs operator ^ (const int pwi) const {
        hs res;
        for(int i = 0; i < 4; i++){
            res.val[i] = (val[i] * pw[i][pwi]) % mods[i];
        }
        return res;
    }

    void add(int x, int pwi){
        for(int i = 0; i < 4; i++) {
            val[i] = (val[i] + x * pw[i][pwi]) % mods[i];
            if(val[i] < 0) val[i] += mods[i];
        }
    }
};

int n, a[N];
map<hs, int> mp;
int S[N], sz = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int t = 0; t < 4; t++){
        pw[t][0] = 1;
        for(int i = 1; i < N; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        sz = 0;
        hs sum;
        mp.clear();
        mp[sum]++;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(sz == 0 || S[sz-1] != a[i]) {
                sum.add(a[i], sz);
                S[sz++] = a[i];
            }
            else {
                sz--;
                sum.add(-a[i], sz);
            }
            mp[sum]++;
        }
        ll res = 0;
        for(auto &p : mp) res += 1LL * p.second * (p.second - 1) / 2;
        cout << res << '\n';
    }
}