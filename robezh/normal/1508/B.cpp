#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)1e5 + 50;
ll psum[N], a[N];
int n;
ll k;



int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    psum[0] = a[0] = 1;
    rep(i, 1, N) {
        a[i] = psum[i - 1];
        psum[i] = psum[i - 1] + a[i];
        //if(i < 100) cout << i << " " << a[i] << endl;
    }


    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        int off = 0;
        vi res;
        if(n > 63) {
            off = n - 63;
            n = 63;
            rep(i, 1, off + 1) res.push_back(i - off);
        } else if(a[n] < k) {
            cout << -1 << '\n';
            continue;
        }
        int remlen = n;
        while(remlen) {
            int nxtlen = remlen - 1;

            while(nxtlen && (a[nxtlen] < k)) {
                k -= a[nxtlen];
                nxtlen--;
            }
//            nxtlen--;
//            cout << remlen << " " << k << "  " << nxtlen << endl;
            rep(i, nxtlen + 1, remlen + 1) {
                res.push_back(n - i + 1);
            }
            remlen = nxtlen;
        }
        for(int x : res) cout << x + off << " ";
        cout << endl;
    }


}