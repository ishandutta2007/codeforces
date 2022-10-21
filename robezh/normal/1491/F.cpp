#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 2005;

bool ask_pre(int l, int r, int x) {
    cout << "? " << r - l + 1 << " " << 1 << '\n';
    rep(i, l, r + 1) cout << i << " ";
    cout << "\n";
    cout << x << '\n';
    fflush(stdout);
    int val;
    cin >> val;
    return val != 0;
}

int n;
bool mag[N];

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        memset(mag, 0, sizeof(mag));
        cin >> n;

        int sec = 2;
        while(!ask_pre(1, sec - 1, sec)) sec++;
        mag[sec] = true;
        rep(i, sec + 1, n + 1) mag[i] = ask_pre(1, sec - 1, i);
        int l = 0, r = sec - 1, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(ask_pre(1, mid, sec)) r = mid;
            else l = mid;
        }
        mag[r] = true;
        vi res;
        rep(i, 1, n + 1) if(!mag[i]) res.push_back(i);
        cout << "! ";
        cout << sz(res) << " ";
        for(int x : res) cout << x << " ";
        cout << '\n';
        fflush(stdout);
    }



}