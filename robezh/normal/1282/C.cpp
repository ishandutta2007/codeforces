#include <bits/stdc++.h>
using namespace std;

const int N = (int)4e5 + 50;
typedef long long ll;

int n, T, a, b;
int na, nb;
int ty[N], t[N];

struct Eve {
    int t, tp;
};

vector<Eve> es;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Tcase;
    cin >> Tcase;
    while(Tcase--) {
        cin >> n >> T >> a >> b;
        es.clear();
        na = nb = 0;
        for(int i = 0; i < n; i++) cin >> ty[i];
        for(int i = 0; i < n; i++) cin >> t[i];
        for(int i = 0; i < n; i++) {
            es.push_back({t[i], ty[i]});
            if(ty[i]) nb++;
            else na++;

            if(t[i] >= 1) es.push_back({t[i] - 1, -1});
        }
        es.push_back({T, -1});
        sort(es.begin(), es.end(), [](const Eve &e1, const Eve &e2) {
            return e1.t < e2.t;
        });
        int r = 0;
        ll curtime = 0;
        ll res = 0;
        for(int i = 0; i < es.size(); i = r) {
            while(r < es.size() && es[r].t == es[i].t) {
                if(es[r].tp == 0) {
                    na--;
                    curtime += a;
                }
                else if(es[r].tp == 1) {
                    nb--;
                    curtime += b;
                }
                r++;
            }
//            cout << i << ", " << r << ": " << curtime << ", " << es[i].t << endl;
            if(curtime <= es[i].t) {
                ll left = es[i].t - curtime;
                ll solve_a = min((ll)na, left / a);
                left -= solve_a * a;
                ll solve_b = min((ll)nb, left / b);

                res = max(res, n - na - nb + solve_a + solve_b);
            }
        }

        cout << res << '\n';
    }
}