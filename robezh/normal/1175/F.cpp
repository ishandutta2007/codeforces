#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
const int N = (int)3e5 + 50;

int n;
int p = 10;
int num[N];
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

    void add(int x, int pwi){
        for(int i = 0; i < 4; i++) val[i] = (val[i] + x * pw[i][pwi]) % mods[i];
    }

    hs up_pow(int pwi){
        hs res;
        for(int i = 0; i < 4; i++){
            res.val[i] = (val[i] * pw[i][pwi]) % mods[i];
        }
        return res;
    }
};

hs psum[N];
hs good[N];

bool check(int l, int r) {
    return good[r - l + 1] == (psum[r] - psum[l-1]);
}

int solve(int l, int r) {
    if(l > r) return 0;
    if(l == r) return num[l] == 1;

    int mid = (l + r) / 2;

    int res = 0;
    int mx = -1;
    for(int i = mid; i <= r; i++) {
        mx = max(num[i], mx);
        if(i - mx + 1 >= l && i - mx + 1 <= mid && check(i - mx + 1, i)) {
            res++;
        }
    }
    mx = -1;
    for(int i = mid - 1; i >= l; i--) {
        mx = max(num[i], mx);
        if(i + mx - 1 >= mid && i + mx - 1 <= r && check(i, i + mx - 1)) {
            res++;
        }
    }
    return res + solve(l, mid - 1) + solve(mid + 1, r);
}


int main(){
    for(int t = 0; t < 4; t++){
        pw[t][n] = 1;
        for(int i = 1; i < N; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 1; i <= n; i++) {
        psum[i] = psum[i-1];
        psum[i].add(1, num[i]);
    }
    for(int i = 1; i <= n; i++) {
        good[i] = good[i-1];
        good[i].add(1, i);
    }

    cout << solve(1, n) << endl;
}