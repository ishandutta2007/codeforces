#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)1e5 + 50, M = 11, B = (int)300;

int n, m, q;
string str[N];
pii to[N][M];

void rebuild(int b) {
    queue<pii> que;
    bool fir = true;
    for(int i = b * B + 1; i <= min((b + 1) * B, n); i++) {
        fill(to[i] + 1, to[i] + m + 1, pii{-1, -1});
        for(int j = 1; j <= m; j++) {
            if(str[i][j] != '^') continue;
            int l = j, r = j;
            while(l - 1 >= 1 && str[i][l - 1] == '>') l--;
            while(r + 1 <= m && str[i][r + 1] == '<') r++;
            rep(x, l, r + 1) to[i][x] = fir ? pii{i - 1, j} : to[i - 1][j];
        }
        int j = 0;
        while(j + 1 <= m && str[i][j + 1] == '<') j++;
        rep(x, 1, j + 1) to[i][x] = {i, 0};
        j = m + 1;
        while(j - 1 >= 1 && str[i][j - 1] == '>') j--;
        rep(x,  j, m + 1) to[i][x] = {i, m + 1};

        fir = false;
    }
}

bool end(int x, int y) {
    return x == -1 || x == 0 || y == 0 || y == m + 1;
}

void run(int x, int y) {
    while(!end(x, y)) tie(x, y) = to[x][y];
    cout << x << " " << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    cin >> n >> m >> q;
    rep(i, 1, n + 1) {
        cin >> str[i], str[i] = " " + str[i];
    }
    rep(b, 0, (n - 1) / B + 1) rebuild(b);
    while(q--) {
        char c;
        int x, y; cin >> c >> x >> y;
        if(c == 'A') {
            run(x, y);
        } else {
            char uc; cin >> uc;
            str[x][y] = uc;
            rebuild((x - 1) / B);
//            for(int i = 1; i <= n; i++) {
//                for(int j = 1; j <= m; j++) cout << to[i][j].first << ", " << to[i][j].second << " ";
//                cout << endl;
//            }
        }
    }



}