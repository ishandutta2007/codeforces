#include <bits/stdc++.h>
using namespace std;

const int N = (int)4e5 + 50;
typedef pair<int, int> P;

int n, m;
int f[N];
int a[N], b[N];
int s, ds, t, dt;
bool dct = false;
vector<P> res;
vector<P> can[N][2];
bool cmp[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    f[x] = y;
}
bool same(int x, int y) {return find(x) == find(y);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < N; i++) f[i] = i;
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i], a[i]--, b[i]--;
    cin >> s >> t >> ds >> dt; s--, t--;

    for(int i = 0; i < m; i++) {
        if(a[i] == s || a[i] == t || b[i] == s || b[i] == t) continue;
        if(!same(a[i], b[i])) {
            unite(a[i], b[i]);
            res.push_back({a[i], b[i]});
        }
    }


    for(int i = 0; i < n; i++) cmp[find(i)] = true;

    for(int i = 0; i < m; i++) {
        if(a[i] == s || b[i] == s) {
            if(a[i] == t || b[i] == t) dct = true;
            else {
                int now = a[i] == s ? b[i] : a[i];
                can[find(now)][0].push_back({a[i], b[i]});
            }
        }
        else if(a[i] == t || b[i] == t){
            int now = a[i] == t ? b[i] : a[i];
            can[find(now)][1].push_back({a[i], b[i]});
        }
    }


    for(int i = 0; i < n; i++) {
        if(i == s || i == t || !cmp[i]) continue;
        if(can[i][0].empty() && can[i][1].empty()) {
            return cout << "No" << endl, 0;
        }
        else if(!can[i][0].empty() && can[i][1].empty()) {
            res.push_back(can[i][0][0]);
            cmp[i] = false;
            ds --;
        }
        else if(can[i][0].empty() && !can[i][1].empty()) {
            res.push_back(can[i][1][0]);
            cmp[i] = false;
            dt --;
        }

        if(ds < 0 || dt < 0)  return cout << "No" << endl, 0;

    }

    bool fir = true;
    for(int i = 0; i < n; i++) {
        if(i == s || i == t || !cmp[i]) continue;
        if(fir) {
            fir = false;
            res.push_back(can[i][0][0]);
            res.push_back(can[i][1][0]);
            ds--, dt --;
            if(ds < 0 || dt < 0)  return cout << "No" << endl, 0;
            continue;
        }

        if(ds > 0) {
            res.push_back(can[i][0][0]);
            ds --;
        }
        else if(dt > 0) {
            res.push_back(can[i][1][0]);
            dt --;
        }
        else {
            return cout << "No" << endl, 0;
        }
    }
    if(fir) {
        if(dct) {
            res.push_back({s, t});
            ds --, dt--;
        }
        else return cout << "No" << endl, 0;
    }
    if(ds < 0 || dt < 0) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    for(const auto &p : res) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }


}