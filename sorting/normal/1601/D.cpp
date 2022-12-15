#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 5e5 + 3;
const int INF = 1e9;

int n, d;
pair<int, int> p[N]; //a, s
int dp[N];

struct SegmentTree{
    int mx[4 * N], lp[4 * N];

    void push(int i, int l, int r){
        if(!lp[i]) return;
        if(l != r){
            lp[2 * i + 1] += lp[i];
            lp[2 * i + 2] += lp[i];
        }
        mx[i] += lp[i];
        lp[i] = 0;
    }
    void update(int sl, int sr, int v, int i = 0, int l = 0, int r = n + 1){
        push(i, l, r);
        if(sr < l || r < sl) return;
        if(sl <= l && r <= sr){
            lp[i] += v;
            push(i, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(sl, sr, v, 2 * i + 1, l, mid);
        update(sl, sr, v, 2 * i + 2, mid + 1, r);
        mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
    }
    int query(int sl, int sr, int i = 0, int l = 0, int r = n + 1){
        push(i, l, r);
        if(sr < l || r < sl) return -1;
        if(sl <= l && r <= sr) return mx[i];
        int mid = (l + r) >> 1;
        return max(query(sl, sr, 2 * i + 1, l, mid), query(sl, sr, 2 * i + 2, mid + 1, r));
    }
} st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    p[0].first = d;

    for(int i = 1; i <= n; ++i){
        cin >> p[i].second >> p[i].first;
        if(p[i].second < d){
            --i;
            --n;
        }
    }
    sort(p + 1, p + 1 + n, [&](auto l, auto r){
        if(l.first != r.first)
            return l.first < r.first;
        return l.second > r.second;
    });

    // cout << "p:\n";
    // for(int i = 1; i <= n; ++i)
        // cout << p[i].first << " " << p[i].second << "\n";

    dp[n + 1] = -1;
    st.update(n + 1, n + 1, - 1);
    st.update(0, n, -INF);

    struct cmp{
        bool operator()(int l, int r) const{
            return p[l].second < p[r].second;
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    for(int i = n; i >= 0; --i){
        //cout << i << " i" << endl;
        //if(!pq.empty()) cout << p[pq.top()].second << " cmp " << p[i].first << "\n";
        while(!pq.empty() && p[pq.top()].second >= p[i].first){
            st.update(pq.top(), pq.top(), INF);
            //cout << pq.top() << " pq.top()" << endl;
            pq.pop();
        }
        dp[i] = st.query(i + 1, n + 1) + 1;
        //cout << dp[i] << " dp[i]" << endl;
        int idx = upper_bound(p + i + 1, p + n + 1, pair{p[i].second, INF}) - p - 1;
        if(idx >= i + 1) st.update(i + 1, idx, 1);
        st.update(i, i, dp[i]);
        pq.push(i);
    }

    cout << dp[0] << "\n";
}
// | |
// | |
// bigger s than this
// at the beginning maybe everything is -inf
// and then we continuosly add them one by one 
// sum(x^j/j!)