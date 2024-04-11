#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2000 + 13;

vector<int> g[N];
int n;

vector<int> get(int v) {
    cout << "? " << v + 1 << endl;
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);


    cin >> n;

    vector<int> a = get(0);
    vector<pii> e;
//    for(int i = 0; i < n; i++) {
//        if(a[i] == 1) {
//            g[0].push_back(i);
//            e.emplace_back(1, i + 1);
//        }
//    }

    vector<int> c(2, 0);
    for(int i = 1; i < n; i++)
        c[a[i] % 2]++;

    int x = (c[0] < c[1] ? 0 : 1);

    for(int v = 0; v < n; v++) {
        if(a[v] % 2 == x) {
            vector<int> b = (v == 0 ? a : get(v));
            for(int i = 0; i < n; i++)
                if(b[i] == 1)
                    e.emplace_back(v + 1, i + 1);
        }
    }

    cout << "!" << endl;
    for(auto p : e)
        cout << p.f << ' ' << p.s << endl;

}