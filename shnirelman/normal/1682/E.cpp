#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 2e6 + 9;
const int LOGN = 20;

pii key[M * 2];
int val[M * 2];
pii null = pii(0, 0);

int get(pii x) {
    if(x.f > x.s)
        swap(x.f, x.s);
    int i = (x.f * 13 + x.s + 17) % M;
    while(key[i] != null && key[i] != x) {
//        cout << "get " << i << ' ' << x.f << ' ' << x.s << ' ' << key[i].f << ' ' << key[i].s << endl;
        i++;
    }

    return i;
}


int a[N], wh[N];
pii e[N];
map<pii, int> mp;
//int deg[N];

vector<int> g[N];
int tin[N], tout[N];
int T = 1;

int p[N][LOGN];

void dfs(int v, int par) {
    tin[v] = T++;

    p[v][0] = par;
    for(int i = 1; i < LOGN; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];

//    cout << "dfs " << v << endl;
//    for(int i = 0; i < 5; i++)
//        cout << p[v][i] << ' ';
//    cout << endl;

    for(int u : g[v])
        if(u != par)
            dfs(u, v);

    tout[v] = T++;
}

bool is_anc(int anc, int v) {
    return (tin[anc] <= tin[v] && tout[v] <= tout[anc]);
}

int get(int anc, int v) {
//    cout << "get -------------------- " << v << ' ' << anc << endl;
    for(int i = LOGN - 1; i >= 0; i--)
        if(!is_anc(p[v][i], anc)) {
//            cout << i << ' ' << p[v][i] << endl;
            v = p[v][i];
        }

//    cout << "get -------------------- " << v << ' ' << anc << endl;
    return v;
}

//mt19937 rnd(364357);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        wh[a[i]] = i;
    }

    for(int i = 0; i < m; i++) {
        cin >> e[i].f >> e[i].s;
        e[i].f--;
        e[i].s--;

        if(e[i].f > e[i].s)
            swap(e[i].f, e[i].s);

//        mp[e[i]] = i;
//        swap(e[i].f, e[i].s);
//        mp[e[i]] = i;
        int ind = get(e[i]);
        key[ind] = e[i];
        val[ind] = i;
//        cout << ind << endl;

//        deg[e[i].f]++;
//        deg[e[i].s]++;

        g[e[i].f].push_back(e[i].s);
        g[e[i].s].push_back(e[i].f);
    }

    for(int i = 0; i < n; i++) {
        if(tin[i] == 0) {
            dfs(i, i);
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        int v = e[i].f, u = e[i].s;
        if(is_anc(u, v))
            swap(u, v);

        if(is_anc(u, a[v]) && !is_anc(u, a[u]))
            q.push(i);
    }

//    {
////            vector<int> x;
//            queue<int> q1 = q;
//            cout << "qqqqqqqqqq : ";
//            while(!q1.empty()) {
//                cout << q1.front() << ' ';
//                q1.pop();
//            }
//            cout << endl;
//        }

    vector<int> ans;
    while(!q.empty() && ans.size() < m) {
        int i = q.front();
        q.pop();

        int v = e[i].f, u = e[i].s;
        if(is_anc(u, v))
            swap(u, v);

//        cout << "swap " << i << ' ' << v << ' ' << u << endl;

        ans.push_back(i);
        swap(a[v], a[u]);

//        cout << "a : ";
//        for(int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//        cout << endl;

        if(v != a[v]) {
            if(is_anc(v, a[v])) {
                int w = get(v, a[v]);
//                cout << "wwwwww = " << w << endl;
                if(!is_anc(w, a[w])) {
//                    cout << "add1 " << val[get(pii(v, w))] << ' ' << v << ' ' << w << ' ' << get(pii(v, w)) << endl;
                    q.push(val[get(pii(v, w))]);
                }

            } else if(is_anc(v, a[p[v][0]])) {
//                cout << "add2 " << val[get(pii(v, p[v][0]))] << ' ' << v << ' ' << p[v][0] << ' ' << get(pii(v, p[v][0])) << endl;
                q.push(val[get(pii(v, p[v][0]))]);
            }
        }

//        cout << q.size() << endl;

        if(u != a[u]) {
            int w = get(u, a[u]);
            if(!is_anc(w, a[w])) {
//                cout << "add3 " << val[get(pii(u, w))] << ' ' << u << ' ' << w << ' ' << get(pii(u, w)) << endl;
                q.push(val[get(pii(u, w))]);
            }

        }

//        {
////            vector<int> x;
//            queue<int> q1 = q;
//            cout << "qqqqqqqqqq : ";
//            while(!q1.empty()) {
//                cout << q1.front() << ' ';
//                q1.pop();
//            }
//            cout << endl;
//        }



//        cout << q.size() << endl;

    }
//    reverse(ans.begin(), ans.end());

    for(int x : ans)
        cout << x + 1 << ' ';
    cout << endl;
}