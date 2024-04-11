#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vi type;
vector<array<int, 3>> where;
vll cost;

// data structure for type 1 and type 3 plans
vvi enter;
set<int> unproc;

// data structure for looking up type 2 plans
struct seg_tree {
    int S;
    vector<set<int>> value;

    vi query(int i) {
        vi res;

        i += S;
        while(i){
            for (int v : value[i])
                res.push_back(v);
            i/=2;
        }

        sort(all(res));
        res.erase(unique(all(res)), res.end());
        return res;
    }

    void update(int i, int j, int v, bool rem) {
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) {
                if (!rem) value[i++].insert(v);
                else value[i++].erase(v);
            }
            if((j&1) == 0) {
                if (!rem) value[j--].insert(v);
                else value[j--].erase(v);
            }
        }
    }
};
seg_tree plan2;

// dijkstra
const ll INF = LLONG_MAX / 2;
priority_queue<pair<ll, int>> pq;
vll dist;

void update(int loc, ll tot) {
    if (dist[loc] != INF) return;
    assert(tot < INF);
    dist[loc] = tot;

    // check for type 2 and convert to type 1
    vi reach = plan2.query(loc);
    for (int q : reach) {
        plan2.update(where[q][1], where[q][2], q, true);
        type[q] = 1;
        where[q][1] = loc;
        enter[loc].push_back(q);
    }

    // type 1 and 3 are easy
    for (int q : enter[loc]) {
        pq.push({ -tot - cost[q], q });
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q, S;
    cin >> N >> Q >> S;
    S--;

    type.resize(Q), where.resize(Q), cost.resize(Q);
    enter.resize(N);

    plan2.S = N;
    plan2.value.resize(2 * N + 1);

    for (int q = 0; q < Q; q++) {
        cin >> type[q];

        if (type[q] == 1) {
            for (int i = 0; i < 2; i++) {
                cin >> where[q][i];
                where[q][i]--;
            }
            swap(where[q][0], where[q][1]);
            enter[where[q][1]].push_back(q);
        } else {
            for (int i = 0; i < 3; i++) {
                cin >> where[q][i];
                where[q][i]--;
            }

            if (type[q] == 2) {
                swap(where[q][0], where[q][1]);
                swap(where[q][1], where[q][2]);
                enter[where[q][2]].push_back(q);
            } else {
                plan2.update(where[q][1], where[q][2], q, false);
            }

            type[q] = 5 - type[q];
        }

        cin >> cost[q];
    }

    dist.resize(N, INF);
    update(S, 0);
    for (int l = 0; l < N; l++)
        unproc.insert(l);
    unproc.erase(S);

    while (!pq.empty()) {
        ll tot = -pq.top().first;
        int edge = pq.top().second;

        if (type[edge] == 1) {
            pq.pop();
            update(where[edge][0], tot);
        } else {
            auto it = unproc.lower_bound(where[edge][0]);
            if (it == unproc.end() || *it > where[edge][1]) {
                pq.pop();
                continue;
            }
            update(*it, tot);
            unproc.erase(it);
        }
    }

    for (int l = 0; l < N; l++) {
        if (dist[l] == INF) cout << -1 << " ";
        else cout << dist[l] << " ";
    }
    cout << endl;

    return 0;
}