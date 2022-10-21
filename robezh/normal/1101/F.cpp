#include <bits/stdc++.h>
using namespace std;

const int N = 405;
typedef long long ll;
struct tuk{
    int s, f, c, r;
};

int n, m;
vector<tuk> ks;
ll len[N];

bool check(int i, ll V){
    int cur = ks[i].s;
    ll curV = V;
    int tim = ks[i].r;
    while(cur != ks[i].f) {
        ll cost = (len[cur+1] - len[cur]) * ks[i].c;
        if(cost > curV) {
            if(cost > V || tim == 0) return false;
            tim--;
            curV = V;
        }
        curV -= cost;
        cur++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> len[i];
    for(int i = 0; i < m; i++){
        int s,f,c,r;
        cin >> s >> f >> c >> r;
        s--, f--;
        ks.push_back({s, f, c, r});
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(ks.begin(), ks.end(), rng);
    ll l = -1, r = 0, mid;
    for(int i = 0; i < m; i++) {
        if(check(i, r)) continue;
        l = r, r = (ll)1e18;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(check(i, mid)) r = mid;
            else l = mid;
        }
    }
    cout << r << endl;


}