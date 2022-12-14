#include <bits/stdc++.h>
#define sz              size()
#define pb              push_back
#define Fr              first
#define Sc              second
#define int             ll
using namespace std;
typedef long long ll;
int n, T, A[400400];
int In[400400], Out[400400], Discover[400200];
int Time;
vector<int> v[400400];
int Tree[1000400 << 2LL], Lazy[1000400 << 2LL];
void dfs(int curr, int prev) {
    In[curr] = ++Time;
    Discover[Time] = curr;
    for(auto i : v[curr])
        if(i != prev) dfs(i, curr);
    Out[curr] = Time;
}
void Build(int curr, int start, int end) {
    if(start == end) {
        Tree[curr] = (1LL << A[Discover[start]]);
        return;
    }
    int mid = start + end >> 1LL;
    Build(curr << 1LL, start, mid);
    Build(curr << 1LL | 1LL, mid + 1, end);
    Tree[curr] = Tree[curr << 1LL] | Tree[curr << 1LL | 1LL];
}
void pushLazy(int curr) {
    Tree[curr] = (1LL << Lazy[curr]);
    Lazy[curr << 1LL] = Lazy[curr];
    Lazy[curr << 1LL | 1LL] = Lazy[curr];
    Lazy[curr] = 0;
}
void rangeUpdate(int curr, int start, int end, int i, int j, int val) {
    if(start > end) return;
    if(Lazy[curr]) pushLazy(curr);
    if(start > j || end < i) return;
    if(start >= i && end <= j) {
        Tree[curr] = (1LL << val);
        if(start != end) {
            Lazy[curr << 1LL] = val;
            Lazy[curr << 1LL | 1LL] = val;
        }
        return;
    }
    int mid = start + end >> 1LL;
    rangeUpdate(curr << 1LL, start, mid, i, j, val);
    rangeUpdate(curr << 1LL | 1LL, mid + 1, end, i, j, val);
    Tree[curr] = Tree[curr << 1LL] | Tree[curr << 1LL | 1LL];
 
}
int rangeQuery(int curr, int start, int end, int i, int j) {
    if(Lazy[curr]) pushLazy(curr);
    if(start > j || end < i) return 0LL;
    if(start >= i && end <= j) return Tree[curr];
    int mid = start + end >> 1LL;
    return rangeQuery(curr << 1LL, start, mid, i, j) |
        rangeQuery(curr << 1LL | 1LL, mid + 1, end, i, j);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> T;
    for(int i = 1 ; i <= n ; i++) cin >> A[i];
    for(int i = 0 ; i < n - 1 ; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, -1);
    Build(1, 1, n);
 
    while(T--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x, val;
            cin >> x >> val;
            rangeUpdate(1, 1, n, In[x], Out[x], val);
        } else {
            int x, t = 0;
            cin >> x;
            int ans = rangeQuery(1, 1, n, In[x], Out[x]);
            while(ans) {
                t += (ans & 1);
                ans = ans >> 1LL;
            }
            cout << t << endl;
        }
    }
 
}