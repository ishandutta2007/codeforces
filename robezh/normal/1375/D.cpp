#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1005;

int n;
int a[N];
bool in[N];

int find_mex() {
    fill(in, in + n + 1, false);
    for(int i = 0; i < n; i++) in[a[i]] = true;
    for(int i = 0; i <= n; i++) {
        if(!in[i]) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        vi res;
        while(true) {
            int f = find_mex();
            if(f == n) break;
            res.push_back(f);
            a[f] = f;
        }

        rep(i, 0, n) {
            if(a[i] != i) {
                if(find_mex() != i) {
                    int idx = -1;
                    rep(j, 0, n) {
                        if(a[j] == i) {idx = j; break;}
                    }
                    a[idx] = find_mex();
                    res.push_back(idx);
                }
                assert(find_mex() == i);
                res.push_back(i);
                a[i] = i;
            }
        }
        cout << sz(res) << '\n';
        for(int x : res) cout << x + 1 << ' ';
        cout << '\n';

    }
}