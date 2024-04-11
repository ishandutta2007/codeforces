#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct digs {
    int z, f, s;
};

bool can[100];
digs how[100];

void gen() {
    for (int z = 0; z <= 6; z++) {
        for (int f = 0; z + f <= 6; f++) {
            int s = 6 - f - z;
            int v = 4 * f + 7 * s;
            can[v] = true;
            how[v] = {z, f, s};
        }
    }
}

void apply(vector<ll> &v, int a) {
    vector<int> d;
    for (int i = 0; i < how[a].z; i++)
        d.push_back(0);
    for (int i = 0; i < how[a].f; i++)
        d.push_back(4);
    for (int i = 0; i < how[a].s; i++)
        d.push_back(7);
    for (int i = 0; i < 6; i++) {
        v[i] = 10 * v[i] + d[i];
    }
}

int dp[21][10];
int us[21][10];
int goal[21];

void solve(ll V) {
    memset(dp, 0xff, sizeof(dp));

    for (int i = 0; i < 21; i++) {
        goal[i] = V % 10;
        V /= 10;
    }

    for (int tn = 0; tn < 10; tn++) {
        int mk = 10 * tn + goal[0];
        if(can[mk]) {
            dp[0][tn] = 0;
            us[0][tn] = mk;
        }
    }

    for (int d = 1; d < 21; d++) {
        for (int c = 0; c < 10; c++) {
            if(dp[d-1][c] == -1) continue;

            for (int a = 0; a < 100; a++) {
                if(can[a] && ((a+c) % 10 == goal[d])) {
                    dp[d][(a+c)/10] = c;
                    us[d][(a+c)/10] = a;
                } 
            }
        }
    }

    if(dp[20][0] == -1){
        cout << -1 << "\n";
    } else {
        int c = 0;
        vector<ll> res(6, 0);

        for (int d = 20; d >= 0; d--) {
            apply(res, us[d][c]);
            c = dp[d][c];
        }

        for (ll v : res) cout << v << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    gen();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        ll V;
        cin >> V;

        solve(V);
    }
}