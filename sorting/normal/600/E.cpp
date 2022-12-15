#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 3;

struct Info{
    map<int, int> cnt;
    int mx;
    ll sum;

    Info(){
        mx = sum = 0;
    }
} info[N];

int n, c[N];
pair<int, int> e[N];
vector<int> adj[N];
ll ans[N];

void add(int idx, int x, int cnt_x){
    info[idx].cnt[x] += cnt_x;
    if(info[idx].cnt[x] > info[idx].mx){
        info[idx].mx = info[idx].cnt[x];
        info[idx].sum = x;
    }
    else if(info[idx].cnt[x] == info[idx].mx)
        info[idx].sum += x;
}

void merge(int l, int r){
    if(info[l].cnt.size() < info[r].cnt.size()){
        swap(info[l], info[r]);
    }

    for(auto [x, cnt_x]: info[r].cnt){
        add(l, x, cnt_x);
    }
}

void dfs(int u, int p = -1){
    for(int to: adj[u]){
        if(to == p)
            continue;
        dfs(to, u);
        merge(u, to);
    }
    add(u, c[u], 1);
    ans[u] = info[u].sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    for(int i = 0; i < n - 1; ++i){
        cin >> e[i].first >> e[i].second;
        adj[e[i].first].push_back(e[i].second);
        adj[e[i].second].push_back(e[i].first);
    }

    int root = 1;
    dfs(root);

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}