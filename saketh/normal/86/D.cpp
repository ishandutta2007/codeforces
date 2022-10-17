#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 500;
const int BUCK = 500;
const int MAXV = 1e6 + 100;

int N, T;
int val[MAXN];

int ord[MAXN];
ll ans[MAXN];
pair<int, int> que[MAXN];

ll value = 0;
int occ[MAXV];

void reset() {
    value = 0;
    memset(occ, 0, sizeof(occ));
}

ll score(int val) {
    ll app = occ[val];
    return app * app * val;
}

void insert(int val) {
    value -= score(val);
    occ[val]++;
    value += score(val);
}

void remove(int val) {
    value -= score(val);
    occ[val]--;
    value += score(val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> T;

    for (int i = 0; i < N; i++)
        cin >> val[i];

    for (int i = 0; i < T; i++) {
        cin >> que[i].first >> que[i].second;
        que[i].first--;
        que[i].second--;
        ord[i] = i;
    }

    sort(ord, ord + T, [](int i, int j) {
        if (que[i].first / BUCK != que[j].first / BUCK)
            return que[i].first / BUCK < que[j].first / BUCK;        
        return que[i].second < que[j].second;
    });

    int buck = -1;
    int front = -1, back = -1; // [front, back)

    for (int _i = 0; _i < T; _i++) {
        int i = ord[_i];
        int l = que[i].first, r = que[i].second;    
        
        if (l / BUCK != buck) {
            reset();
            buck = l / BUCK;
            front = buck * BUCK;
            back = front;
        }

        while (back <= r) {
            insert(val[back++]);
        }

        while(front < l) {
            remove(val[front++]);
        }

        while(front > l) {
            insert(val[--front]);
        }

        ans[i] = value;
    }

    for (int i = 0; i < T; i++)
        cout << ans[i] << "\n";
}