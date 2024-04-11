#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

map<pii, int> mp;

int get(int l, int r) {
    if(mp.count({l, r}))
        return mp[{l, r}];
    cout << "? " << l + 1 << ' ' << r << endl;
    int x;
    cin >> x;

    x--;

    return mp[{l, r}] = x;
}

int main() {
    int n;
    cin >> n;


    int l = 0, r = n;
//    int cur = get(0, n);
    while(r - l > 3) {
        int m = (l + r) / 2;

//        if(cur < l || cur >= r)
        int cur = get(l, r);

        if(cur < m) {
            int x = get(l, m);
            if(x == cur) {
                r = m;
            } else {
                l = m;
            }
        } else {
            int x = get(m, r);
            if(x == cur)
                l = m;
            else
                r = m;
        }
    }

    int ans = 0;

    if(r - l == 2) {
        int x = get(l, r);
        ans = x ^ l ^ (l + 1);
    } else {
        int x = get(l, l + 2);
        set<int> st = {l, l + 1, l + 2};
        st.erase(x);
        int y = get(l + 1, l + 3);
        st.erase(y);

        int z = get(l, l + 3);
        st.erase(z);
        ans = *st.begin();
    }

    cout << "! " << ans + 1 << endl;
}