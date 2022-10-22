//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
using pci = pair<char, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 7;//998244353;
const int B = 350;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, li k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

/*
*/

int k;

int getk(li v) {
    int res = 0;
    for(int i = k; i >= 0; i--) {
        if(v & (1ll << i))
            break;
        res++;
    }
    return res;
//    int res = 0;
//    while(v > 1) {
//        res++;
//        v /= 2;
//    }
//
//    return k - res - 1;
}

int sum(const vector<int>& a) {
    int res = 0;
    for(int x : a)
        res = sum(res, x);
    return res;
}

vector<int> res[61];
map<li, int> col;
map<li, vector<int>> dp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    res[0] = vector<int>(6, 1);
    for(int i = 1; i <= 60; i++) {
        res[i].resize(6, pow2(4, (1ll << i) - 2));
    }


    cin >> k;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        li v;
        string s;
        cin >> v >> s;

        dp[v] = vector<int>(6, 0);


        int j = getk(v);

        int rs = (j == 0 ? 1 : res[j][0]);//mul(16, res[j - 1][0]));//mul(res[j - 1][0], res[j - 1][0])));
        if(s[0] == 'w')
            col[v] = 0;
        else if(s[0] == 'y')
            col[v] = 1;
        else if(s[0] == 'g')
            col[v] = 2;
        else if(s[0] == 'b')
            col[v] = 3;
        else if(s[0] == 'r')
            col[v] = 4;
        else
            col[v] = 5;

        dp[v][col[v]] = rs;
//        cout << v << ' ' << rs << endl;

//        if(s[0] == 'w')
//            dp[v][0] = 1;
//        else if(s[0] == 'o')
//            dp[v][1] = 1;
//        else if(s[0] == 'g')
//            dp[v][2] = 1;
//        else if(s[0] == 'b')
//            dp[v][3] = 1;
//        else if(s[0] == 'r')
//            dp[v][4] = 1;
//        else
//            dp[v][5] = 1;
    }
//
//    for(int i = 1; i <= 8; i++)
//        cout << "getk " << i << ' ' << getk(i) << endl;
//    for(int i = 0; i <= k; i++) {
//        cout << "res " << i << ' ' << res[i][0] << endl;
//    }

    while(true) {
        li v = dp.rbegin()->f;
        if(v == 1)
            break;

//        cout << v << endl;

        vector<int> a1 = dp[v];
        vector<int> a2 = (dp.count(v ^ 1) ? dp[v ^ 1] : res[getk(v)]);
//        for(int x : a1)
//            cout << x << ' ';
//        cout << endl;
//        for(int x : a2)
//            cout << x << ' ';
//        cout << endl;

        dp.erase(v);
        dp.erase(v ^ 1);

        li par = v / 2;

        dp[par].resize(6, 0);

        if(col.count(par)) {
            int cl = col[par];
            int rs = 0;
            for(int i = 0; i < 6; i++) if(i != cl && i != (cl ^ 1))
                for(int j = 0; j < 6; j++){
                    if(j != cl && j != (cl ^ 1)) {
                        rs = sum(rs, mul(a1[i], a2[j]));
                    }
                }
            dp[par][cl] = rs;
        } else {
            for(int cl = 0; cl < 6; cl++) {
                int rs = 0;
                for(int i = 0; i < 6; i++) if(i != cl && i != (cl ^ 1))
                    for(int j = 0; j < 6; j++){
                        if(j != cl && j != (cl ^ 1)) {
                            rs = sum(rs, mul(a1[i], a2[j]));
                        }
                    }
                dp[par][cl] = rs;
            }
        }
    }

    cout << sum(dp[1]) << endl;
}