//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int a[N];
vector<int> g[N];
li ans[N];
//int sz[N];
map<int, int>* vmp[N];
int vres[N];

void dfs(int v, int par) {
    vmp[v] = new map<int, int>();
    (*vmp[v])[a[v]]++;
    vres[v] = 1;

    int  mxu = v;
    ans[v] = a[v];
    vector<int> ind(1, v);
    for(auto u : g[v]) {
        if(u == par)
            continue;

        dfs(u, v);
        ind.push_back(u);

        if(vmp[u]->size() > vmp[mxu]->size()) {
            mxu = u;
        }
    }

//    vmp[v] = vmp[mxu];
    map<int, int>* mp = vmp[mxu];
    int res = vres[mxu];
    ans[v] = ans[mxu];

//    for(auto p : mp) {
//        cout << "v " << v << ' ' << "mp before " << p.f << ' ' << p.s << endl;
//    }
//    cout << "res size before " << res.size() << endl;
//    for(auto p : res) {
//        cout << "v " << v << ' ' << "res before " << p.f << ' ' << p.s << endl;
//    }

    for(int i : ind) {
        if(i == mxu)
            continue;

        for(auto p : *vmp[i]) {


//            int& x = mp[p.f];
//            li& y = res[x];
//            y -= p.f;
//            x += p.s;
//            y += p.f;

            int& x = (*mp)[p.f];
            if(x == res)
                ans[v] -= p.f;
//            li& y = res[x];
//            res[x] -= p.f;
            x += p.s;
            if(x == res)
                ans[v] += p.f;
            else if(x > res) {
                res = x;
                ans[v] = p.f;
            }
//            res[x] += p.f;

//            res[mp[p.f]] -= p.f;
//            mp[p.f] += p.s;
//            res[mp[p.f]] += p.f;
        }

//        cout << "---------- " << res[1] << endl;
    }

//    for(auto p : mp) {
//        cout << "v " << v << ' ' << "mp after " << p.f << ' ' << p.s << endl;
//    }
//    for(auto p : res) {
//        cout << "v " << v << ' ' << "res after " << p.f << ' ' << p.s << endl;
//    }

    vmp[v] = mp;
    vres[v] = res;
//    ans[v] = res.rbegin()->s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}