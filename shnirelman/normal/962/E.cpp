#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), t(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> a[i] >> c;
        t[i] = (c == 'P' ? 2 : (c == 'B' ? 0 : 1));
        cnt += (t[i] == 2);
    }

    if(cnt == 0) {
        int lst[2] = {-1, -1};
        li ans = 0;
        for(int i = 0; i < n; i++) {
            if(lst[t[i]] != -1)
                ans += a[i] - a[lst[t[i]]];
            lst[t[i]] = i;
        }

        cout << ans << endl;
        return 0;
    }

    li ans = 0;
    int mn[2] = {-1, -1};
    int ind = -1;
    for(int i = 0; i < n; i++) {
        if(t[i] == 2) {
            for(int j = 0; j < 2; j++)
                ans += (mn[j] == -1 ? 0 : a[i] - a[mn[j]]);
            ind = i;
            break;
        } else {
            if(mn[t[i]] == -1)
                mn[t[i]] = i;
        }
    }

//    cout << ans << endl;

    int lst = ind;
    int mx[2] = {0, 0};
    int ls[2] = {ind, ind};
    for(int i = ind + 1; i < n; i++) {
        if(t[i] == 2) {
            for(int j = 0; j < 2; j++)
                mx[j] = max(mx[j], a[i] - a[ls[j]]);
            int len = a[i] - a[lst];
            ans += 2ll * len + min(0ll, len - 1ll * mx[0] - mx[1]);
//            cout << len << ' ' << ans << ' ' << mx[0]  << ' ' << mx[1] << endl;
            lst = i;
            for(int j = 0; j < 2; j++)  {
                mx[j] = 0;
                ls[j] = i;
            }
        } else {
            int j = t[i];
            mx[j] = max(mx[j], a[i] - a[ls[j]]);
            ls[j] = i;
        }
    }

    for(int j = 0; j < 2; j++)
        ans += a[ls[j]] - a[lst];

    cout << ans << endl;
}