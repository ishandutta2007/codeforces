#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2000 + 13;
const int K = 30;
const int M = 1e9 + 7;
const int LOGN = 20;


int n;
int a[N];
vector<int> g[N + K];
bool used[N + K];

void dfs(int v) {
    used[v] = true;

//    cout << "dfs " << v << endl;

    if(v >= n) {
        int j = v - n;
        for(int i = 0; i < n; i++) {
            if(!used[i] && (a[i] & (1 << j)))
                dfs(i);
        }
    } else {
        for(int j = 0; j < K; j++) {
            if((a[v] & (1 << j)) && !used[n + j])
                dfs(n + j);

        }
    }
}

bool check() {
//    cout << "check" << endl;
    dfs(0);
//    cout << "check" << endl;
//    for(int i = 0; i < n; i++)
//        cout << a[i] << ' ';
//    cout << endl;
//    for(int i = 0; i < n; i++)
//        cout << used[i] << ' ';
//    cout << endl;

    bool fl = false;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            fl = true;
        }
        used[i] = false;
    }
    for(int i = n; i < n + K; i++)
        used[i] = false;
    return !fl;
}

void solve() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        used[i] = false;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(a[i] == 0) {
            a[i]++;
            ans++;
        }
    }


//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < K; j++) {
//            if(a[i] & (1 << j)) {
//
//            }
//        }
//    }



    if(check()) {
        cout << ans << endl;
        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++) for(int x = -1; x <= 1; x += 2) {
        a[i] += x;
        if(check()) {
            cout << ans + 1 << endl;
            for(int i = 0; i < n; i++)
                cout << a[i] << ' ';
            cout << endl;
            return;
        }
        a[i] -= x;
    }

    int mx = 0;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        int x = 0;
        while(((1 << x) & a[i]) == 0) {
            x++;
        }

        if(mx < x) {
            mx = x;
            res.erase(res.begin(), res.end());
            res.push_back(i);
        } else if(mx == x) {
            res.push_back(i);
        }
    }

//    cout << "res" << endl;
//    for(int x : res)
//        cout << x << ' ';
//    cout << endl;

    a[res[0]]--;
    a[res[1]]++;

    cout << ans + 2 << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;

//    bool fl = false;
//    int cnt = 0;
//    vector<int> ind;
//    for(int i = 0; i < n; i++) {
//        if(a[i] & 1)
//            fl = true;
//        if(!used[i]) {
//            cnt++;
//            dfs(i);
//            if((a[i] & 1) == 0)
//                ind.push_back(i);
//        }
//    }
//
//    cout << "cnt = " << cnt << endl;
//
//    if(cnt == 1) {
//        cout << 0 << endl;
//    } else {
//        for(int i : ind)
//            a[i]++;
//        cout << ind.size() << endl;
//    }
//
//    for(int i = 0; i < n; i++)
//        cout << a[i] << ' ';
//    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}