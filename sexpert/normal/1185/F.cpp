#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAX = 512;
int guys[MAX], A, B, C, S;
 
struct pz {
    int cost, idx;
    bool operator< (const pz &o) const { return cost < o.cost; }
};
vector<pz> pizzas[MAX];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int f, ms = 0;
        cin >> f;
        while(f--) {
            int b;
            cin >> b;
            b--;
            ms |= (1 << b);
        }
        guys[ms]++;
    }
    for(int i = 0; i < m; i++) {
        int c, f, ms = 0;
        cin >> c >> f;
        while(f--) {
            int b;
            cin >> b;
            b--;
            ms |= (1 << b);
        }
        //cout << ms << endl;
        pizzas[ms].push_back({c, i + 1});
    }
    for(int i = 0; i < MAX; i++) {
        sort(pizzas[i].begin(), pizzas[i].end());
        while(pizzas[i].size() > 2) pizzas[i].pop_back();
    }
    S = -1;
    for(int i = 0; i < MAX; i++) {
        if(pizzas[i].size() < 2) continue;
        int co = pizzas[i][0].cost + pizzas[i][1].cost;
        int s = 0;
        for(int j = 0; j < MAX; j++) {
            if((i & j) == j)
                s += guys[j];
        }
        if(s > S || (s == S && co < C)) {
            S = s;
            C = co;
            A = pizzas[i][0].idx;
            B = pizzas[i][1].idx;
        }
    }
    for(int i = 0; i < MAX; i++) {
        if(pizzas[i].empty()) continue;
        for(int j = i + 1; j < MAX; j++) {
            if(pizzas[j].empty()) continue;
            int m = (i | j);
            int co = pizzas[i][0].cost + pizzas[j][0].cost;
            int s = 0;
            for(int k = 0; k < MAX; k++) {
                if((m & k) == k)
                    s += guys[k];
            }
            if(s > S || (s == S && co < C)) {
                S = s;
                C = co;
                A = pizzas[i][0].idx;
                B = pizzas[j][0].idx;
            }
        }
    }
    cout << A << " " << B << '\n';
}