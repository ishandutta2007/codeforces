#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int K = N * 30;
const int LOG = 30;

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
}

int a[N];

int cur = 1;
int g[K][2];
int cnt[K];

void add(int x, int d) {
    int v = 0;
    for(int i = 0; i < LOG; i++) {
        int bit = (x >> (LOG - i - 1)) & 1;
        if(g[v][bit] == 0) {
            g[v][bit] = cur;
            cur++;
        }
        cnt[v] += d;
        v = g[v][bit];
    }
    cnt[v] += d;
}

int get(int x) {
    int v = 0;
    int res = 0;
    for(int i = 0; i < LOG; i++) {
        int bit = (x >> (LOG - i - 1)) & 1;
        if(g[v][bit] == 0 || cnt[g[v][bit]] == 0)
            bit ^= 1;

        res = ((res << 1) | bit);
        v = g[v][bit];
    }

    return res;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a1(n);

    for(int i = 0; i < n; i++) {
        cin >> a1[i];
    }
//return 0;
    sort(a1.begin(), a1.end());
    a1.erase(unique(a1.begin(), a1.end()), a1.end());

    n = a1.size();
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        a[i] = a1[i];
        mp[a[i]] = i;
//        cout << a[i] << ' ';
    }
//    cout << endl;

//    vector<vector<int>> b(n, vector<int>(1));
//    for(int i = 0; i < n; i++) {
//        b[i][0] = i;
//    }

    for(int i = 0; i < n; i++) {
        add(a[i], 1);
    }

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    li ans = 0;
//    cout << "sg" << endl;

    while(true) {
        vector<vector<int>> b(n);
        for(int i = 0; i < n; i++) {
            b[getp(i)].push_back(i);
        }
//
//        cout << "while " << endl;
//        for(int i = 0; i < n; i++) {
//            cout << i << "  : ";
//            for(auto x : b[i])
//                cout << x << ' ';
//            cout << endl;
//        }

        if(b[p[0]].size() == n)
            break;

        set<pii> e;
        for(int i = 0; i < b.size(); i++) if(!b[i].empty()) {
            for(int j = 0; j < b[i].size(); j++) {
                add(a[b[i][j]], -1);
            }

            int mn = INF, v = -1, u = -1;
            for(int j = 0; j < b[i].size(); j++) {
                int x = a[b[i][j]];
                int y = get(x);

                if((x ^ y) < mn) {
                    mn = (x ^ y);
                    v = b[i][j];
                    u = y;
                }
            }

            u = mp[u];

//            cout << "edge " << i << ' ' << v << ' ' << u << endl;

            e.insert({min(v, u), max(v, u)});

            for(int j = 0; j < b[i].size(); j++) {
                add(a[b[i][j]], 1);
            }
        }

        for(auto pr : e) {
//            cout << pr.f << ' ' << pr.s << ' ' << a[pr.f] <<' ' << a[pr.s] << endl;
            unite(pr.f, pr.s);
            ans += (a[pr.f] ^ a[pr.s]);
        }
    }

    cout << ans << endl;
}