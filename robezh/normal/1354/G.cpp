#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937 rng(2333);
int n, k;

int ask(vi a, vi b) {
    if(a.empty() && b.empty()) return 0;
    if(a.empty()) return -1;
    if(b.empty()) return 1;
    cout << "? " << sz(a) << " " << sz(b) << '\n';
    for(auto x : a) cout << x << " ";
    cout << '\n';
    for(auto x : b) cout << x << " ";
    cout << '\n';
    fflush(stdout);
    string str;
    cin >> str;
    char c = str[0];
    return c == 'F' ? 1 : (c == 'E' ? 0 : -1);
}

void answer(int x) {
    cout << "! " << x << '\n';
    fflush(stdout);
}

int good[15];

vi make_range(int l, int r) {
    vi res;
    for(int j = l; j <= r; j++) res.push_back(j);
    return res;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        if(n <= 10) {
            fill(good, good + n + 1, 1);
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    int ans = ask({i}, {j});
                    if(ans == 1) good[j] = 0;
                    if(ans == -1) good[i] = 0;
                }
            }
            for(int i = 1; i <= n; i++) {
                if(!good[i]) {
                    answer(i);
                    break;
                }
            }
        }
        else {
            bool bad = false;
            for(int it = 0; it < 25; it++) {
                int idx = (int)(rng() % (n - 1)) + 2;
                int ans = ask({1}, {idx});
                if(ans < 0) bad = true;
            }
            if(bad) {
                answer(1);
                continue;
            }
            int pw = 1;
            while(true) {
                if(pw * 2 > n) break;
                int ans = ask(make_range(1, pw), make_range(pw + 1, pw * 2));
                if(ans > 0) break;
                pw *= 2;
            }
            int l = pw, r = min(n, 2 * pw), mid;
            while(l + 1 < r) {
                mid = (l + r) / 2;
                int ans = ask(make_range(1, mid - pw), make_range(pw + 1, mid));
                if(ans > 0) r = mid;
                else l = mid;
            }
            answer(r);
        }
    }
}