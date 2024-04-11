#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 9;
const int N = 20 + 1;
const int A = 26;


/*
4
0 0
1 0
1 1
2 0

5
0 4
0 3
0 2
0 1
0 0

4
0 0
1 1
2 2
3 3


4
0 0
1 0
2 0
3 0

4
0 0
1 0
0 1
1 1

3
0 0
1 0
2 0

4
1 1
0 1
1 0
0 0

*/

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    vector<pii> a(n);
    map<pii, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
        mp[a[i]] = i;
    }

    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++) {
        if(a[i].s == 0)
            cnt[i] = INF;
        else {
            for(int j = -1; j <= 1; j++)
                cnt[i] += mp.count({a[i].f + j, a[i].s - 1});

        }
    }

    vector<int> d(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = -1; j <= 1; j++) {
            if(mp.count({a[i].f + j, a[i].s + 1}) && cnt[mp[{a[i].f + j, a[i].s + 1}]] == 1)
                d[i]++;
        }
    }


    vector<bool> del(n, false);
    set<int> st;
    vector<int> ans(n);

    for(int i = 0; i < n; i++)
        if(d[i] == 0)
            st.insert(i);

    for(int ind = n - 1; ind >= 0; ind--) {
//        cout << ind << " st ";
//        for(auto x : st)
//            cout << x << ' ';
//        cout << endl;
//        for(int i = 0; i < n; i++) {
//            cout << i << ' ' << del[i] << ' ' << cnt[i] << ' ' << d[i] << endl;
//        }
        int i;
        if((n - ind) % 2 == 0) {
            i = *st.begin();
        } else {
            auto it = st.end();
            i = *(--it);
        }
//        cout << i << endl;
        st.erase(i);
        del[i] = true;
        ans[ind] = i;

        if(cnt[i] == 1) {
            for(int j = -1; j <= 1; j++) {
                if(mp.count({a[i].f + j, a[i].s - 1})) {
                    int k = mp[{a[i].f + j, a[i].s - 1}];
                    if(del[k])
                        continue;
                    d[k]--;
                    if(d[k] == 0) {
                        st.insert(k);
                    }
                }
            }
        }

        for(int j = -1; j <= 1; j++) {
            if(mp.count({a[i].f + j, a[i].s + 1})) {
                int k = mp[{a[i].f + j, a[i].s + 1}];
                if(del[k])
                    continue;
                cnt[k]--;
                if(cnt[k] == 1) {
                    for(int l = -1; l <= 1; l++) {
                        if(mp.count({a[k].f + l, a[k].s - 1})) {
                            int m = mp[{a[k].f + l, a[k].s - 1}];
                            if(del[m])
                                continue;
                            d[m]++;
                            if(d[m] == 1)
                                st.erase(m);
                        }
                    }
                }
            }
        }
    }



    int res = 0;
    int p = 1;
    for(int i = 0; i < n; i++) {
        res = (res + ans[i] * 1ll * p) % M;
        p = p * 1ll * n % M;
    }

    cout << res << endl;
}