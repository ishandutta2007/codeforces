#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 200010

int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void solve() {
    int n, m, a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    vector <pii> e;
    for(int i = 1; i <= n; i ++) f[i] = i;
    while(m --) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x == a || x == b || y == a || y == b) {
            e.push_back(pii(x, y));
        }
        else {
            x = find(x), y = find(y);
            f[x] = y;
        }
    }
    set <int> A, B;
    for(int i = 0; i < e.size(); i ++) {
        int x = e[i].first, y = e[i].second;
        if(x == a && y == b) continue;
        if(y == a && x == b) continue;
        if(x == a || y == a) {
            if(y == a) swap(x, y);
            A.insert(find(y));
        }
        if(x == b || y == b) {
            if(y == b) swap(x, y);
            B.insert(find(y));
        }
    }
    int aa = 0, bb = 0;
    for(int i = 1; i <= n; i ++) if(A.count(find(i)) && !B.count(find(i))) aa ++;
    for(int i = 1; i <= n; i ++) if(B.count(find(i)) && !A.count(find(i))) bb ++;
    cout << 1ll * aa * bb << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}