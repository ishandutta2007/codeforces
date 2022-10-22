/*
    keep calm and love rick and morty  :D
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e2 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct st {
    char c;
    char col = '2';
    ll f_ind;
};


st a[MAXN];

char p(char c) {
    if (c == '1') return '0';
    return '1';
}

int main() {
    fast_io;
    ll n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        a[i].c = s[i];
        a[i].f_ind = i;
    }

    ll f = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = f; i < n; i++) {
            if (a[i].c == c) {
                char x = '2';
                for (int j = i - 1; j >= f; j--) {
                    if (x != a[j].col) {
                        if (x != '2') kill("NO");
                        x = a[j].col;
                    }
                }


//                cout << f << sep << c << endl;
//
//                for (int i = 0; i < n; i++) cout << a[i].c; cout << endl;
//                for (int i = 0; i < n; i++) cout << a[i].col; cout << endl;

                if (x != '2' && a[i].col != '2' && x != p(a[i].col)) kill("NO");

                if (a[i].col == '2') a[i].col = p(x);
                for (int j = i - 1; j >= f; j--) {
                    a[j].col = p(a[j + 1].col);
                    swap(a[j + 1], a[j]);
                }

//                for (int i = 0; i < n; i++) cout << a[i].c; cout << endl;
//                for (int i = 0; i < n; i++) cout << a[i].col; cout << endl;
                f++;
            }
        }
    }

    cout << "YES" << endl;
    char* res = new char[n];
    for (int i = 0; i < n; i++) {
        res[a[i].f_ind] = a[i].col;
    }

    for (int i = 0; i < n; i++) cout << res[i];
    cout << endl;
    return 0;
}