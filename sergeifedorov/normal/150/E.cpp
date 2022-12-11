#pragma comment(linker, "/STACK:60000000") 
#define _CRT_SECURE_NO_WARNINGS 
 
#include <cstdio> 
#include <iostream> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <string> 
#include <cstring> 
#include <ctime> 
 
using namespace std; 
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++) 
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--) 
#define pb push_back 
#define mp make_pair 
#define fs first 
#define sc second 
#define all(a) a.begin(), a.end() 
 
typedef pair <int, int> pii; 
 
const int inf = (int)1e9 + 100; 
 
const int nmax = 131072; 
 
struct edge{ 
    int v, u, w, cw; 
    edge () { 
        v = u = w = cw = -1; 
    } 
}; 
 
int n, l, r, res, resu, resv; 
pii t[nmax * 2]; 
 
edge e[nmax * 2]; 
vector<int> cg[nmax], what[100000], ts, w; 
vector<pii> ord; 
int head = 0, tail = 1, ctim; 
int len[nmax], col[nmax], num[nmax], dep[nmax], cost[nmax]; 
 
void update(int dep, int cost, int v){ 
    t[nmax + dep] = max(t[nmax + dep], mp(cost, v)); 
    int pos = (nmax + dep) / 2; 
    while (pos > 0){ 
        t[pos] = max(t[pos * 2], t[pos * 2 + 1]); 
        pos /= 2; 
    } 
} 
 
pii get(int l, int r){ 
    pii res = mp(-inf, -1); 
    if (r < 0) return res; 
    l = max(l, 0) + nmax; 
    r = r + nmax; 
    while (l <= r){ 
        if (l & 1) res = max(res, t[l]); 
        if (!(r & 1)) res = max(res, t[r]); 
        l = (l + 1) / 2; 
        r = (r - 1) / 2; 
    } 
    return res; 
} 
 
struct level{ 
    vector<int> g, s; 
    vector<pii> buf; 
    int R; 
 
    level () { R = inf; } 
 
    void recalc(int v){ 
        forn(i, len[v]) 
            if (col[v] != col[e[cg[v][i]].u]){ 
                swap(cg[v][i], cg[v][len[v] - 1]); 
                len[v] --; 
                i--; 
            } 
    } 
     
    void dfs(int v, int pr){ 
         if (pr == -1){ 
             ts.clear(); 
             dep[v] = 0; 
         } 
         forn(i, len[v]) 
            if (pr != e[cg[v][i]].u){ 
                num[e[cg[v][i]].u] = cg[v][i]; 
                dep[e[cg[v][i]].u] = dep[v] + 1; 
                dfs(e[cg[v][i]].u, v); 
            } 
        ts.pb(v); 
    } 
 
    int get_up(const vector<int> &w, int res){ 
        dfs(res, -1); 
        forn(i, w.size()) 
            if (dep[w[i]] > dep[res]) 
                res = w[i]; 
        return res; 
    } 

    int find_centr(int v, int pr, int sz, int &res){
        int cnt = 1, done = 1;
            forn(i, len[v]) 
                if (pr != e[cg[v][i]].u){ 
                    int now = find_centr(e[cg[v][i]].u, v, sz, res);
                    if (now > sz / 2)
                        done = 0;
                    cnt += now;
                }
            if (sz - cnt > sz / 2)
                done = 0;
            if (done) res = v;
            return cnt;
    } 

        int chose(const vector<int> &w){
            int res = -1;
            find_centr(w[0], -1, w.size(), res);
            return res; 
//        int res = get_up(w, get_up(w, w[0])); 
  //      int cnt = dep[res] / 2; 
    //    forn(i, cnt) 
      //      res = e[num[res]].v; 
        //return res; 
    } 
     
    void calc(){ 
        dep[s.back()] = cost[s.back()] = 0; 
        for (int i = (int)s.size() - 2; i >= 0; i --){ 
            dep[s[i]] = dep[e[g[i]].v] + 1; 
             cost[s[i]] = cost[e[g[i]].v] + e[g[i]].cw; 
        } 
    } 
     
