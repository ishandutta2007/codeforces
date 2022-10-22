#include <bits/stdc++.h>

using namespace std;

int MAX = 0, MIN = 0;

vector<vector<int> > a;
vector<int> h, first;
vector<vector<int> > sp;
vector<int> ln;

class top{
    public:
    int mn1, mn2, mx1, mx2;
    top(int m1, int m2, int m3, int m4){
        mn1 = m1;
        mn2 = m2;
        mx1 = m3;
        mx2 = m4;
    }

    top(top t1, top t2){
        if(t1.mn1 < 0 || t1.mn1 >= first.size() || t1.mn2 < 0 || t1.mn2 >= first.size() ||
           t1.mx1 < 0 || t1.mx1 >= first.size() || t1.mx2 < 0 || t1.mx2 >= first.size())exit(0);
        if(t2.mn1 < 0 || t2.mn1 >= first.size() || t2.mn2 < 0 || t2.mn2 >= first.size() ||
           t2.mx1 < 0 || t2.mx1 >= first.size() || t2.mx2 < 0 || t2.mx2 >= first.size())exit(0);
        if(first[t1.mx1] > first[t2.mx1]){
            mx1 = t1.mx1;
            mx2 = first[t1.mx2] > first[t2.mx1] ? t1.mx2 : t2.mx1;
        }
        else{
            mx1 = t2.mx1;
            mx2 = first[t1.mx1] > first[t2.mx2] ? t1.mx1 : t2.mx2;
        }

        if(first[t1.mn1] < first[t2.mn1]){
            mn1 = t1.mn1;
            mn2 = first[t1.mn2] < first[t2.mn1] ? t1.mn2 : t2.mn1;
        }
        else{
            mn1 = t2.mn1;
            mn2 = first[t1.mn1] < first[t2.mn2] ? t1.mn1 : t2.mn2;
        }
    }

};



vector<top> t;
vector<int> d;

void dfs(int v, int H){
    first[v] = h.size();
    if(first[MAX] < first[v])MAX = v;
    h.push_back(H);
    for(int i = 0; i < a[v].size(); i++){
        dfs(a[v][i], H + 1);
        h.push_back(H);
    }
}

void build(int v, int l, int r){
    if(r - l == 1){
        t[v] = top(l, MAX, l, MIN);
        return;
    }

    int m = (l + r) / 2;
    int v1 = v * 2 + 1, v2 = v * 2 + 2;
    build(v1, l, m);
    build(v2, m, r);
    t[v] = top(t[v1], t[v2]);
}

top get(int v, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr)return t[v];

    if(l >= qr || r <= ql)return top(MAX, MAX, MIN, MIN);

    int m = (r + l) / 2;
    return top(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m, r, ql, qr));
}

void buil(int v, int l, int r){
    if(r - l == 1){
        d[v] = h[l];
        return;
    }

    int m = (r + l) / 2;
    buil(v * 2 + 1, l, m);
    buil(v * 2 + 2, m, r);
    d[v] = min(d[v * 2 + 1], d[v * 2 + 2]);
}

int ged(int v, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr)return d[v];
    if(l >= qr || r <= ql)return 1e9;

    int m = (r + l) / 2;
    return min(ged(v * 2 + 1, l, m, ql, qr), ged(v * 2 + 2, m, r, ql, qr));
}

int main(){
    int n, q;
    cin >> n >> q;

    a.resize(n, vector<int>());
    for(int i = 1; i < n; i++){
        int p;
        scanf("%d", &p);
        a[p - 1].push_back(i);
    }


    first.resize(n);

    dfs(0, 0);

    d.resize(h.size() * 4);
    buil(0, 0, h.size());

    t.resize(n * 4, top(MAX, MAX, MIN, MIN));
    build(0, 0, n);

    for(int i = 0; i < q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        top tp = get(0, 0, n, l, r);
        int res1 = ged(0, 0, h.size(), first[tp.mn1], first[tp.mx2] + 1);
        int res2 = ged(0, 0, h.size(), first[tp.mn2], first[tp.mx1] + 1);
        //cout << res1 << ' ' << res2 << endl;
        if(res1 > res2){
            cout << tp.mx1 + 1 << ' ' << res1 << '\n';
        }
        else{
            cout << tp.mn1 + 1 << ' ' << res2 << '\n';
        }
    }
}