#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e3 + 3;

int n, d;
vector<int> adj[N];

int p[N], sz[N];

int get_p(int x){
    if(p[x] == x) return x;
    return p[x] = get_p(p[x]); 
}

bool unite(int x, int y){
    x = get_p(x), y = get_p(y);
    if(x == y) return false;
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    p[y] = x;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    for(int i = 1; i <= n; ++i){
        p[i] = i;
        sz[i] = 1;
    }

    int cnt = 0;
    for(int i = 0; i < d; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cnt += !unite(x, y);

        //cout << cnt << " cnt\n";
        vector<int> v(n + 1);
        for(int i = 1; i <= n; ++i)
            v[i] = (get_p(i) == i) ? sz[i] : 0;
        sort(v.begin() + 1, v.end(), greater<int>());
        int ans = 0;
        for(int i = 1; i <= cnt + 1; ++i)
            ans += v[i];
        cout << ans - 1 << "\n";
    }
}