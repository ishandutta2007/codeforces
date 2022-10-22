#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
1
4 2
9 12 12 6
2
4 5
3
111 11 11
*/

li sum[N];
int k[N];
vector<int> a[N];
vector<bool> ans[N];

bool cmp(const int& i, const int& j) {
    li x = sum[i] * k[j];
    li y = sum[j] * k[i];

    if(x != y)
        return x > y;
    else
        return i > j;
}

int ord[N];

int b[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        a[i].erase(a[i].begin(), a[i].end());
        ans[i].erase(ans[i].begin(), ans[i].end());
        sum[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = -b[i];
    }

    sort(b, b + n);

    for(int i = 0; i < n; i++) {
        b[i] = -b[i];
    }

//    cout << "teachers" << endl;
//    for(int i = 0; i < m; i++)
//        cout << b[i] << ' ';
//    cout << endl;

    for(int i = 0; i < m; i++) {
        cin >> k[i];

        a[i].resize(k[i]);
        ans[i].resize(k[i], false);
        for(int j = 0; j < k[i]; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }

        ord[i] = i;
    }

    sort(ord, ord + m, cmp);

//    for(int i = 0; i < m; i++) {
//        cout << ord[i] << ' ';
//    }
//    cout << endl;

    vector<int> pos, pos_l, pos_r;
    for(int i = 0; i < m; i++) {
        if(sum[ord[i]] > b[i] * 1ll * k[ord[i]]) {
            pos.push_back(i);
        }

        if(i > 0 && sum[ord[i]] > b[i - 1] * 1ll * k[ord[i]]) {
            pos_l.push_back(i);
        }

        if(i < m - 1 && sum[ord[i]] > b[i + 1] * 1ll * k[ord[i]]) {
            pos_r.push_back(i);
        }
    }

    pos_l.push_back(INF);
    pos_r.push_back(INF);

//    cout << "pos ";
//    for(auto x : pos)
//        cout << x << ' ';
//    cout << endl;

    for(int ind = 0; ind < m; ind++) {
        int i = ord[ind];
        for(int j = 0; j < a[i].size(); j++) {
            int k1 = k[i] - 1;
            li sum1 = sum[i] - a[i][j];

            if(sum[i] * k1 > sum1 * k[i]) {
//                cout << i << ' ' << j << endl;
                sum[i] -= a[i][j];
                k[i]--;

                int l = ind, r = m;
                while(r - l > 1) {
                    int mid = (l + r) / 2;

                    if(cmp(i, ord[mid]))
                        r = mid;
                    else
                        l = mid;
                }

//                cout << "lr " <<  l << ' ' << r << endl;

                if((pos.empty() || pos[0] >= ind) && lower_bound(pos.begin(), pos.end(), r) == pos.end() &&
                    *upper_bound(pos_l.begin(), pos_l.end(), ind) >= r && sum[i] <= b[l] * 1ll * k[i])
                        ans[i][j] = true;

//                cout << "ans " << ans[i][j] << endl;
//                return;

            } else {
//                cout << i << ' ' << j << endl;
                sum[i] -= a[i][j];
                k[i]--;

                int l = -1, r = ind;
                while(r - l > 1) {
                    int mid = (l + r) / 2;

                    if(cmp(ord[mid], i))
                        l = mid;
                    else
                        r = mid;
                }

//                cout << "lr " <<  l << ' ' << r << endl;
                if((pos.empty() || pos[0] >= r) && lower_bound(pos.begin(), pos.end(), ind + 1) == pos.end() &&
                    *upper_bound(pos_r.begin(), pos_r.end(), l) >= ind && sum[i] <= b[r] * 1ll * k[i])
                        ans[i][j] = true;

//                cout << "ans " << ans[i][j] << endl;
//                return;
            }

            sum[i] += a[i][j];
            k[i]++;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k[i]; j++)
            cout << ans[i][j];
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}