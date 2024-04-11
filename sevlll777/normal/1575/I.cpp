#include <bits/stdc++.h>

#define int long long
#define p pair<int, int>
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()
const int INF = 1000000000000000001;

using namespace std;

struct DO{
    vector<int> do_arr, mod;
    int len;

    DO(vector<int> &a){
        len = 1;
        while (len < a.size()){
            len *= 2;
        }
        do_arr.assign(2*len, -INF), mod.assign(2*len, 0);
        for (int q = len; q < len+a.size(); q++){
            do_arr[q] = a[q-len];
        }
        for (int q = len-1; q > 0; q--){
            do_arr[q] = max(do_arr[2*q], do_arr[2*q+1]);
        }
    }

    void push(int q){
        do_arr[2*q] += mod[q], do_arr[2*q+1] += mod[q];
        mod[2*q] += mod[q], mod[2*q+1] += mod[q], mod[q] = 0;
    }

    void update(int l, int r, int l1, int r1, int q, int x){
        if (l >= r1 || l1 >= r){
            return;
        }
        if (l1 <= l && r <= r1){
            do_arr[q] += x, mod[q] += x;
            return;
        }
        push(q);
        int m = (l+r)/2;
        update(l, m, l1, r1, 2*q, x);
        update(m, r, l1, r1, 2*q+1, x);
        do_arr[q] = max(do_arr[2*q], do_arr[2*q+1]);
    }

    int ans(int l, int r, int l1, int r1, int q){
        if (l >= r1 || l1 >= r){
            return -INF;
        }
        if (l1 <= l && r <= r1){
            return do_arr[q];
        }
        push(q);
        int m = (l+r)/2;
        return max(ans(l, m, l1, r1, 2*q), ans(m, r, l1, r1, 2*q+1));
    }
};

vector<vector<int>> d, up;
vector<int> a, tin, tout, sums, top_sort;
int time1 = 0, log1 = 20;

void make_LCA(int vertex, int parent){
    tin[vertex] = time1++;
    if (parent == -1){
        up[vertex].push_back(vertex);
        sums[vertex] = a[vertex];
    }else{
        up[vertex].push_back(parent);
        sums[vertex] = sums[parent]+a[vertex];
    }
    top_sort.push_back(sums[vertex]);
    for (int q = 1; q < log1; q++){
        up[vertex].push_back(up[up[vertex][q-1]][q-1]);
    }
    for (int q: d[vertex]){
        if (q != parent){
            make_LCA(q, vertex);
        }
    }
    tout[vertex] = time1;
}

bool is_predok(int x, int y){
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int LCA(int x, int y){
    if (is_predok(x, y)){
        return x;
    }
    if (is_predok(y, x)){
        return y;
    }
    for (int q = log1-1; q > -1; q--){
        if (!is_predok(up[x][q], y)){
            x = up[x][q];
        }
    }
    return up[x][0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    d.resize(n), a.resize(n), up.resize(n), tin.resize(n), tout.resize(n), sums.resize(n);
    for (int q = 0; q < n; q++){
        cin >> a[q];
        a[q] = abs(a[q]);
    }
    for (int q = 0; q < n-1; q++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    make_LCA(0, -1);
    DO do_arr = DO(top_sort);
    for (int q = 0; q < m; q++){
        int type, x, y;
        cin >> type >> x >> y;
        x--, y = (type == 1 ? abs(y) : y-1);
        if (type == 1){
            do_arr.update(0, do_arr.len, tin[x], tout[x], 1, y-a[x]);
            a[x] = y;
        }else{
            int lenx = do_arr.ans(0, do_arr.len, tin[x], tin[x]+1, 1), leny = do_arr.ans(0, do_arr.len, tin[y], tin[y]+1, 1);
            int z = LCA(x, y), lenz = do_arr.ans(0, do_arr.len, tin[z], tin[z]+1, 1);
            cout << 2*(lenx+leny-2*lenz)+2*a[z]-a[x]-a[y] << endl;
        }
    }
    return 0;
}