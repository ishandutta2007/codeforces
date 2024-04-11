#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

struct Hash {
    size_t operator () (const P &p) const {
         return 1LL * p.first * 2352345 + p.second;
    }
};

unordered_map<ll, set<P> > pts;
unordered_map<P, int, Hash> l_cnt;
unordered_map<P, int, Hash> on_cnt;

P get_pair(int x, int y) {
    int g = __gcd(x, y);
    return {x / g, y / g};
}

int tcnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while(q--) {
        int t,x,y;
        cin >> t >> x >> y;
        if(t == 1) {
            ll cir = 1LL * x * x + 1LL * y * y;
            auto &V = pts[cir];
            for(const auto &p : V) l_cnt[get_pair(p.first + x, p.second + y)] ++;
            V.insert({x, y});
            on_cnt[get_pair(x, y)] ++;
            tcnt ++;
        }
        else if(t == 2) {
            ll cir = 1LL * x * x + 1LL * y * y;
            auto & V = pts[cir];
            V.erase({x, y});
            for(const auto &p : V) l_cnt[get_pair(p.first + x, p.second + y)] --;
            on_cnt[get_pair(x, y)] --;
            tcnt --;
        }
        else {
            cout << tcnt - on_cnt[get_pair(x, y)] - 2 * l_cnt[get_pair(x, y)] << "\n";
        }
    }
}