/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

pair<vector<int>, int*> solve(int* s, int n) {
   vector<int> res;

    for (int i = 0; i < n; i++) {
        if (s[i] == 1) {
            for (int j = n - 1; j >= 0 && j > i; j--) {
                if (s[j] == 0) {
                    res.push_back(j + 1);
                    res.push_back(i + 1);
                    s[i] = -1;
                    s[j] = -1;
                    break;
                }
            }
        }
    }

    return make_pair(res, s);
}

std::string stringulate(int v)
{
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

int main() {
    string ss;
    cin >> ss;

    int n = ss.size();
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = ss[i] == '(';
    }

    int k = 0;
    vector<int> res;
    string s = "";
    while (true) {
        pair<vector<int>, int*> now = solve(a, n);
        if (now.first.size() < 1)
            break;
        k++;
        stringstream ss;
        s += stringulate(now.first.size());
        s += endl;
        sort(now.first.begin(), now.first.end());
        for (auto it = now.first.begin(); it != now.first.end(); it++) {
            s += stringulate(*it);
            s += ' ';
        }

        s += endl;
    }
    cout << k << endl;
    cout << s;
    return 0;
}