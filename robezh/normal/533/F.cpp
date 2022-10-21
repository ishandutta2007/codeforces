#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
const int N = (int)2e5 + 50;

string s, t;
int p = 37;
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

typedef pair<hs, int> Phs;

hs shs[26];
hs ths[26];
Phs sstd[26], tstd[26];
int to[26];
int n, m;

bool set_to(int a, int b) {
    if(to[a] != -1 && to[a] != b) return false;
    if(to[b] != -1 && to[b] != a) return false;
    to[a] = b, to[b] = a;
    return true;
}

bool check() {
    for(int b = 0; b < 26; b++) sstd[b].first = shs[b], sstd[b].second = b;
    sort(sstd, sstd + 26);
    fill(to, to + 26, -1);
    for(int b = 0; b < 26; b++) {
        if(!(sstd[b].first == tstd[b].first)) {
//            cout << sstd[b].first.val[1] << " " << tstd[b].first.val[1] << endl;
            return false;
        }
        if(sstd[b].first.val[0] == 0) continue;
//        cout << sstd[b].first.val[0] << " " << tstd[b].first.val[0] << endl;
        if(!set_to(sstd[b].second, tstd[b].second)) return false;
    }
    return true;

}

int main() {
    for(int t = 0; t < 4; t++){
        pw[t][n] = 1;
        for(int i = 1; i < N; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s >> t;
    for(int i = 0; i < m; i++) {
        for(int b = 0; b < 26; b++) {
            shs[b] = shs[b] ^ 1;
            ths[b] = ths[b] ^ 1;
        }
        shs[s[i] - 'a'].add(1, 0);
        ths[t[i] - 'a'].add(1, 0);
    }

    for(int b = 0; b < 26; b++) {
        tstd[b].first = ths[b];
        tstd[b].second = b;
    }
    sort(tstd, tstd + 26);
    vector<int> res;
    if(check()) res.push_back(0);
    for(int i = m; i < n; i++) {
        for(int b = 0; b < 26; b++) shs[b] = shs[b] ^ 1;
        shs[s[i - m] - 'a'].add(-1, m);
        shs[s[i] - 'a'].add(1, 0);
        if(check()) res.push_back(i - m + 1);
    }
    cout << res.size() << "\n";
    for(int x : res) cout << x + 1 << " ";
}