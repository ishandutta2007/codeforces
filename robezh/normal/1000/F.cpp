#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 500, INF = (int)1e9;

struct P{
    int first, second;
    bool operator < (const P & p) const {
        return first == p.first ? second < p.second : first < p.first;
    }
};


int n,m,t,a,b,q;
P dat[N * 4];
int ocu[N], las[N];
int num[N], res[N];
vector<P> que[N];

void update(int a, int b, int x, int l, int r, P p){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        dat[x] = p;
        return ;
    }
    update(a, b, x*2+1, l, mid, p);
    update(a, b, x*2+2, mid+1, r, p);

    dat[x] = min(dat[2*x+1], dat[2*x+2]);
}

P query(int a, int b, int x, int l, int r){
    if(r < a || b < l) return {INF, INF};

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return dat[x];

    P LHS = query(a, b, x*2+1, l, mid);
    P RHS = query(a, b, x*2+2, mid+1, r);

    return min(LHS, RHS);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        a--, b--;
        que[b].push_back({a, i});
    }
    fill(ocu, ocu + N, -1);
    for(int i = 0; i < n; i++){
        las[i] = ocu[num[i]];
        ocu[num[i]] = i;
    }
    for(int i = 0; i < n; i++){
        if(las[i] >= 0) update(las[i], las[i], 0, 0, n-1, {las[i], las[i]});
        update(i, i, 0, 0, n-1, {las[i], num[i]});

        for(P p : que[i]){
            auto ans = query(p.first, i, 0, 0, n-1);
            if(ans.first >= p.first) res[p.second] = 0;
            else res[p.second] = ans.second;
        }
    }
    for(int i = 0; i < q; i++) cout << res[i] << endl;
}