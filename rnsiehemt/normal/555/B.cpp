#include <bits/stdc++.h>
typedef long long ll;
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
#define mod(x) ((x)%Mod)

struct E {
    ll l, r; int i, type;
    E(ll l_, ll rr, int ii, int t) : l(l_), r(rr), i(ii), type(t) { }
    bool operator<(const E &e) const { return (l == e.l ? type < e.type : l < e.l); }
};
struct G {
    ll r; int i;
    G(ll rr, int ii) : r(rr), i(ii) { }
    bool operator<(const G &g) const { return r > g.r; }
};

int N, M, ans[200005];
ll l[200005], r[200005];
std::vector<E> e;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%lld%lld", &l[i], &r[i]);
    for (int i = 0; i < N-1; i++) e.push_back(E(l[i+1]-r[i], r[i+1]-l[i], i, 0));
    for (int i = 0; i < M; i++) {
        ll a; scanf("%lld", &a);
        e.push_back(E(a, 0, i, 1));
    }
    std::sort(e.begin(), e.end());
    std::priority_queue<G> q;
    for (int i = 0; i < sz(e); i++) {
        //printf("event %d: %lld %lld %d %d\n", i, e[i].l, e[i].r, e[i].i, e[i].type);
        if (e[i].type == 0) {
            q.push(G(e[i].r, e[i].i));
        } else {
            if (!q.empty() && q.top().r >= e[i].l) {
                ans[q.top().i] = e[i].i;
                q.pop();
            }
        }
    }
    if (!q.empty()) printf("No\n");
    else {
        printf("Yes\n");
        for (int i = 0; i < N-1; i++) printf("%d%c", ans[i]+1, " \n"[i == N-2]);
    }
}