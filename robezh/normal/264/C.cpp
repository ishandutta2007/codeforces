#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;
typedef long long ll;

int n,q;
ll val[N];
int col[N];
ll res[N];
ll mx0, mx1;
int c0, c1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n; i++) cin >> col[i];

    while(q--) {
        int A, B;
        cin >> A >> B;
        fill(res, res + N, -INF);
        mx0 = mx1 = -INF;
        c0 = c1 = -1;
        for(int i = 0; i < n; i++) {
            ll cur_res = B * val[i];
            if(mx0 != -INF) cur_res = max(cur_res, mx0 + (c0 == col[i] ? A * val[i] : B * val[i]));
            if(mx1 != -INF) cur_res = max(cur_res, mx1 + (c1 == col[i] ? A * val[i] : B * val[i]));
            if(res[col[i]] != -INF) cur_res = max(cur_res, res[col[i]] + A * val[i]);

            if(cur_res > mx0) {
                if(c0 != col[i]) mx1 = mx0, c1 = c0;
                mx0 = cur_res, c0 = col[i];
            } else if(cur_res > mx1 && c0 != col[i]) {
                mx1 = cur_res, c1 = col[i];
            }
            res[col[i]] = max(res[col[i]], cur_res);

        }
        cout << max(0LL, mx0) << "\n";
    }
}