#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1005;

int n, m;
string str;
int a[N][N], b[N][N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        vector<vi> mat = {
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
        };
        cin >> n >> m;
        rep(i, 0, n) rep(j, 0, n) cin >> a[i][j], a[i][j]--;
        cin >> str;
        for(char c : str) {
            if(c == 'R') mat[1][0]++;
            else if(c == 'L') mat[1][0]--;
            else if(c == 'D') mat[0][0]++;
            else if(c == 'U') mat[0][0]--;
            else if(c == 'I') swap(mat[1], mat[2]);
            else swap(mat[0], mat[2]);
        }
        auto get = [&](int i, int j, int t) {
            return ((mat[t][0] + mat[t][1] * i + mat[t][2] * j + mat[t][3] * a[i][j]) % n + n) % n;
        };
        rep(i, 0, n) {
            rep(j, 0, n) b[get(i, j, 0)][get(i, j, 1)] = get(i, j, 2);
        }
        rep(i, 0, n) {
            rep(j, 0, n) cout << b[i][j] + 1 << " ";
            cout << '\n';

        }

    }


}