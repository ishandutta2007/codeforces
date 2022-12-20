#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 3;

int n, q, l[N], r[N];
string s, f;

struct SegmentTree{
    int cnt[4 * N], lp[4 * N];

    SegmentTree(){}

    void clear(){
        for(int i = 0; i < 4 * n; ++i){
            cnt[i] = 0;
            lp[i] = -1;
        }
    }

    void push(int i, int l, int r){
        if(lp[i] != -1){
            if(l != r)
                lp[2 * i + 1] = lp[2 * i + 2] = lp[i];
            cnt[i] = lp[i] * (r - l + 1);
            lp[i] = -1;
        }
    }

    void update(int l2, int r2, int val, int i = 0, int l = 1, int r = n){
        push(i, l, r);
        if(r2 < l || r < l2) return;
        if(l2 <= l && r <= r2){
            lp[i] = val;
            push(i, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(l2, r2, val, 2 * i + 1, l, mid);
        update(l2, r2, val, 2 * i + 2, mid + 1, r);

        cnt[i] = cnt[2 * i + 1] + cnt[2 * i + 2];
    }

    int query(int l2, int r2, int i = 0, int l = 1, int r = n){
        push(i, l, r);
        if(r2 < l || r < l2) return 0;
        if(l2 <= l && r <= r2)
            return cnt[i];

        int mid = (l + r) >> 1;
        int ans = 0;
        ans += query(l2, r2, 2 * i + 1, l, mid);
        ans += query(l2, r2, 2 * i + 2, mid + 1, r);
        return ans;
    }
} st;

void solve(){
    cin >> n >> q;
    cin >> s >> f;

    st.clear();

    for(int i = 0; i < q; ++i)
        cin >> l[i] >> r[i];

    for(int i = 0; i < n; ++i)
        st.update(i + 1, i + 1, f[i] - '0');

    for(int i = q - 1; i >= 0; --i){
        int cnt = st.query(l[i], r[i]);
        if(cnt * 2 == (r[i] - l[i] + 1)){
            cout << "NO\n";
            return;
        }
        st.update(l[i], r[i], cnt * 2 > (r[i] - l[i] + 1));
    }

    for(int i = 0; i < n; ++i)
        if(st.query(i + 1, i + 1) != s[i] - '0'){
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}