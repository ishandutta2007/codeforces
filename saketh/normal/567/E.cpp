#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 100;
const ll MOD = 1e9 + 297;
const ll INF = 0x3fffffffffffffff;

int N, M, S, T;
vector<int> adj[MAXN];
int A[MAXN], B[MAXN], L[MAXN];

vector<pair<ll,ll>> dij(int source) {
    vector<pair<ll,ll>> res(N, make_pair(INF, 0));
    res[source] = {0, 1};
    
    priority_queue<pair<ll, int> > dij;
    dij.push({0, source});
    
    while(dij.size()) {
        ll far = -dij.top().first;
        int loc = dij.top().second;
        dij.pop();

        if (res[loc].first != far) continue;

        for (int e : adj[loc]) {
            int nbr = B[e];
            ll tot = far + L[e];
            if (tot < res[nbr].first) {
                res[nbr].first = tot;
                res[nbr].second = res[loc].second;
                dij.push({-tot, nbr});
            }
            else if(tot == res[nbr].first) {
                res[nbr].second += res[loc].second;
                res[nbr].second %= MOD;
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> S >> T;
    S--, T--;

    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> L[i];
        A[i]--, B[i]--;
        adj[A[i]].push_back(i);
    }

    vector<pair<ll, ll>> src = dij(S);

    for (int i = 0; i < N; i++)
        adj[i].clear();

    for (int i = 0; i < M; i++) {
        swap(A[i], B[i]);
        adj[A[i]].push_back(i);
    } 

    vector<pair<ll, ll>> tar = dij(T);   

    ll SP = src[T].first;
    ll TW = src[T].second;

    for (int i = 0; i < M; i++) {
        swap(A[i], B[i]);

        if (src[A[i]].first == INF || tar[B[i]].first == INF) {
            cout << "NO\n";
            continue;
        }

        ll PH = src[A[i]].first + L[i] + tar[B[i]].first;
        if(PH == SP) {
            ll W = src[A[i]].second * tar[B[i]].second % MOD;
            if(W == TW) cout << "YES\n";
            else if(L[i] > 1) cout << "CAN 1\n";
            else cout << "NO\n";
        }
        else {
            ll D = PH - SP + 1;
            if(D < L[i]) cout << "CAN " << D << "\n";
            else cout << "NO\n";
        }    
    }
}