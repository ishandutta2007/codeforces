#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N = 1e6+1;
int P[1000009];
int f[1000009], a[1000009];
int par[1000009],sz[1000009];
int Par(int x){
    if(par[x] == x) return x;
    par[x] = Par(par[x]);
    return par[x];
}
void un(int x, int y){
    x = Par(x), y = Par(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    par[x] = y;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i <= N; i++){
        if(!P[i]){
            for(int j = i; j <= N; j+= i)
                P[j] = i;
        }
    }

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        sz[i] = 1; par[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        vector<int> pr;
        int x = a[i];
        while(x > 1){
            int y = P[x];
            pr.push_back(y);
            while(x % y == 0) x /= y;
        }
        for(int p : pr){
            if(!f[p]) f[p] = i;
            else un(i, f[p]);
        }
    }
    set<pair<int,int> > S;
    for(int i = 1; i <= n; i++){
        vector<int> pr;
        int x = a[i] + 1;
        while(x > 1){
            int y = P[x];
            pr.push_back(y);
            while(x % y == 0) x /= y;
        }
        int v = Par(i);
        for(int p : pr){
            if(!f[p]) continue;
            int u = Par(f[p]);
            if(u != v) S.insert({u, v});
            for(int q : pr){
                if(!f[q]) continue;
                 int w = Par(f[q]);
                 if(u != w) S.insert({u, w});
            }
        }

    }
    while(q--){
        int s, t;
        cin >> s >> t;
        int x = Par(s), y = Par(t);
        if(x == y) {
            cout << 0 << endl;
            continue;
        }
        if(S.find({x, y}) != S.end() ||
           S.find({y, x}) != S.end())
            cout<<1<<endl;
        else cout<<2<<endl;
    }


}