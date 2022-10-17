#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;
const int BITS = 30;

ll tri(ll base) {
    return base * (base + 1) / 2;
}

struct bit {
    int N;
    bool arr[MAXN];

    ll sum = 0;
    set<pair<int, int>> all;

    void init() {
        int run = 0;
        for (int i = 0; i < N; i++) {
            if(arr[i]) run++;

            if((!arr[i] || (i+1) == N) && run > 0) {
                sum += tri(run);
                
                int y = (arr[i] ? i : i-1);
                int x = y + 1 - run;

                all.insert({x, y});

                run = 0;
            }
        }
    }

    void put(int i, bool v) {
        if(arr[i] == v) return;

        if(arr[i]) {
            auto it = all.upper_bound({i, MAXN});
            it--;

            pair<int, int> cur = *it;
            all.erase(it);

            sum -= tri(cur.second - cur.first + 1);

            if (cur.first < i) {
                sum += tri(i - cur.first);
                all.insert({cur.first, i - 1});
            }

            if (i < cur.second) {
                sum += tri(cur.second - i);
                all.insert({i+1, cur.second});
            }
        }
        else {
            pair<int, int> ins = {i, i};

            auto it = all.upper_bound({i, MAXN});

            if (it != all.end() && it->first == i+1) {
                pair<int, int> p = *it;
                sum -= tri(p.second - p.first + 1);
                ins.second = p.second;
                all.erase(it);
            }
            
            it = all.upper_bound({i, MAXN});
            if (it != all.begin()) {
                it--;
                if(it->second == i-1) {
                    pair<int, int> p  = *it;
                    sum-= tri(p.second - p.first + 1);
                    ins.first = p.first;
                    all.erase(it);
                }
            }

            sum += tri(ins.second - ins.first + 1);
            all.insert(ins);
        }

        arr[i] = !arr[i];
    }
};

int N, M;
int val[MAXN];
bit dat[BITS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> val[i];

        for (int j = 0; j < BITS; j++)
            dat[j].arr[i] = (val[i] >> j) & 1;
    }

    for (int i = 0; i < BITS; i++) {
        dat[i].N = N;
        dat[i].init();
    }

    for (int i = 0; i < M; i++) {
        int idx, amt;
        cin >> idx >> amt;

        ll res = 0;
        for (int j = 0; j < BITS; j++) {
            dat[j].put(idx - 1, (amt >> j) & 1);
            res += dat[j].sum << j;
        }

        cout << res << "\n";
    }
}