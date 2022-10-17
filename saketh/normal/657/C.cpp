#include <bits/stdc++.h>
#define TRACE(x)
using namespace std;

typedef long long ll;

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--) 
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct node {
    ll intro;
    ll cost;
    ll membs;

    node(ll _intro = 0, ll _cost = 0, ll _membs = 0) {
        intro = _intro, cost = _cost, membs = _membs;
    }

    node(pair<ll, ll> init) {
        intro = init.first;
        cost = init.second;
        membs = 1;
    }

    node operator+(const node &o) const {
        return node(intro + o.intro, cost + o.cost, membs + o.membs);
    }
};

const int MAXN = 2e5 + 100;

ll N, K, B, C;
ll contrib[MAXN];

ll solve(vector<pair<ll, ll>> &events, vector<int> &storage) {
    ll ans = LLONG_MAX;
    seg_tree<node> st(N);

    for (int i = 0; i < N; i++) {
        ll eval = events[i].first;
        st.upd(storage[i], node(events[i]));

        if (i >= K - 1) {
            int front = 0;
            int lo = 1, hi = N - 1;

            while (lo <= hi) {
                int mi = (lo + hi) / 2;

                if (st.query(mi, N - 1).membs >= K) {
                    front = mi;
                    lo = mi + 1;
                } else {
                    hi = mi - 1;
                }
            }

            node res = st.query(front, N - 1);

            ll desired = eval * K;
            ll shift = desired - res.intro;

            ll total = res.cost + shift * B / 5;
            ans = min(ans, total);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K >> B >> C;

    B = min(B, 5 * C);

    for (int i = 0; i < N; i++) {
        cin >> contrib[i];
    }
    sort(contrib, contrib + N);

    ll ans = LLONG_MAX;

    for (int res = 0; res < 5; res++) {
        vector<pair<ll, ll>> events;

        for (int i = 0; i < N; i++) {
            ll intro = contrib[i];
            ll cost = 0;

            while (((intro % 5) + 5) % 5 != res) {
                intro++;
                cost += C;
            }

            events.emplace_back(intro, cost);
        }

        sort(events.begin(), events.end());

        vector<int> storage(N);
        for (int i = 0; i < N; i++) {
            storage[i] = i;
        }

        sort(storage.begin(), storage.end(), [&events](int i, int j) {
            ll eval = max(events[i].first, events[j].first);
            ll cost1 = events[i].second + B * (eval - events[i].first) / 5;
            ll cost2 = events[j].second + B * (eval - events[j].first) / 5;
            return cost1 > cost2;
        });

        vector<int> inverse(N);
        for (int i = 0; i < N; i++) {
            inverse[storage[i]] = i;
        }

        ll best = solve(events, inverse);
        ans = min(ans, best);
    }

    cout << ans << "\n";
}