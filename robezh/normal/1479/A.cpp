#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50, INF = (int)1e9 + 50;

int n;

mt19937 rng(2333);
int p[N];

int ask(int pos) {
    if(pos == 0 || pos == n + 1) return INF;
//    return p[pos];

    cout << "? " << pos << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

int main() {

//    ios::sync_with_stdio(false);
//    cin.tie(NULL);


    int T;
//    cin >> T;
    T = 1;
    while(T--) {
//        n = 5;
//        iota(p + 1, p + n + 1, 1);
//        shuffle(p + 1, p + n + 1, rng);



        cin >> n;
        int l = 0, r = n + 1;
        int mid;
        int res = -1;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            int vm = ask(mid);
            int vr = ask(mid + 1);
            if(vr < vm) l = mid;
            else {
                int vl = ask(mid - 1);
                if(vl < vm) {
                    r = mid;
                } else {
//                    cout << "! " << mid << endl;
//                    int x = mid;
//                    assert(x == 1 || p[x] < p[x - 1]);
//                    assert(x == n || p[x] < p[x + 1]);
                    res = mid;
                    break;
//                    assert()
//                    fflush(stdout);
                }
            }
        }
        if(res == -1) {
            res = (ask(l) < ask(r) ? l : r);
        }
        cout << "! " << res << endl;
        fflush(stdout);
//        cout << l << " " << r << endl;
    }


}