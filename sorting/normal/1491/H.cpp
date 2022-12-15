#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
const int C = 300;

int n, q, a[N], lp[N], fa[N];
bool b[N];

int get_bucket(int i){
    return (i - 1) / C;
}

void update_all(int i, int x){
    if(b[i]){
        lp[i] += x;
        return;
    }

    b[i] = true;
    for(int j = i * C + 1; j <= (i + 1) * C; ++j){
        a[j] = max(1, a[j] - x);
        fa[j] = j;
        if(a[j] < i * C + 1) fa[j] = j;
        else fa[j] = fa[a[j]];

        if(fa[j] != j) b[i] = false;
    }
}

void update_part(int i, int l, int r, int x){
    if(b[i]){
        for(int j = l; j <= r; ++j)
            a[j] = max(1, a[j] - x);
        return;
    }

    b[i] = true;
    for(int j = i * C + 1; j <= min((i + 1) * C, n); ++j){
        if(l <= j && j <= r) a[j] = max(1, a[j] - x);
        fa[j] = j;
        if(a[j] < i * C + 1) fa[j] = j;
        else fa[j] = fa[a[j]];

        if(fa[j] != j) b[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 2; i <= n; ++i)
        cin >> a[i];

    a[1] = 1;
    
    for(int i = 0; i <= get_bucket(n); ++i){
        int idx = i * C + 1;
        fa[idx] = idx;

        b[i] = true;
        for(int j = idx + 1; j <= min(n, (i + 1) * C); ++j){
            fa[j] = j;
            if(a[j] < idx) fa[j] = j;
            else fa[j] = fa[a[j]];

            if(fa[j] != j) b[i] = false;
        }
    }

    for(int i = 1; i <= q; ++i){
        int t;
        cin >> t;

        if(t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            int bl = get_bucket(l), br = get_bucket(r);
            for(int i = bl + 1; i < br; ++i)
                update_all(i, x);

            if(bl == br) update_part(bl, l, r, x);
            else{
                update_part(bl, l, (bl + 1) * C, x);
                update_part(br, br * C + 1, r, x);
            }
        }
        else{
            int u, v;
            cin >> u >> v;
            while(u != v){
                if(u < v) swap(u, v);
                if(fa[u] >= v){
                    u = fa[u];
                    if(u == v) break;
                    u = max(1, a[u] - lp[get_bucket(u)]);
                    continue;
                }
                if(fa[u] != fa[v]){
                    u = a[fa[u]];
                    v = a[fa[v]];
                    continue;
                }
                while(u != v){
                    u = a[u];
                    if(u < v) swap(u, v);
                }
            }

            cout << u << "\n";
        }
    }
}