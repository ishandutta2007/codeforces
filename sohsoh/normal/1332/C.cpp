/*
    Soheil Mohammadkhani
    IDK :)
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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int al = 0; al < n; al++) cout << a[al] << " "; cout << endl;
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k;
int* a;

int per1(int i) {
    if (i + k < n)
        return i + k;
    return i;
}

int per2(int i) {
    if (i - k >= 0)
        return i - k;
    return i;
}

int* col;
int last_col = 0;
void chain(int ind) {
    if (col[ind] > 0) return;
    int i1 = n - ind - 1;
    int i2 = per1(ind);
    int i3 = per2(ind);

    col[ind] = last_col;
    chain(i1);
    chain(i2);
    chain(i3);

    col[i1] = last_col;
    col[i2] = last_col;
    col[i3] = last_col;
}

int max_count(vector<int> v) {
    sort(v.begin(), v.end());
    int prev = v.front();
    if (v.size() == 1)
        return 1;

    int m = 0;
    int c = 1;
    for (vector<int>::iterator i = v.begin() + 1; i != v.end(); i++) {
        int now = *i;
        if (now != prev) {
            m = max(c, m);
            c = 0;
        }

        c++;
        prev = now;
    }

    m = max(c, m);
    return m;
}

void solve() {
    last_col = 0;
    n = 0;
    k = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    a = new int[s.size()];
    col = new int[s.size()];
    for (int i = 0; i < n; i++) {
        a[i] = int(s[i]);
        col[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (col[i] == 0) {
            last_col++;
            chain(i);
        }

//        if (i == 0)
//            alog(col, n);
    }


    vector<int>* p = new vector<int>[last_col];
    for (int i = 0; i < n; i++) {
        p[col[i] - 1].push_back(a[i]);
    }

//    alog(col, n);

//    for (int i = 0; i < last_col; i++) {
//        alog(p[i], p[i].size())
//    }

    int sum = 0;
    for (int i = 0; i < last_col; i++) {
        sum += p[i].size() - max_count(p[i]);
    }

    cout << sum << endl;
}

int main() {
//    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}