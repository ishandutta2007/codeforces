#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)4e5 + 50;

struct edge {
    int to, c;
};

int n;
edge E[N];

void bad() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        E[a] = {b, 0};
        E[b] = {a, 1};
    }
    set<int> S;
    rep(i, 1, 2 * n + 1) S.insert(i);
    queue<pii> que;
    int res = 0;
    while(!S.empty()) {
        vi cnt(2, 0);
        int fir = *S.begin();
        cnt[E[fir].c]++;
        S.erase(fir);
        S.erase(E[fir].to);
        int lval = E[fir].to, rval = -1;
        int lid = fir, rid = N;

        while(!S.empty() && (*(prev(S.end())) > lval || *S.begin() < rval)) {
            if(*(prev(S.end())) > lval) {
                rid = *(prev(S.end()));
                int nxtrval = E[rid].to;
//                cout << rid << " " << nxtrval << " on the back" << endl;
                if(nxtrval < rval) bad();
                rval = nxtrval;
                S.erase(rid);
                S.erase(rval);
                cnt[E[rid].c]++;
            } else {
                lid = *S.begin();
                int nxtlval = E[lid].to;
//                cout << lid << " " << nxtlval << " on the front" << endl;
                if(nxtlval > lval) bad();
                lval = nxtlval;
                S.erase(lid);
                S.erase(lval);
                cnt[E[lid].c]++;
            }
        }
        if(lval < rval || lid > rid) bad();
//        cout << cnt[0] << " " << cnt[1] << endl;
        res += min(cnt[0], cnt[1]);
    }
    cout << res << '\n';
}