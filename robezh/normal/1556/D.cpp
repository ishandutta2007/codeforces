#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e4 + 50;


mt19937 rng(2333);
int b[N];

int get_or(int i, int j) {
    cout << "or " << i + 1 << " " << j + 1 << endl;
    fflush(stdout);
    int x; cin >> x;
    return x;

//    return b[i] | b[j];
}

int get_and(int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    fflush(stdout);
    int x; cin >> x;
    return x;

//    return b[i] & b[j];
}


int n, k, a[N];
int cor[3], cand[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
//    n = 100, k = 2;
//    rep(i, 0, n) {
//        b[i] = rng() % 1000;
//    }
    rep(i, 0, 3) {
        cor[i] = get_or(i, (i + 1) % 3);
        cand[i] = get_and(i, (i + 1) % 3);

    }
    rep(bt, 0, 30) {

//        cout <<  (b[0] >> bt & 1)  << " " << (b[1] >> bt & 1)  << " " << (b[2] >> bt & 1) << endl;
//        cout <<  (cor[0] >> bt & 1)  << " " << (cor[1] >> bt & 1)  << " " << (cor[2] >> bt & 1) << endl;
        int bor = (int)(cor[0] >> bt & 1) + (int)(cor[1] >> bt & 1) + (int)(cor[2] >> bt & 1);
//        cout << bor << endl;

        if(bor == 0) {
        } else if(bor == 2) {
            for (int j = 0; j < 3; j++) {
                if((cor[j] >> bt & 1) == 0) {
                    a[(j + 2) % 3] |= (1 << bt);
                }
            }
        } else {
            int band = (int)(cand[0] >> bt & 1) + (int)(cand[1] >> bt & 1) + (int)(cand[2] >> bt & 1);
            if(band == 3) {
                for (int j = 0; j < 3; j++) a[j] |= (1 << bt);
            } else {
//                cout << band << endl;
                assert(band == 1);
                for (int j = 0; j < 3; j++) {
                    if((cand[j] >> bt & 1) == 1) {
                        a[j] |= (1 << bt);
                        a[(j + 1) % 3] |= (1 << bt);
                    }
                }
            }
        }
    }
    rep(i, 3, n) {
        int aor = get_or(0, i);
        int aand = get_and(0, i);
        rep(b, 0, 30) {
            if(a[0] >> b & 1) {
                if(aand >> b & 1) a[i] |= (1 << b);
            } else {
                if(aor >> b & 1) a[i] |= (1 << b);
            }
        }
    }
    sort(a, a + n);
    cout << "finish " << a[k - 1] << endl;
    fflush(stdout);
//    rep(i, 0, n) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//    rep(i, 0, n) {
//        cout << b[i] << " ";
//    }
//    cout << endl;

}