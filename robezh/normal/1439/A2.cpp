#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 105;

struct P {
    int a, b, c, d, e, f;
};

int n, m;
string s[N];
int mp[N][N];


vector<P> res;

void change(int a, int b, int c, int d, int e, int f) {
    res.push_back({a, b, c, d, e, f});
    mp[a][b] ^= 1;
    mp[c][d] ^= 1;
    mp[e][f] ^= 1;
}

P p[4] = {{0, 0, 0, 1, 1, 0},
          {0, 1, 1, 0, 1, 1},
          {1, 0, 1, 1, 0, 0},
          {1, 1, 0, 0, 0, 1}};

int get(int mask, int a, int b, int c, int d) {
    int res[2][2] = {{a, b}, {c, d}};
    for(int i = 0; i < 4; i++) {
        if(mask >> i & 1) {
            P x = p[i];
            res[x.a][x.b] ^= 1;
            res[x.c][x.d] ^= 1;
            res[x.e][x.f] ^= 1;
        }
    }
    return res[0][0] ==  0 && res[0][1] == 0 && res[1][0] == 0 && res[1][1] == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        res.clear();
        cin >> n >> m;

        rep(i, 0, n) {
            cin >> s[i];
            for(int j = 0; j < m; j++) mp[i][j] = s[i][j] - '0';
        }

        for(int i = n - 1; i >= 2; i--) {
            rep(j, 0, m) {
                if(mp[i][j]) {
                    if(j + 1 < m) change(i - 1, j, i - 1, j + 1, i, j);
                    else change(i - 1, j - 1, i - 1, j, i, j);
                }
            }
        }

//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++) cout << mp[i][j];
//            cout << endl;
//        }
        for(int j = m - 1; j >= 2; j--) {
            if(mp[0][j]) change(0, j - 1, 1, j - 1, 0, j);
            if(mp[1][j]) change(0, j - 1, 1, j - 1, 1, j);
        }

//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++) cout << mp[i][j];
//            cout << endl;
//        }
        rep(mask, 0, (1 << 4)) {
//            cout << mp[0][0] << mp[0][1] << mp[1][0] << mp[1][1] << endl;
            if(get(mask, mp[0][0], mp[0][1], mp[1][0], mp[1][1])) {
                rep(i, 0, 4) {
                    if(mask >> i & 1) {
                        P x = p[i];
                        change(x.a, x.b, x.c, x.d, x.e, x.f);
                    }
                }
//                cout << mask << endl;
//                cout << "nice " << endl;
                break;
            }
        }
        cout << res.size() << '\n';
        for(auto p : res) {
            cout << p.a + 1 <<  " " << p.b + 1 << " " << p.c + 1 << " " << p.d + 1 << " " << p.e + 1 << " " << p.f + 1 << '\n';
        }

    }




}