     void clean(){ 
         int now = nmax, len = s.size() + 1; 
         while (now > 0){ 
             forn(i, len) 
                 t[now + i] = mp(-inf, -1); 
             now /= 2; 
             len = (len + 1) / 2; 
         } 
    } 
     
    int solve(int l, int r, int &resu, int &resv, int mid){ 
        if (mid >= R) return 0; 
        calc(); 
        update(0, 0, s.back()); 
        for (int i = 0; i < (int)buf.size(); i ++){ 
            int j = i;      
            while (j < (int)buf.size() && buf[j].fs == buf[i].fs) j ++; 
            for (int k = i; k < j; k ++){ 
                pii now = get(l - dep[buf[k].sc], r - dep[buf[k].sc]); 
                now.fs += cost[buf[k].sc]; 
                if (now.fs >= 0){ 
                    resu = buf[k].sc; 
                    resv = now.sc; 
                    clean(); 
                    return 1; 
                } 
            } 
            for (int k = i; k < j; k ++) 
                update(dep[buf[k].sc], cost[buf[k].sc], buf[k].sc); 
            i = j - 1; 
        } 
        clean(); 
        R = min(R, mid); 
        return 0; 
    } 
 
    void init(const vector<int> &w, int msz){ 
        ctim ++; 
        forn(i, w.size()) 
            col[w[i]] = ctim; 
        forn(i, w.size()) 
            recalc(w[i]); 
        int root = chose(w); 
 
        dfs(root, -1); 
 
        s = ts; 
        g.resize(ts.size()); 
        buf.resize(ts.size()-1); 
 
        forn(i, ts.size() - 1) 
            g[i] = num[ts[i]]; 
        ford(i, g.size() - 1){ 
            if (e[num[ts[i]]].v == root) 
                col[ts[i]] = ts[i]; 
            else 
                col[ts[i]] = col[e[num[ts[i]]].v]; 
            buf[i] = mp(col[ts[i]], ts[i]); 
        } 
        sort(all(buf)); 
        for (int i = 0, j = 0; i < (int)buf.size(); i = j){ 
            while (j < (int)buf.size() && buf[j].fs == buf[i].fs) j ++; 
            if (j <= i + msz) 
                continue; 
            what[tail].resize(j - i); 
            for (int k = i; k < j; k ++) 
                what[tail][k-i] = buf[k].sc; 
            tail ++; 
        } 
    } 
} lev[100000]; 
 
void pre_calc(){ 
    forn(i, nmax * 2) 
        t[i] = mp(-inf, -1); 
    forn(i, 2 * n - 2){ 
        cg[e[i].v].pb(i); 
        len[e[i].v] ++; 
    } 
    forn(i, n) 
        what[0].pb(i); 
    while (head < tail){ 
        lev[head].init(what[head], l); 
        head ++; 
    } 
    forn(i, tail) 
        ord.pb(mp(lev[i].g.size(), i)); 
    sort(all(ord)); 
} 
 
int check(int m, int &resu, int &resv){ 
    forn(i, 2 * n - 2) 
        e[i].cw = e[i].w >= m ? 1 : -1; 
    forn(i, tail) 
        if (lev[ord[i].sc].solve(l, r, resu, resv, m)) 
            return 1; 
    return 0; 
} 
 
int main (){ 
    scanf("%d%d%d", &n, &l, &r); 
    forn(i, n-1){ 
        scanf("%d%d%d", &e[i*2].v, &e[i*2].u, &e[i*2].w); 
        e[i*2].v --; e[i*2].u --; 
        e[i*2+1] = e[i*2]; 
        swap(e[i*2+1].v, e[i*2 + 1].u); 
        w.pb(e[2*i].w); 
    } 
 
    pre_calc(); 
 
    sort(all(w)); 
    w.erase(unique(all(w)), w.end()); 
    int l = 0, r = w.size() - 1; 
    while (l < r){ 
        int m = (l + r + 1) / 2; 
        if (check(w[m], resu, resv)) 
            l = m; 
        else 
            r = m - 1; 
    } 
     
    check(w[l], resu, resv); 
    res = w[l]; 
     
    cout << resu + 1 << " " << resv + 1<< endl; 
    cerr << clock() << endl; 
 
    return 0; 
}