#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50, INF = (int)1e9, LOGN = 18;

struct P {
    int v1, len1, v2, len2;
};

int n;
P opt[N];
bool skip[N];
string str;
string res[N];
int rlen[N];
bool large[N];
int nxt[N][LOGN];

P comb(int v, P p) {
    if(v == p.v1) {
        return {v, 1 + p.len1, p.v2, p.len2};
    } else {
        return {v, 1, p.v1, p.len1};
    }
}

bool cmp(P p1, P p2) {
    if(p1.v1 != p2.v1) return p1.v1 < p2.v1;
    if(p1.len1 != p2.len1) {
        if(p1.len1 > p2.len1) return p1.v1 < p2.v2;
        else return p1.v2 < p2.v1;
    }
    if(p1.v2 != p2.v2) return p1.v2 < p2.v2;
    return p1.len2 < p2.len2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    n = str.length();
    opt[n] = {-1, 0, -1, 0};
    for (int i = n - 1; i >= 0; i--) {
        P sk = (i + 2 <= n && str[i] == str[i + 1] ? opt[i + 2] : P{INF, 0, INF, 0});
        P nsk = comb(str[i] - 'a', opt[i + 1]);

        skip[i] = cmp(sk, nsk);
        if(skip[i]) opt[i] = sk;
        else opt[i] = nsk;
        if(skip[i]) {
            res[i] = res[i + 2];
            large[i] = large[i + 2];
            rlen[i] = rlen[i + 2];
        }
        else {
            rlen[i] = rlen[i + 1] + 1;
            if(large[i + 1]) {
                res[i] = str[i] + res[i + 1].substr(0, 4) + res[i + 1].substr(5, 5);
                large[i] = true;
            } else {
                res[i] = str[i] + res[i + 1];
                if(sz(res[i]) > 10) {
                    large[i] = true;
                    res[i] = res[i].substr(0, 5) + "..." + res[i].substr(9, 2);
                }
            }
        }

    }
    rep(i, 0, n) cout << rlen[i] << " " << res[i] << '\n';

}