#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;


int n, m, q, x[N], y[N], z[N], type[N], p[N], val[N], rnk[N];
map < pair < int, int >, pair < int, int > > edge;
pair < pair < int, int >, int > cur;
vector < pair < pair < int, int >, int > > t[5 * N];
vector < pair < int, int > > roll1, roll2, roll3;

/// DSU BEGIN
inline int dsu_get_parent(int v){
    while(v != p[v]){
        v = p[v];
    }
    return v;
}

inline int dsu_get_val(int v){
    int ans = 0;
    while(v != p[v]){
        ans ^= val[v];
        v = p[v];
    }
    return ans;
}

inline bool dsu_unite(int x, int y, int z){
    int px = dsu_get_parent(x), py = dsu_get_parent(y);
    if(px == py){
        return false;
    }
    if(rnk[px] < rnk[py]){
        roll1.push_back(make_pair(px, val[px]));
        val[px] = dsu_get_val(x) ^ z ^ dsu_get_val(y);
        roll2.push_back(make_pair(px, p[px]));
        p[px] = py;
    }
    else{
        roll1.push_back(make_pair(py, val[py]));
        val[py] = dsu_get_val(x) ^ z ^ dsu_get_val(y);
        roll2.push_back(make_pair(py, p[py]));
        p[py] = px;
        if(rnk[px] == rnk[py]){
            roll3.push_back(make_pair(px, rnk[px]));
            rnk[px]++;
        }
    }
    return true;
}

inline void rollback1(int t){
    while(roll1.size() > t){
        val[roll1.back().first] = roll1.back().second;
        roll1.pop_back();
    }
}

inline void rollback2(int t){
    while(roll2.size() > t){
        p[roll2.back().first] = roll2.back().second;
        roll2.pop_back();
    }
}

inline void rollback3(int t){
    while(roll3.size() > t){
        rnk[roll3.back().first] = roll3.back().second;
        roll3.pop_back();
    }
}

/// DSU END

vector < int > bas;

inline void add(int x){
    for(auto it : bas){
        x = min(x, x ^ it);
    }
    if(x){
        for(auto &it : bas){
            it = min(it, it ^ x);
        }
        bas.push_back(x);
        sort(bas.rbegin(), bas.rend());
    }
}

inline int get(int x){
    for(auto it : bas){
        x = min(x, x ^ it);
    }
    return x;
}

void update(int v, int l, int r, int tl, int tr){
    if(l > r || l > tr || tl > r){
        return;
    }
    if(tl <= l && r <= tr){
        t[v].push_back(cur);
        return;
    }
    int mid = (r + l) >> 1;
    update(v + v, l, mid, tl, tr);
    update(v + v + 1, mid + 1, r, tl, tr);
}

void rec(int v, int l, int r){
    vector < int > save_bas = bas;
    int save_time1 = roll1.size(),
        save_time2 = roll2.size(),
        save_time3 = roll3.size();
    for(auto it : t[v]){
        int x = it.first.first, y = it.first.second, z = it.second;
        if(!dsu_unite(x, y, z)){
            add(dsu_get_val(x) ^ z ^ dsu_get_val(y));
        }
    }
    if(l == r){
        if(type[l] == 3){
            cout << get(dsu_get_val(x[l]) ^ dsu_get_val(y[l])) << "\n";
        }
    }
    else{
        int mid = (r + l) >> 1;
        rec(v + v, l, mid);
        rec(v + v + 1, mid + 1, r);
    }
    rollback1(save_time1);
    rollback2(save_time2);
    rollback3(save_time3);
    bas = save_bas;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edge[make_pair(x, y)] = make_pair(z, 0);
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> type[i];
        if(type[i] == 1){
            cin >> x[i] >> y[i] >> z[i];
            edge[make_pair(x[i], y[i])] = make_pair(z[i], i);
        }
        else if(type[i] == 2){
            cin >> x[i] >> y[i];
            cur = make_pair(make_pair(x[i], y[i]), edge[make_pair(x[i], y[i])].first);
            update(1, 0, q, edge[make_pair(x[i], y[i])].second, i - 1);
            edge.erase(make_pair(x[i], y[i]));
        }
        else{
            cin >> x[i] >> y[i];
        }
    }
    for(auto it : edge){
        cur = make_pair(it.first, it.second.first);
        update(1, 0, q, it.second.second, q);
    }
    for(int i = 1; i <= n; i++){
        p[i] = i;
        val[i] = 0;
    }
    rec(1, 0, q);
}