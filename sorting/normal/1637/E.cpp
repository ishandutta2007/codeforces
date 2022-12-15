#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 3;

int n, m;
vector<int> values;
vector<pair<int, int>> t[N];
unordered_set<int> edges[N];
int C;

int a[N], cnt[N];
ll ans;

int getIdx(int x){
    return lower_bound(all(values), x) - values.begin();
}

bool existsEdge(int idx1, int idx2){
    return edges[idx1].count(idx2);
}

void checkBig(int x, int idx_x){
    for(int i = 0; i < values.size(); ++i){
        int y = values[i];
        if(i == idx_x) continue;
        if(existsEdge(i, idx_x)) continue;
        check_max(ans, (ll)(x + y) * (ll)(cnt[i] + cnt[idx_x]));
    }
}

void checkSmall(int cnt_x){
    for(int i = 0; i < values.size(); ++i){
        int y = values[i];
        if(cnt[i] > C) continue;

        for(int j = (int)t[cnt_x].size() - 1; j >= 0; --j){
            int x = t[cnt_x][j].first;
            int idx_x = t[cnt_x][j].second;
            if(i == idx_x || existsEdge(i, idx_x))
                continue;

            //cout << x << " " << y << " " << cnt[i] << " " << cnt_x << endl;

            check_max(ans, (ll)(x + y) * (ll)(cnt[i] + cnt_x));
            break;
        }
    }
}

void solve(){
    ans = 0;

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    C = sqrt(n) / 2 + 1; 

    for(int i = 0; i < n; ++i)
        edges[i].clear();

    values.resize(n);
    for(int i = 0; i < n; ++i)
        values[i] = a[i];
    sort(all(values));
    values.resize(unique(all(values)) - values.begin());

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        x = getIdx(x), y = getIdx(y);
        edges[x].insert(y);
        edges[y].insert(x);
    }

    fill(cnt, cnt + n, 0);
    for(int i = 0; i < n; ++i)
        cnt[getIdx(a[i])]++;

    for(int i = 0; i < values.size(); ++i){
        int x = values[i];
        if(cnt[i] > C){
            checkBig(x, i);
        }
        else{
            t[cnt[i]].push_back({x, i});
            //cout << x << " " << i << " - " << cnt[i] << endl;
        }
    }

    for(int i = 1; i <= C; ++i)
        checkSmall(i);

    for(int i = 1; i <= C; ++i)
        t[i].clear();

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
}