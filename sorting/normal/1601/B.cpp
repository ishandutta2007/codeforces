#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 3;
const int INF = 1e9;

int n, a[N], b[N], dist[N];
pair<int, int> par[N];
bool vis[N], vis2[N];
vector<int> adj[N];
queue<int> q;

struct SegmentTree{
    vector<int> v[4 * N];

    void update(int sl, int sr, int i = 0, int l = 0, int r = n){
        if(sr < l || r < sl) return;
        if(sl <= l && r <= sr){
            v[i].push_back(sr);
            return;
        }
        int mid = (l + r) >> 1;
        update(sl, sr, 2 * i + 1, l, mid);
        update(sl, sr, 2 * i + 2, mid + 1, r);
    }

    void query(int to, int x, int i = 0, int l = 0, int r = n){
        if(to < l || r < to) return;
        if(l <= to && to <= r){
            if(!v[i].empty()){
                for(int x2: v[i]){
                    if(vis[x2]) continue;
                    dist[x2] = dist[x] + 1;
                    par[x2] = {x, to};
                    vis[x2] = true;
                    q.push(x2);
                }
                v[i].clear();
            }
        }
        if(l == r) return;
        int mid = (l + r) >> 1;
        query(to, x, 2 * i + 1, l, mid);
        query(to, x, 2 * i + 2, mid + 1, r);
    }
} st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];

    for(int i = 1; i <= n; ++i)
        st.update(i - a[i], i);
    for(int i = 1; i <= n; ++i)
        adj[i + b[i]].push_back(i);
    for(int i = 1; i <= n; ++i)
        dist[i] = INF;

    
    st.query(0, 0);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == n) break;

        for(int to: adj[x]){
            if(vis2[to]) continue;
            vis2[to] = true;
            
            st.query(to, x);
        }
    }

    if(dist[n] == INF) dist[n] = -1;
    cout << dist[n] << "\n";
    if(dist[n] != -1){
        while(n){
            cout << par[n].second << " ";
            n = par[n].first;
        }
        cout << "\n";
    }
}