#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;
const ll INF = 1e18;

int n, m;
int a[N], b[N];
array<int, 3> t[2 * N];

struct SegmentTree{
    ll mn[4 * N], lp[4 * N];
    void clear(){
        for(int i = 0; i < 4 * (n + 2); ++i)
            mn[i] = lp[i] = 0;
    }
    void push(int i, int l, int r){
        if(!lp[i]) return;
        if(l != r){
            lp[2 * i + 1] += lp[i];
            lp[2 * i + 2] += lp[i];
        }
        mn[i] += lp[i];
        lp[i] = 0;
    }
    void update(int sl, int sr, ll val, int i = 0, int l = 0, int r = n){
        push(i, l, r);
        if(sr < l || r < sl) return;
        if(sl <= l && r <= sr){
            lp[i] += val;
            push(i, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(sl, sr, val, 2 * i + 1, l, mid);
        update(sl, sr, val, 2 * i + 2, mid + 1, r);
        mn[i] = min(mn[2 * i + 1], mn[2 * i + 2]);
    }
    ll get_min(int sl, int sr, int i = 0, int l = 0, int r = n){
        push(i, l, r);
        if(sr < l || r < sl) return INF;
        if(sl <= l && r <= sr) return mn[i];
        int mid = (l + r) >> 1;
        return min(get_min(sl, sr, 2 * i + 1, l, mid), get_min(sl, sr, 2 * i + 2, mid + 1, r));
    }
} st;

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= m; ++i)
        cin >> b[i];

    for(int i = 1; i <= n; ++i)
        t[i] = {a[i], i, 0};
    for(int i = 1; i <= m; ++i)
        t[i + n] = {b[i], i, 1};
    sort(t + 1, t + 1 + n + m);

    st.clear();
    for(int i = 1; i <= n; ++i)
        st.update(i, n, 1);

    ll ans = 0, ans2 = 0;
    int start = 1;
    for(int i = 1; i <= n + m + 1; ++i){
        if(i == n + m + 1 || t[i][0] != t[start][0]){
            for(int j = start; j < i; ++j)
                if(t[j][2] == 0)
                    st.update(t[j][1], n, -1);

            for(int j = start; j < i; ++j){
                if(t[j][2] == 0){
                    //cout << st.get_min(t[j][1], t[j][1]) << " st" << "\n";
                    ans2 += st.get_min(t[j][1], t[j][1]);
                }
                else{
                    ans += st.get_min(0, n);
                }
            }
            for(int j = start; j < i; ++j)
                if(t[j][2] == 0){
                    st.update(t[j][1], n, -1);
                    st.update(0, n, 1);
                }
                    
            start = i;
        }
    }

    ans2 /= 2;
    cout << ans + ans2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}