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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int>* res;
bool* a;
int n, k;
int mv;

bool solve() {
    bool b = true;
    mv = 0;
    while (b) {
        b = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] && !a[i + 1]) {
                b = true;

                if (mv >= k) return 0;
                if (a[i]) res[mv].push_back(i);
                else res[mv].push_back(i + 1);

                swap(a[i], a[i + 1]);
                i++;
            }
        }

        if (!b) break;

        mv++;
        if (mv > k) return 0;
    }

    return 1;
}

int main() {
    cin >> n >> k;
    res = new vector<int>[k + 1];
    a = new bool[n];
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = (c == 'R');
    }

    if (!solve()) return cout << -1 << endl, 0;
    int e = k - mv;
    int sum = 0;
    for (int i = 0; i < mv; i++) {
        sum += res[i].size() - 1;
    }

    if (sum < e) return cout << -1 << endl, 0;

//    alog(res[0], res[0].size());

    for (int i = 0; i < mv; ) {
        if (res[i].size() <= 0) {
            i++;
            continue;
        }

        int print_now = res[i].size();
        if (e > 0 && res[i].size() > 1) {
            print_now = 1;
            e--;
        }

        cout << print_now << sep;
//        cout << "LOG "; alog(res[0], res[0].size());
        for (int j = 0; j < print_now; j++) {
            cout << *res[i].begin() + 1 << sep;
            res[i].erase(res[i].begin());
        }

        cout << endl;
    }

    return 0;
}