#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef pair<DO, int> pdi;

#define NN 101010

int a[NN], T[NN];
pii mx[NN];
vector<pii> add[NN];
vector<pdi> multi;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int k, n, m, t, r, v;
    cin>>k>>n>>m;

    for (int i=1; i<=k; i++) scanf("%d", a+i);
    for (int i=1; i<=n; i++) {
        scanf("%d%d%d", T+i, &r, &v);
        int t=T[i];
        if (t==1) mx[r]=max(mx[r], make_pair(v, i));
        else if (t==2) add[r].push_back(make_pair(v, i));
        else multi.push_back(pdi(-v, i));
    }

    for (int i=1; i<=k; i++) {
        if (mx[i].first>a[i]) add[i].push_back(pii(mx[i].first-a[i], mx[i].second));
        sort(add[i].begin(), add[i].end(), [](pii x, pii y){return x.first>y.first;});
        INT cur=a[i];
        for (pii v : add[i]) {
            multi.push_back(pdi(-1.0*(cur+v.first)/cur, v.second));
            cur+=v.first;
        }
    }

    sort(multi.begin(), multi.end());
    if (multi.size()>m) multi.resize(m);
    VI id;
    for (pdi x : multi) id.push_back(x.second);

    sort(id.begin(), id.end(), [](int u, int v) {return T[u]<T[v];});

    printf("%d\n", id.size());
    for (int x : id) {
        printf("%d ", x);
    }
    puts("");

    return 0;
}