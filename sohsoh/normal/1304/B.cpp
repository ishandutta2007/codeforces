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

bool used[MAXN] = {false};

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    vector<int> self_pal;
    string* a = new string[n];
    string* reva = new string[n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        reva[i] = s2;
    }

//    alog(reva, n)
//    alog(a, n)

    vector<pair<int, int>> two_pal;
    for (int i = 0; i < n; i++) {
        if (a[i] == reva[i]) self_pal.push_back(i);
        for (int j = i + 1; j < n; j++) {
            if (i != j && reva[j] == a[i]) {
                two_pal.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> res_front;
    vector<int> res_end;


    for (auto i = two_pal.begin(); i != two_pal.end(); i++) {
        pair<int, int> tmp = *i;
        res_front.push_back(tmp.first);
        res_end.insert(res_end.begin(), tmp.second);

        used[tmp.first] = true;
        used[tmp.second] = true;
    }

    for (int i = 0; i < self_pal.size(); i++) {
        if (used[self_pal[i]] == false) {
            res_front.push_back(self_pal[i]);
            break;
        }
    }

    cout << res_end.size() * m + res_front.size() * m << endl;
    for (int i : res_front) {
        cout << a[i];
    }

    for (int i : res_end) {
        cout << a[i];
    }

    cout << endl;
    return 0;
}