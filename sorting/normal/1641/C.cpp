#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
const int INF = 2e9;

struct SegmentTree{
    int a[4 * N];
    bool lp[4 * N];
    bool is_lp[4 * N];

    void push_lazy(int i, int l, int r){
        if(!is_lp[i]) return;
        if(l != r){
            is_lp[2 * i + 1] = true;
            is_lp[2 * i + 2] = true;
            lp[2 * i + 1] = lp[i];
            lp[2 * i + 2] = lp[i];
        }
        a[i] = ((int)lp[i]) * (r - l + 1);
        is_lp[i] = false;
    }

    void update(int sl, int sr, int val, int i = 0, int l = 1, int r = N - 1){
        push_lazy(i, l, r);
        if(sr < l || r < sl) return;
        if(sl <= l && r <= sr){
            is_lp[i] = true;
            lp[i] = val;
            push_lazy(i, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(sl, sr, val, 2 * i + 1, l, mid);
        update(sl, sr, val, 2 * i + 2, mid + 1, r);
        a[i] = a[2 * i + 1] + a[2 * i + 2];
    }

    int query(int s, int i = 0, int l = 1, int r = N - 1){
        push_lazy(i, l, r);
        if(s < l || r < s) return 0;
        if(l == r) return a[i];

        int mid = (l + r) >> 1;
        return query(s, 2 * i + 1, l, mid) + query(s, 2 * i + 2, mid + 1, r);
    }

    int find1Left(int s, int i = 0, int l = 1, int r = N - 1){
        push_lazy(i, l, r);
        if(s < l) return 0;
        if(!a[i]) return 0;
        if(l == r) return l;

        int mid = (l + r) >> 1;
        int ans = find1Left(s, 2 * i + 2, mid + 1, r);
        if(ans) return ans;
        return find1Left(s, 2 * i + 1, l, mid);
    }

    int find1Right(int s, int i = 0, int l = 1, int r = N - 1){
        push_lazy(i, l, r);
        if(r < s) return N;
        if(!a[i]) return N;
        if(l == r) return l;

        int mid = (l + r) >> 1;
        int ans = find1Right(s, 2 * i + 1, l, mid);
        if(ans != N) return ans;
        return find1Right(s, 2 * i + 2, mid + 1, r);
    }
} st;

struct SegmentTreeMin{
    int a[4 * N], lp[4 * N];
    bool is_lp[4 * N];

    SegmentTreeMin(){
        fill(a, a + 4 * N, INF);
    }

    void push_lazy(int i, int l, int r){
        if(!is_lp[i]) return;
        if(l != r){
            is_lp[2 * i + 1] = true;
            is_lp[2 * i + 2] = true;
            lp[2 * i + 1] = lp[i];
            lp[2 * i + 2] = lp[i];
        }
        a[i] = min(lp[i], a[i]);
        is_lp[i] = false;
    }

    void update(int sl, int sr, int val, int i = 0, int l = 1, int r = N - 1){
        push_lazy(i, l, r);
        if(sr < l || r < sl) return;
        if(sl <= l && r <= sr){
            is_lp[i] = true;
            lp[i] = val;
            push_lazy(i, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(sl, sr, val, 2 * i + 1, l, mid);
        update(sl, sr, val, 2 * i + 2, mid + 1, r);
        a[i] = min(a[2 * i + 1], a[2 * i + 2]);
    }

    int query(int sl, int sr, int i = 0, int l = 1, int r = N - 1){
        push_lazy(i, l, r);
        if(sr < l || r < sl) return INF;
        if(sl <= l && r <= sr) return a[i];

        int mid = (l + r) >> 1;
        return min(query(sl, sr, 2 * i + 1, l, mid), query(sl, sr, 2 * i + 2, mid + 1, r));
    }
} st2;

pair<int, int> merge(pair<int, int> l, pair<int, int> r){
    return {l.first, r.second};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    st.update(1, n, 1);

    set<pair<int, int>> s;
    for(int i = 0; i < q; ++i){
        int t;
        cin >> t;

        if(!t){
            int l, r, x;
            cin >> l >> r >> x;

            if(!x){
                st.update(l, r, 0);
            }
            else{
                st2.update(l, l, r);
            }
        }
        else{
            int j;
            cin >> j;

            if(!st.query(j)){
                cout << "NO\n";
                continue;
            }

            int l, r;
            l = st.find1Left(j - 1) + 1;
            r = st.find1Right(j + 1) - 1;
            if(st2.query(l, j) <= r){
                cout << "YES\n";
                continue;
            }

            cout << "N/A" << "\n"; 
        }
    }
}